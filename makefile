CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -Weffc++ -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral -Werror
INCLUDE_SFML = -I/usr/local/include
LIB_SFML = -L/usr/local/lib -lsfml-window -lsfml-system -lsfml-graphics
PROJECT = SFML-Father
all:
	make run

run: $(PROJECT)
	./$(PROJECT) $(PROJECT)

$(PROJECT): main.o Info.o RingMenu.o Input.o DialogueBox.o ScreenManager.o RingMenuItem.o TextureManager.o
	g++ $(CFLAGS) main.o Info.o RingMenu.o Input.o DialogueBox.o ScreenManager.o RingMenuItem.o TextureManager.o -o $(PROJECT) $(LIB_SFML)

main.o: main.cpp FatherDrawable.hpp
	g++ $(CFLAGS) -c main.cpp $(INCLUDE_SFML)

Info.o: Info/Info.cpp Info/Info.hpp 
	g++ $(CFLAGS) -c Info/Info.cpp $(INCLUDE_SFML)

RingMenu.o: RingMenu/RingMenu.cpp RingMenu/RingMenu.hpp
	g++ $(CFLAGS) -c RingMenu/RingMenu.cpp $(INCLUDE_SFML)

RingMenuItem.o: RingMenu/RingMenuItem.cpp RingMenu/RingMenuItem.hpp
	g++ $(CFLAGS) -c RingMenu/RingMenuItem.cpp $(INCLUDE_SFML)

Input.o: Input/Input.cpp Input/Input.hpp Input/InputStruct.hpp Input/InputListener.hpp
	g++ $(CFLAGS) -c Input/Input.cpp $(INCLUDE_SFML)

DialogueBox.o: DialogueBox/DialogueBox.cpp DialogueBox/DialogueBox.hpp
	g++ $(CFLAGS) -c DialogueBox/DialogueBox.cpp $(INCLUDE_SFML)

ScreenManager.o: ScreenManager/ScreenManager.cpp ScreenManager/ScreenManager.hpp
	g++ $(CFLAGS) -c ScreenManager/ScreenManager.cpp $(INCLUDE_SFML)

TextureManager.o: TextureManager/TextureManager.cpp TextureManager/TextureManager.hpp
	g++ $(CFLAGS) -c TextureManager/TextureManager.cpp $(INCLUDE_SFML)

clean:
	rm *.o
	rm $(PROJECT)

recompile:
	make clean
	make $(PROJECT)

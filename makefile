CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -Weffc++ -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral -Werror
PROJECT = SFML-Father
all:
	make run

run: $(PROJECT)
	./$(PROJECT) $(PROJECT)

$(PROJECT): main.o Info.o RingMenu.o Input.o DialogueBox.o ScreenManager.o RingMenuItem.o TextureManager.o Alarm.o AlarmManager.o
	g++ $(CFLAGS) main.o Info.o RingMenu.o Input.o DialogueBox.o ScreenManager.o RingMenuItem.o TextureManager.o Alarm.o AlarmManager.o -o $(PROJECT) -lsfml-window -lsfml-system -lsfml-graphics

main.o: main.cpp FatherDrawable.hpp
	g++ $(CFLAGS) -c main.cpp

Info.o: Info/Info.cpp Info/Info.hpp 
	g++ $(CFLAGS) -c Info/Info.cpp

RingMenu.o: RingMenu/RingMenu.cpp RingMenu/RingMenu.hpp
	g++ $(CFLAGS) -c RingMenu/RingMenu.cpp

RingMenuItem.o: RingMenu/RingMenuItem.cpp RingMenu/RingMenuItem.hpp
	g++ $(CFLAGS) -c RingMenu/RingMenuItem.cpp

Input.o: Input/Input.cpp Input/Input.hpp Input/InputStruct.hpp Input/InputListener.hpp
	g++ $(CFLAGS) -c Input/Input.cpp

DialogueBox.o: DialogueBox/DialogueBox.cpp DialogueBox/DialogueBox.hpp
	g++ $(CFLAGS) -c DialogueBox/DialogueBox.cpp

ScreenManager.o: ScreenManager/ScreenManager.cpp ScreenManager/ScreenManager.hpp
	g++ $(CFLAGS) -c ScreenManager/ScreenManager.cpp

TextureManager.o: TextureManager/TextureManager.cpp TextureManager/TextureManager.hpp
	g++ $(CFLAGS) -c TextureManager/TextureManager.cpp

Alarm.o: Alarm/Alarm.cpp Alarm/Alarm.hpp Alarm/AlarmListener.hpp
	g++ $(CFLAGS) -c Alarm/Alarm.cpp

AlarmManager.o: Alarm/AlarmManager.cpp Alarm/AlarmManager.hpp Alarm/AlarmListener.hpp
	g++ $(CFLAGS) -c Alarm/AlarmManager.cpp

clean:
	rm *.o
	rm $(PROJECT)

recompile:
	make clean
	make $(PROJECT)

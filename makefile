CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -Weffc++ -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral -Werror
PROJECT = SFML-Father
all:
	make run

run: $(PROJECT)
	./$(PROJECT) $(PROJECT)

$(PROJECT): main.o Info.o RingMenu.o Input.o
	g++ $(CFLAGS) main.o Info.o RingMenu.o Input.o -o $(PROJECT) -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp InputListener.hpp
	g++ $(CFLAGS) -c main.cpp

Info.o: Info.cpp Info.hpp 
	g++ $(CFLAGS) -c Info.cpp

RingMenu.o: RingMenu.cpp RingMenu.hpp
	g++ $(CFLAGS) -c RingMenu.cpp

Input.o: Input.cpp Input.hpp InputStruct.hpp
	g++ $(CFLAGS) -c Input.cpp

clean:
	rm *.o
	rm $(PROJECT)

recompile:
	make clean
	make $(PROJECT)

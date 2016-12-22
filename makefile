CFLAGS = -std=c++14 -Wall -Winit-self -Wextra -Weffc++ -pedantic -Wredundant-decls -Wcast-align -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Winvalid-pch -flto -Wodr -Wformat=2 -Wmissing-format-attribute -Wformat-nonliteral -Werror
PROJECT = SFML-Father
all:
	make run

run: $(PROJECT)
	./$(PROJECT) $(PROJECT)

$(PROJECT): main.o
	g++ $(CFLAGS) main.o -o $(PROJECT) -lsfml-graphics -lsfml-window -lsfml-system

main.o: main.cpp
	g++ $(CFLAGS) -c main.cpp

clean:
	rm *.o
	rm $(PROJECT)

recompile:
	make clean
	make $(PROJECT)

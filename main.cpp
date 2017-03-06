// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Input.hpp"
#include "RingMenu.hpp"
RingMenu *RingMenu::s_instance = 0;
int main(int argc, char const *argv[]) {
    std::cout << "Arguments: " << argc;
    for (int i = 0; i < argc; i++) {
        std::cout << std::endl << "arg "<< i << ": " << argv[i] << std::endl;
    }
    sf::RenderWindow window(sf::VideoMode(1920, 1080), argv[1]);
    window.setFramerateLimit(60);

    Input input = Input();
    //RingMenu ring = RingMenu();
    RingMenu *s_ring = RingMenu::instance();
    std::cout << s_ring << std::endl;
    input.listeners.push_back(s_ring);

    while (window.isOpen()) {
        input.clearInput();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                } else {
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
                        if (input.inputStruct.left == false) {
                            input.inputStruct.leftPressed = true;
                        }
                        input.inputStruct.left = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        if (input.inputStruct.right == false) {
                            input.inputStruct.rightPressed = true;
                        }
                        input.inputStruct.right = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        if (input.inputStruct.up == false) {
                            input.inputStruct.upPressed = true;
                        }
                        input.inputStruct.up = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        if (input.inputStruct.down == false) {
                            input.inputStruct.downPressed = true;
                        }
                        input.inputStruct.down = true;
                    }
                }
            } else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Left
                    || event.key.code == sf::Keyboard::A) {
                    if (input.inputStruct.left == true) {
                        input.inputStruct.leftReleased = true;
                    }
                    input.inputStruct.left = false;
                }
                if (event.key.code == sf::Keyboard::Right
                    || event.key.code == sf::Keyboard::D) {
                    if (input.inputStruct.right == true) {
                        input.inputStruct.rightReleased = true;
                    }
                    input.inputStruct.right = false;
                }
                if (event.key.code == sf::Keyboard::Up
                    || event.key.code == sf::Keyboard::W) {
                    if (input.inputStruct.up == true) {
                        input.inputStruct.upReleased = true;
                    }
                    input.inputStruct.up = false;
                }
                if (event.key.code == sf::Keyboard::Down
                    || event.key.code == sf::Keyboard::S) {
                    if (input.inputStruct.down == true) {
                        input.inputStruct.downReleased = true;
                    }
                    input.inputStruct.down = false;
                }
            }
        }
        input.logForInput();
        window.clear();
        window.draw(*s_ring);
        window.display();
    }

    return EXIT_SUCCESS;
}
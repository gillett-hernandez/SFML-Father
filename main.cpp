// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Input.hpp"

const bool debug = true;

using namespace std;

int main(int argc, char const *argv[]) {
    std::cout << "Arguments: " << argc;
    for (int i = 0; i < argc; i++) {
        std::cout << std::endl << "arg "<< i << ": " << argv[i] << std::endl;
    }
    sf::RenderWindow window(sf::VideoMode(640, 480), argv[1]);
    window.setFramerateLimit(60);

    InputStruct input;

    while (window.isOpen()) {
        clearInput(input);

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
                        if (input.left == false) {
                            input.leftPressed = true;
                        }
                        input.left = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
                        if (input.right == false) {
                            input.rightPressed = true;
                        }
                        input.right = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
                        if (input.up == false) {
                            input.upPressed = true;
                        }
                        input.up = true;
                    }
                    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)
                        || sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
                        if (input.down == false) {
                            input.downPressed = true;
                        }
                        input.down = true;
                    }
                }
            } else if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Left
                    || event.key.code == sf::Keyboard::A) {
                    if (input.left == true) {
                        input.leftReleased = true;
                    }
                    input.left = false;
                }
                if (event.key.code == sf::Keyboard::Right
                    || event.key.code == sf::Keyboard::D) {
                    if (input.right == true) {
                        input.rightReleased = true;
                    }
                    input.right = false;
                }
                if (event.key.code == sf::Keyboard::Up
                    || event.key.code == sf::Keyboard::W) {
                    if (input.up == true) {
                        input.upReleased = true;
                    }
                    input.up = false;
                }
                if (event.key.code == sf::Keyboard::Down
                    || event.key.code == sf::Keyboard::S) {
                    if (input.down == true) {
                        input.downReleased = true;
                    }
                    input.down = false;
                }
            }
        }
        if (debug) {
            logForInput(input);
        }
        window.clear();
        window.display();
    }

    return EXIT_SUCCESS;
}

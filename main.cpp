// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Input.hpp"
#include "RingMenu.hpp"

const bool debug = false;

void logArgs(int argc, char const *argv[]);

int main(int argc, char const *argv[]) {
    if (debug) {
        logArgs(argc, argv);
    }
    sf::RenderWindow window(sf::VideoMode(1920, 1080), argv[1]);
    window.setFramerateLimit(60);

    Input *input = Input::instance();
    RingMenu *ring = RingMenu::instance();

    input->addListener(ring);

    while (window.isOpen()) {
        input->clearInput();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            } else if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            input->processEvent(event);
        }
        input->informListeners();
        window.clear();
        window.draw(*ring);
        window.display();
    }

    return EXIT_SUCCESS;
}

void logArgs(int argc, char const *argv[]) {
    std::cout << "Arguments: " << argc;
    for (int i = 0; i < argc; i++) {
        std::cout << std::endl << "arg "<< i << ": " << argv[i];
    }
    std::cout << std::endl;
}
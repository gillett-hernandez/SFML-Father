// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ScreenManager/ScreenManager.hpp"
#include "Input/Input.hpp"
#include "RingMenu/RingMenu.hpp"
#include "DialogueBox/DialogueBox.hpp"

const bool debug = false;

void logArgs(int argc, char const *argv[]);

int main(int argc, char const *argv[]) {
    if (debug) {
        logArgs(argc, argv);
    }
    sf::RenderWindow window(sf::VideoMode(ScreenWidth, ScreenHeight), argv[1]);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    Input *input = Input::instance();
    RingMenu *ring = RingMenu::instance();
    DialogueBox *dialogueBox = DialogueBox::instance();
    std::vector<FatherDrawable *> drawables;
    drawables.push_back(ring);
    drawables.push_back(dialogueBox);

    input->addListener(ring);
    input->addListener(dialogueBox);
    dialogueBox->setString("A morphable polygon has appeared\n"
        "It asks your name...?\n"
        "and it asks again..\n"
        "and again...\n"
        "and again...\n"
        "and again..\n"
        "test banana monkey money hella\n"
        " cash \n"
        " CA$H!!!!\n"
        "no no no no yes no\n"
        " cant stop wont stop ding dong.\n"
        "witch is dead.\n"
        " which will you choose, how long will it take\n"
        "go eat an apple or a banana stop asking me questions\n"
        "hello my name is a robots bot row.");
    while (window.isOpen()) {
        input->clearInput();
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
            input->processEvent(event);
        }
        input->informListeners();
        window.clear(sf::Color(0x20,0x00,0x20));
        for (FatherDrawable *drawable : drawables) {
            drawable->drawToWindow(window);
        }
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
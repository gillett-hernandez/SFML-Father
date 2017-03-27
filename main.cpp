// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ScreenManager/ScreenManager.hpp"
#include "Input/Input.hpp"
#include "RingMenu/RingMenu.hpp"
#include "DialogueBox/DialogueBox.hpp"
#include "TextureManager/TextureManager.hpp"

const bool debug = false;

void logArgs(int argc, char const *argv[]);

int main(int argc, char const *argv[]) {
    if (debug) {
        logArgs(argc, argv);
    }
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), argv[1], sf::Style::Fullscreen|sf::Style::Resize);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    TextureManager *textureManager = TextureManager::instance();
    std::cout << &textureManager;
    textureManager->loadTexture(kRingMenuItemTexture, kRingMenuItemTextureFilePath);

    Input *input = Input::instance();
    
    DialogueBox *dialogueBox = DialogueBox::instance();
    sf::Texture texture;
    RingMenu *ring = RingMenu::instance();
    
    std::vector<FatherDrawable *> drawables;
    drawables.push_back(ring);
    drawables.push_back(dialogueBox);

    input->addListener(ring);
    input->addListener(dialogueBox);
    dialogueBox->show(
        "one\n"
        "two two\n"
        "three three three\n"
        "four four four four\n"
        "five five five five five\n"
        "six six six six six six\n"
        "seven seven seven seven seven seven seven\n"
        "eight eight eight eight eight eight eight eight\n"
        "nine nine nine nine nine nine nine nine nine\n"
        "ten ten ten ten ten ten ten ten ten ten\n"
        "eleven eleven eleven eleven eleven eleven eleven eleven eleven eleven eleven\n"
        "twelve twelve twelve twelve twelve twelve twelve twelve twelve twelve twelve twelve\n"
        "thirteen thirteen thirteen thirteen thirteen thirteen thirteen thirteen thirteen thirteen thirteen thirteen thirteen\n"
        "fourteen fourteen fourteen fourteen fourteen fourteen fourteen fourteen fourteen fourteen fourteen fourteen fourteen fourteen\n"
        "fifteen fifteen fifteen fifteen fifteen fifteen fifteen fifteen fifteen fifteen fifteen fifteen fifteen fifteen fifteen \n"
        "1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 90 91 92 93 94 95 96 97 98 99 100"
        );
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
// main.cpp
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "ScreenManager/ScreenManager.hpp"
#include "Input/Input.hpp"
#include "RingMenu/RingMenu.hpp"
#include "DialogueBox/DialogueBox.hpp"
#include "TextureManager/TextureManager.hpp"
#include "Alarm/AlarmManager.hpp"

const bool debug = false;
const bool showFPS = true;

void logArgs(int argc, char const *argv[]);
void setupFPSText(sf::Text &text, sf::Font &font);
void setFPSTextUsingClock(sf::Text &text, sf::Clock &clock);

int main(int argc, char const *argv[]) {
    if (debug) {
        logArgs(argc, argv);
    }
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), argv[1], sf::Style::Fullscreen|sf::Style::Resize);
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);

    TextureManager *textureManager = TextureManager::instance();
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
        "Press ESC to exit SFML father \n\n"
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, "
        "sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. "
        "Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. "
        "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. "
        "Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum."
        );


    sf::Text fpsText;
    sf::Font fpsFont;

    if (showFPS) {
        setupFPSText(fpsText, fpsFont);
    }

    sf::Clock fpsClock;
    std::string fpsString;

    AlarmManager *alarmManager = AlarmManager::instance();

    while (window.isOpen()) {
        if (alarmManager->alarmsCount() > 0) {
            alarmManager->incrementFrame();
        }
        if (showFPS) {
            setFPSTextUsingClock(fpsText, fpsClock);
        }

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
        window.clear(sf::Color(0x28,0x00,0x28));
        for (FatherDrawable *drawable : drawables) {
            drawable->drawToWindow(window);
        }
        if (showFPS) {
            window.draw(fpsText);
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

void setupFPSText(sf::Text &text, sf::Font &font) {
    text.setOutlineColor(sf::Color(sf::Color::White));
    text.setFillColor(sf::Color(sf::Color::White));
    text.setPosition(2,2);
    text.setCharacterSize(14);
    text.setStyle(sf::Text::Regular);
    font.loadFromFile("Fonts/FUTRFW.TTF");
    text.setFont(font);
    text.setString("hi");
}

void setFPSTextUsingClock(sf::Text &text, sf::Clock &clock) {
    std::string fpsString;
    fpsString = "";
    fpsString.append("fps: ");
    fpsString.append(std::to_string(1.f / clock.restart().asSeconds()));
    text.setString(fpsString);
}
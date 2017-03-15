#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include <vector>
#include <SFML/Window.hpp>
#include "InputStruct.hpp"
#include "InputListener.hpp"

class Input
{
private:
    Input();
    static Input *s_instance;
    std::vector<InputListener *> listeners;
public:
    static Input *instance() {
        if (!s_instance) {
            s_instance = new Input;
        }
        return s_instance;
    }
    ~Input();
    InputStruct inputStruct;
    void addListener(InputListener *listener);
    void removeListener(InputListener *listener);
    void clearInput();
    void informListeners();
    
    void upPressed();
    void downPressed();
    void leftPressed();
    void rightPressed();

    void upReleased();
    void downReleased();
    void leftReleased();
    void rightReleased();
    
    void up();
    void down();
    void left();
    void right();

    void enterPressed();

    void processEvent(sf::Event &event);
};

#endif
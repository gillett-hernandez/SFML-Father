#ifndef INPUT_H
#define INPUT_H
#include <iostream>
#include "InputStruct.hpp"
#include "InputListener.hpp"
#include <vector>

class Input
{
public:
    Input();
    ~Input();
    InputStruct inputStruct;
    std::vector<InputListener *> listeners;
    void clearInput();
    void logForInput();
    
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
};

#endif
#ifndef SCREENMANAGER_H
#define SCREENMANAGER_H
#include <SFML/Window.hpp>
//extern const int ScreenWidth;
//extern const int ScreenHeight;

class ScreenManager
{
private:
    static ScreenManager *s_instance;
    ScreenManager();
public:
    ~ScreenManager();
    static ScreenManager *instance() {
        if (!s_instance) {
            s_instance = new ScreenManager;
        }
        return s_instance;
    }
    static int screenWidth() {
        return sf::VideoMode::getDesktopMode().width;
    }
    static int screenHeight() {
        return sf::VideoMode::getDesktopMode().height;
    }
};
#endif
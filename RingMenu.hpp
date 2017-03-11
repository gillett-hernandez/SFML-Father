#ifndef RINGMENU_H
#define RINGMENU_H
#include <SFML/Graphics.hpp>
#include "Info.hpp"
#include "Input.hpp"

class RingMenu: public sf::CircleShape, public Info, public InputListener {
private:
    RingMenu();
    static RingMenu *s_instance;
public:
    static RingMenu *instance() {
        if (!s_instance) {
            s_instance = new RingMenu;
        }
        return s_instance;
    }
    ~RingMenu();
    void hide();
    void show();
    void upPressed() override;
    void downPressed() override;
    void leftPressed() override;
    void rightPressed() override;

    void upReleased() override;
    void downReleased() override;
    void leftReleased() override;
    void rightReleased() override;
    
    void up() override;
    void down() override;
    void left() override;
    void right() override;
};

#endif
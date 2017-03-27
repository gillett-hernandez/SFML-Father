#ifndef RINGMENU_H
#define RINGMENU_H
#include <SFML/Graphics.hpp>
#include "RingMenuItem.hpp"
#include "../Info/Info.hpp"
#include "../Input/Input.hpp"
#include "../FatherDrawable.hpp"
#include "../ScreenManager/ScreenManager.hpp"

class RingMenu: public sf::CircleShape, public Info, public InputListener, public FatherDrawable {
private:
    RingMenu();
    static RingMenu *s_instance;
    bool hidden;
    std::vector<RingMenuItem> items;
    float rad;
public:
    static RingMenu *instance() {
        if (!s_instance) {
            s_instance = new RingMenu;
        }
        return s_instance;
    }
    ~RingMenu();
    void toggleHidden();
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
    void enterPressed() override;
    void drawToWindow(sf::RenderWindow &windowRef) override;
};

#endif
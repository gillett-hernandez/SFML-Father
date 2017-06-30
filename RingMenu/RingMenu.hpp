#ifndef RINGMENU_H
#define RINGMENU_H
#include <SFML/Graphics.hpp>
#include "RingMenuItem.hpp"
#include "../Info/Info.hpp"
#include "../Input/Input.hpp"
#include "../FatherDrawable.hpp"
#include "../ScreenManager/ScreenManager.hpp"
#include "../Alarm/Alarm.hpp"
#include "../Alarm/AlarmManager.hpp"
#include "../Alarm/AlarmListener.hpp"

extern const double pi;
extern const double rad_max;

class RingMenuItem;

class RingMenu: public sf::CircleShape, public Info, public InputListener, public FatherDrawable, public AlarmListener {
private:
    RingMenu();
    static RingMenu *s_instance;
    std::vector<RingMenuItem> items;
    float rad;
    void placeItems();
    sf::RectangleShape overlay;
    sf::Text menuText;
    sf::RectangleShape textBackground;
    sf::Font menuFont;
    Alarm fadeOutAlarm;
    Alarm fadeInAlarm;
    bool hidden;
    void fadeIn();
    void fadeOut();
public:
    bool isHidden() {
        return this->hidden;
    }
    static RingMenu *instance() {
        if (!s_instance) {
            s_instance = new RingMenu;
        }
        return s_instance;
    }
    ~RingMenu();
    void toggleHidden();
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

    void frameTick(Alarm *alarm, sf::Uint8 currentFrame, sf::Uint8 frames) override;
};

#endif
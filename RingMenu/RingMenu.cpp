#include "RingMenu.hpp"
#include <cmath>
#include "../Lerp/Lerp.hpp"

RingMenu *RingMenu::s_instance = nullptr;

const sf::Color ringColor = sf::Color(0x00,0xFF,0xFF,0x80);
const sf::Color clearColor = sf::Color::Transparent;
const sf::Color overlayColor = sf::Color(0x00, 0x00, 0x00, 0x40);
const sf::Color textBackgroundColor = sf::Color(0xFF,0x00,0x00,0x80);

const double pi = 3.141592653589793;
const double rad_max = pi * 2.0f;
const std::string kFadeInAlarmTitle = "fadeIn";
const std::string kFadeOutAlarmTitle = "fadeOut";

static const bool debug = false;

RingMenu::RingMenu() {
    float radius = ScreenManager::screenHeight()/8;
    if (debug) {
        std::cout << "radius: " << radius << std::endl;
    }
    rad = 0.0f;
    this->setInfo(std::string("This is a Ring Menu"));

    int screenWidth = ScreenManager::screenWidth();
    int screenHeight = ScreenManager::screenHeight();
    this->setPosition(screenWidth/2,screenHeight/2);
    
    this->menuFont.loadFromFile("Fonts/FUTRFW.TTF");
    this->menuText.setFont(this->menuFont);
    this->menuText.setCharacterSize(20);
    this->menuText.setStyle(sf::Text::Regular);
    this->menuText.setFillColor(sf::Color::White);
    this->menuText.setString("Select Item...");
    this->menuText.setPosition(screenWidth/2 - this->menuText.getLocalBounds().width/2,screenHeight/2);

    this->textBackground.setFillColor(textBackgroundColor);

    sf::FloatRect textBounds = this->menuText.getGlobalBounds();
    
    this->textBackground.setSize(sf::Vector2f(textBounds.width+20.0f, textBounds.height+20.0f));
    this->textBackground.setPosition(sf::Vector2f(textBounds.left-10.0f, textBounds.top-10.0f));


    this->setRadius(radius);
    this->move(-screenHeight/8,-screenHeight/8);

    this->setPointCount(32);
    this->setOutlineColor(sf::Color(ringColor));
    this->setFillColor(clearColor);
    this->setOutlineThickness(1);
    
    RingMenuItem weapon = RingMenuItem(this, RingMenuItemTypeWeapon);
    RingMenuItem armor = RingMenuItem(this, RingMenuItemTypeArmor);
    RingMenuItem shield = RingMenuItem(this, RingMenuItemTypeShield);
    RingMenuItem item = RingMenuItem(this, RingMenuItemTypeItem);
    RingMenuItem spear1 = RingMenuItem(this, RingMenuItemTypeSpear1);
    RingMenuItem spear2 = RingMenuItem(this, RingMenuItemTypeSpear2);
    RingMenuItem spear3 = RingMenuItem(this, RingMenuItemTypeSpear3);

    this->items.push_back(weapon);
    this->items.push_back(armor);
    this->items.push_back(shield);
    this->items.push_back(item);
    this->items.push_back(spear1);
    this->items.push_back(spear2);
    this->items.push_back(spear3);

    this->placeItems();
    this->overlay.setSize(sf::Vector2f(screenWidth, screenHeight));
    this->overlay.setFillColor(sf::Color(overlayColor));
}

void RingMenu::placeItems() {
    float radius = this->getRadius();
    sf::Vector2f position = this->getPosition();
    size_t itemsLength = this->items.size();
    for (size_t i = 0; i < this->items.size(); i++) {
        sf::Vector2f pos;
        pos.x = position.x + (radius) * cos(rad + ((rad_max / itemsLength) * i));
        pos.y = position.y + (radius) * sin(rad + ((rad_max / itemsLength) * i));
        float itemWidthHalf = this->items[i].width() / 2;
        sf::Vector2f offset = sf::Vector2f(radius - (itemWidthHalf), radius - (itemWidthHalf));
        this->items[i].setPosition(pos + offset);
    }
}

RingMenu::~RingMenu() {

}

void RingMenu::upPressed() {
    if (debug) {
        std::cout << "RingMenu::upPressed" << std::endl;
    }
}
void RingMenu::downPressed() {
    if (debug) {
        std::cout << "RingMenu::downPressed" << std::endl;
    }
}
void RingMenu::leftPressed() {
    if (debug) {
        std::cout << "RingMenu::leftPressed" << std::endl;
    }
}
void RingMenu::rightPressed() {
    if (debug) {
        std::cout << "RingMenu::rightPressed" << std::endl;
    }
}

void RingMenu::upReleased() {
    if (debug) {
        std::cout << "RingMenu::upReleased" << std::endl;
    }
}
void RingMenu::downReleased() {
    if (debug) {
        std::cout << "RingMenu::downReleased" << std::endl;
    }
}
void RingMenu::leftReleased() {
    if (debug) {
        std::cout << "RingMenu::leftReleased" << std::endl;
    }
}
void RingMenu::rightReleased() {
    if (debug) {
        std::cout << "RingMenu::rightReleased" << std::endl;
    }
}

void RingMenu::up() {
    if (debug) {
        std::cout << "RingMenu::up" << std::endl;
    }
}
void RingMenu::down() {
    if (debug) {
        std::cout << "RingMenu::down" << std::endl;
    }
}
void RingMenu::left() {
    if (debug) {
        std::cout << "RingMenu::left" << std::endl;
    }

    rad -= 0.05f;

    this->placeItems();
       
}
void RingMenu::right() {
    if (debug) {
        std::cout << "RingMenu::right" << std::endl;
    }

    rad += 0.05f;

    this->placeItems();
}

void RingMenu::enterPressed() {
    if (debug) {
        std::cout << "RingMenu::enterPressed" << std::endl;
    }
    this->toggleHidden();

}

void RingMenu::drawToWindow(sf::RenderWindow &windowRef) {
    if (true) {
        windowRef.draw(this->overlay);
        windowRef.draw(this->textBackground);
        windowRef.draw(this->menuText);
        windowRef.draw(*this);
        for (RingMenuItem item: this->items) {
            item.drawToWindow(windowRef);
        }
    }
}

void RingMenu::toggleHidden() {
    if (this->hidden) {
        this->fadeIn();
    } else {
        this->fadeOut();
    }
    this->hidden = !this->hidden;
}

void RingMenu::fadeIn() {
    this->fadeInAlarm.configure(kFadeInAlarmTitle, 20, this);
    this->fadeInAlarm.addToManager(AlarmManager::instance());
}

void RingMenu::fadeOut() {
    this->fadeOutAlarm.configure(kFadeOutAlarmTitle, 20, this);
    this->fadeOutAlarm.addToManager(AlarmManager::instance());

};

sf::Uint8 sfUint8Lerp(sf::Uint8 a, sf::Uint8 b, sf::Uint8 top, sf::Uint8 bottom) {
    // lerp stands for Linear intERPolation
    // this function returns the point that is exactly `top/bottom` of the way from `a` to `b`
    return (a * bottom + (b - a) * top) / bottom;
}

void RingMenu::frameTick(Alarm *alarm, sf::Uint8 currentFrame, sf::Uint8 frames) {
    if (debug) std::cout << "frame tick" << std::endl;

    if (alarm == &this->fadeOutAlarm) {

        sf::Color newRingColor = ringColor;
        sf::Color newTextBackgroundColor = textBackgroundColor;
        sf::Color newTextColor = sf::Color::White;

        newRingColor.a = Lerp::sfUint8Lerp(ringColor.a, 0 , currentFrame, frames);
        newTextBackgroundColor.a = Lerp::sfUint8Lerp(textBackgroundColor.a, 0, currentFrame, frames);
        newTextColor.a = Lerp::sfUint8Lerp(sf::Color::White.a, 0, currentFrame, frames);

        this->setOutlineColor(newRingColor);
        this->textBackground.setFillColor(newTextBackgroundColor);
        this->menuText.setFillColor(newTextColor);
        for (RingMenuItem &item: this->items) {
            item.setColor(newTextColor);
        }
        if (currentFrame == frames) {
            this->rad = 0.0f;
            this->placeItems();
        }
    } else if (alarm == &this->fadeInAlarm) {
        sf::Color newRingColor = ringColor;
        sf::Color newTextBackgroundColor = textBackgroundColor;
        sf::Color newTextColor = sf::Color::White;

        newRingColor.a = Lerp::sfUint8Lerp(0, ringColor.a, currentFrame, frames);
        newTextBackgroundColor.a = Lerp::sfUint8Lerp(0, textBackgroundColor.a, currentFrame, frames);
        newTextColor.a = Lerp::sfUint8Lerp(0, sf::Color::White.a, currentFrame, frames);

        this->setOutlineColor(newRingColor);
        this->textBackground.setFillColor(newTextBackgroundColor);
        this->menuText.setFillColor(newTextColor);
        for (RingMenuItem &item: this->items) {
            item.setColor(newTextColor);
        }
    }
}
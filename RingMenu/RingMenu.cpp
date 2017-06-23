#include "RingMenu.hpp"
#include <cmath>
#include "../TextureManager/TextureManager.hpp"

RingMenu *RingMenu::s_instance = nullptr;
//sf::RectangleShape *RingMenu::overlayRect = nullptr;

//const sf::Color ringColor = sf::Color(0xFF,0xFF,0xFF,0xFF);
const sf::Color ringColor = sf::Color(0x20,0xFF,0xFF,0x80);
const sf::Color clearColor = sf::Color(0x00,0x00,0x00,0x00);

const double pi = 3.141592653589793;
const double rad_max = pi * 2.0f;

static const bool debug = true; 

RingMenu::RingMenu() {
    float radius = ScreenManager::screenHeight()/8;
    std::cout << "radius: " << radius << std::endl;
    rad = 0.0f;
    this->setInfo(std::string("This is a Ring Menu"));

    int screenWidth = ScreenManager::screenWidth();
    int screenHeight = ScreenManager::screenHeight();
    
    this->setPosition(screenWidth/2,screenHeight/2);
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

void RingMenu::show() {
    this->setOutlineColor(ringColor);
    this->setFillColor(clearColor);
}

void RingMenu::hide() {
    this->setOutlineColor(clearColor);
    this->setFillColor(clearColor);

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
    windowRef.draw(*this);
    for (RingMenuItem item: this->items) {
        item.drawToWindow(windowRef);
    }
}

void RingMenu::toggleHidden() {
    this->hidden = !this->hidden;
    if (this->hidden) {
        this->hide();
    } else {
        this->show();
    }
}
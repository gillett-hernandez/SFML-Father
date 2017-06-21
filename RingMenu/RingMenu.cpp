#include "RingMenu.hpp"
#include <cmath>
#include "../TextureManager/TextureManager.hpp"

RingMenu *RingMenu::s_instance = nullptr;

const sf::Color ringColor = sf::Color(0xFF,0xFF,0xFF,0xFF);
const sf::Color clearColor = sf::Color(0x00,0x00,0x00,0x00);

const double pi = 3.141592653589793;
const double rad_max = pi * 2.0f;

static const bool debug = false; 

RingMenu::RingMenu() {
    float radius = ScreenManager::screenHeight()/8;
    rad = 0.0f;
    this->setInfo(std::string("This is a Ring Menu"));

    //this->setOrigin(radius/2, radius/2);
    int screenWidth = ScreenManager::screenWidth();
    int screenHeight = ScreenManager::screenHeight();
    
    this->setPosition(screenWidth/2,screenHeight/2);
    this->setRadius(radius);
    this->move(-screenHeight/8,-screenHeight/8);

    this->setPointCount(3);
    this->setOutlineColor(sf::Color(ringColor));
    this->setFillColor(clearColor);
    this->setOutlineThickness(1);
    //this->hidden = true;
    RingMenuItem item = RingMenuItem(this, RingMenuItemTypeWeapon);
    RingMenuItem armor = RingMenuItem(this, RingMenuItemTypeArmor);
    RingMenuItem shield = RingMenuItem(this, RingMenuItemTypeItem);
    this->items.push_back(item);
    this->items.push_back(armor);
    this->items.push_back(shield);
}

RingMenu::~RingMenu() {

}

void RingMenu::hide() {
    this->setOutlineColor(ringColor);
    this->setFillColor(clearColor);

}

void RingMenu::show() {
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

    for (size_t i = 0; i < this->items.size(); i++) {
        sf::Vector2f pos;
        pos.x = this->getPosition().x + (this->getRadius()) * cos(rad + ((rad_max / this->items.size()) * i));
        pos.y = this->getPosition().y + (this->getRadius()) * sin(rad + ((rad_max / this->items.size()) * i));
        this->items[i].setPosition(pos);
    }
       
}
void RingMenu::right() {
    if (debug) {
        std::cout << "RingMenu::right" << std::endl;
    }

    rad += 0.05f;

    for (size_t i = 0; i < this->items.size(); i++) {
        sf::Vector2f pos;
        pos.x = this->getPosition().x + (this->getRadius()) * cos(rad + ((rad_max / this->items.size()) * i));
        pos.y = this->getPosition().y + (this->getRadius()) * sin(rad + ((rad_max / this->items.size()) * i));
        this->items[i].setPosition(pos);
    }
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
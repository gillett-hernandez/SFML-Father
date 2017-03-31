#include "RingMenu.hpp"
#include <cmath>
#include "../TextureManager/TextureManager.hpp"

RingMenu *RingMenu::s_instance = nullptr;

const sf::Color ringColor = sf::Color(0xFF,0xFF,0xFF,0xFF);
const sf::Color clearColor = sf::Color(0x00,0x00,0x00,0x00);
//const double pi = 3.141592653589793;

static const bool debug = false; 

RingMenu::RingMenu() {
    float radius = ScreenManager::screenHeight()/8;
    rad = 0.0f;
    this->setInfo(std::string("This is a Ring Menu"));

    //this->setOrigin(radius/2, radius/2);
    this->setPosition(ScreenManager::screenWidth()/2,ScreenManager::screenHeight()/2);
    this->setRadius(radius);
    this->move(-ScreenManager::screenHeight()/8,-ScreenManager::screenHeight()/8);

    this->setPointCount(3);
    this->setOutlineColor(sf::Color(ringColor));
    this->setFillColor(clearColor);
    this->setOutlineThickness(1);
    //this->hidden = true;
    RingMenuItem item = RingMenuItem(this, RingMenuItemTypeWeapon);
    this->items.push_back(item);
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

    sf::Vector2f pos;
    //float angle = 45.0f;
    // ftfy. angles were reversed, left went clockwise when its supposed to go counterclockwise - gillett
    rad -= 0.05f;
    pos.x = this->getPosition().x + (this->getRadius() * cos(rad));
    pos.y = this->getPosition().y + (this->getRadius() * sin(rad));

//    pos.x = this->getPosition().x;// + radius * cos(1);
//    pos.y = this->getPosition().y;// + radius * sin(1);

    this->items[0].setPosition(pos);

    std::cout << "pos.x " << pos.x << "pos.y " << pos.y << std::endl;
}
void RingMenu::right() {
    if (debug) {
        std::cout << "RingMenu::right" << std::endl;
    }

    sf::Vector2f pos;
    //float angle = 45.0f;
    rad += 0.05f;
    pos.x = this->getPosition().x + (this->getRadius() * cos(rad));
    pos.y = this->getPosition().y + (this->getRadius() * sin(rad));

//    pos.x = this->getPosition().x;// + radius * cos(1);
//    pos.y = this->getPosition().y;// + radius * sin(1);

    this->items[0].setPosition(pos);

    std::cout << "pos.x " << pos.x << "pos.y " << pos.y << std::endl;
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
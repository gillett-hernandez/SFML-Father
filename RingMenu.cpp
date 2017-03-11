#include "RingMenu.hpp"

RingMenu *RingMenu::s_instance = nullptr;

const sf::Color ringColor = sf::Color(0xFF,0xFF,0xFF,0xFF);
const sf::Color clearColor = sf::Color(0x00,0x00,0x00,0x00);

static const bool debug = true; 

RingMenu::RingMenu() {
    this->setInfo(std::string("This is a Ring Menu"));
    this->setPosition(1920/2,1080/2);
    this->setRadius(100);
    this->move(-100,-100);
    this->setPointCount(7);
    this->setOutlineColor(sf::Color(ringColor));
    this->setFillColor(clearColor);
    this->setOutlineThickness(1);
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
}
void RingMenu::right() {
    if (debug) {
        std::cout << "RingMenu::right" << std::endl;
    }
}
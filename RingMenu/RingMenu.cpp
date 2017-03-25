#include "RingMenu.hpp"

RingMenu *RingMenu::s_instance = nullptr;

const sf::Color ringColor = sf::Color(0xFF,0xFF,0xFF,0xFF);
const sf::Color clearColor = sf::Color(0x00,0x00,0x00,0x00);

static const bool debug = false; 

RingMenu::RingMenu() {
    this->setInfo(std::string("This is a Ring Menu"));
    this->setPosition(ScreenManager::screenWidth()/2,ScreenManager::screenHeight()/2);
    this->setRadius(ScreenManager::screenHeight()/8);
    this->move(-ScreenManager::screenHeight()/8,-ScreenManager::screenHeight()/8);
    this->setPointCount(3);
    this->setOutlineColor(sf::Color(ringColor));
    this->setFillColor(clearColor);
    this->setOutlineThickness(1);
    this->hidden = true;
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
    this->setPointCount(this->getPointCount()+1);
}
void RingMenu::downPressed() {
    if (debug) {
        std::cout << "RingMenu::downPressed" << std::endl;
    }
    int pointCount = this->getPointCount();
    if (pointCount > 3) {
        this->setPointCount(this->getPointCount()-1);
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
    this->move(0, -5);
}
void RingMenu::down() {
    if (debug) {
        std::cout << "RingMenu::down" << std::endl;
    }
    this->move(0, 5);
}
void RingMenu::left() {
    if (debug) {
        std::cout << "RingMenu::left" << std::endl;
    }
    this->move(-5, 0);
}
void RingMenu::right() {
    if (debug) {
        std::cout << "RingMenu::right" << std::endl;
    }
    this->move(5, 0);
}

void RingMenu::enterPressed() {
    if (debug) {
        std::cout << "RingMenu::enterPressed" << std::endl;
    }
    this->toggleHidden();

}

void RingMenu::drawToWindow(sf::RenderWindow &windowRef) {
    windowRef.draw(*this);
}

void RingMenu::toggleHidden() {
    this->hidden = !this->hidden;
    if (this->hidden) {
        this->hide();
    } else {
        this->show();
    }
}
#include <cmath>
#include "RingMenuItem.hpp"
#include "../TextureManager/TextureManager.hpp"
#include "../ScreenManager/ScreenManager.hpp"
RingMenuItem::RingMenuItem() {
    //this->setColor(sf::Color(0xFF, 0xFF, 0xFF, 0xFF));
    //this->setPosition(100, 100);
    //this->setOrigin(-34-34-17,-34-34-17);
    this->setTexture(TextureManager::instance()->getRef(kRingMenuItemTexture));
    this->setType(RingMenuItemTypeItem);
}
RingMenuItem::RingMenuItem(RingMenu* parent, RingMenuItemType type) {
    this->parent = parent;
    //this->setColor(sf::Color(0xFF, 0xFF, 0xFF, 0xFF));
    //this->setPosition(100, 100);
    float v = this->parent->getRadius() - this->parent->getPosition().x;
    // for some reason 23 seems to be the magic value. 2 minutes later - its because 24.04 = 17*sqrt(2)
    float origin = (this->parent->getPosition().x + this->parent->getRadius())/sqrt(2) - this->parent->getPosition().x - 24.04;
    this->setOrigin(origin, origin);
    //std::cout << "-----" << sqrt(2)*(-34*v + this->parent->getPosition().x) << "-----" << std::endl;
    //std::cout << "-----" << origin << "-----" << std::endl;
    //std::cout << "-----" << this->parent->getPosition().x + this->parent->getRadius() << "-----" << std::endl;
    this->setTexture(TextureManager::instance()->getRef(kRingMenuItemTexture));
    this->setType(type);
    std::cout << type;
}
void RingMenuItem::setType(RingMenuItemType type) {
    this->type = type;
    switch (this->type) {
        case RingMenuItemTypeNone: {
            break;
        }
        case RingMenuItemTypeArmor: {
            this->setTextureRect(sf::IntRect(34*4, 34*5, 34, 34));
            break;
        }
        case RingMenuItemTypeWeapon: {
            this->setTextureRect(sf::IntRect(34*4, 0, 34, 34));
            break;
        }
        case RingMenuItemTypeItem: {
            this->setTextureRect(sf::IntRect(34*6, 34*5, 34, 34));
            break;
        }
        default: {
            break;
        }
    }
}

RingMenuItem::~RingMenuItem() {

}
void RingMenuItem::drawToWindow(sf::RenderWindow &windowRef) {
    windowRef.draw(*this);
    //sf::RectangleShape rect = sf::RectangleShape();
    //rect.setSize(sf::Vector2f(34,34));
    //rect.setPosition(this->getPosition());
    //windowRef.draw(rect);
}
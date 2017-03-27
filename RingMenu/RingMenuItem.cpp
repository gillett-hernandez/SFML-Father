#include "RingMenuItem.hpp"
#include "../TextureManager/TextureManager.hpp"
RingMenuItem::RingMenuItem() {
    this->setColor(sf::Color(0xFF, 0xFF, 0xFF, 0xFF));
    //this->setPosition(100, 100);
    this->setOrigin(-34,-34);
    this->setTexture(TextureManager::instance()->getRef(kRingMenuItemTexture));
}
RingMenuItem::RingMenuItem(RingMenuItemType type) {
    this->setColor(sf::Color(0xFF, 0xFF, 0xFF, 0xFF));
    //this->setPosition(100, 100);
    this->setOrigin(-34,-34);
    this->setTexture(TextureManager::instance()->getRef(kRingMenuItemTexture));
    this->setType(type);
}
void RingMenuItem::setType(RingMenuItemType type) {
    this->type = type;
    switch (this->type) {
        case RingMenuItemTypeNone: {
            break;
        }
        case RingMenuItemTypeArmor: {
            this->setTextureRect(sf::IntRect(34*4, 0, 34, 34));
            break;
        }
        case RingMenuItemTypeWeapon: {
            this->setTextureRect(sf::IntRect(34*4, 0, 34, 34));
            break;
        }
        case RingMenuItemTypeItem: {
            this->setTextureRect(sf::IntRect(34*6, 0, 34, 34));
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
}
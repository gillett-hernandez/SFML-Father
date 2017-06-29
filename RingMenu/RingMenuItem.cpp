#include <cmath>
#include "RingMenuItem.hpp"
#include "../TextureManager/TextureManager.hpp"
#include "../ScreenManager/ScreenManager.hpp"

RingMenuItem::RingMenuItem() {
    this->setTexture(TextureManager::instance()->getRef(kRingMenuItemTexture));
    this->setType(RingMenuItemTypeItem);
}
RingMenuItem::RingMenuItem(RingMenu* parent, RingMenuItemType type) {
    this->parent = parent;
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
            this->setTextureRect(this->IntRectForTile(4,5,34,34));
            break;
        }
        case RingMenuItemTypeWeapon: {
            this->setTextureRect(this->IntRectForTile(4,0,34,34));
            break;
        }
        case RingMenuItemTypeItem: {
            this->setTextureRect(this->IntRectForTile(6,5,34,34));
            break;
        }
        case RingMenuItemTypeShield: {
            this->setTextureRect(this->IntRectForTile(5,4,34,34));
            break;
        }
        case RingMenuItemTypeSpear0: {
            this->setTextureRect(this->IntRectForTile(0,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear1: {
            this->setTextureRect(this->IntRectForTile(1,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear2: {
            this->setTextureRect(this->IntRectForTile(2,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear3: {
            this->setTextureRect(this->IntRectForTile(3,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear4: {
            this->setTextureRect(this->IntRectForTile(4,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear5: {
            this->setTextureRect(this->IntRectForTile(5,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear6: {
            this->setTextureRect(this->IntRectForTile(6,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear7: {
            this->setTextureRect(this->IntRectForTile(7,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear8: {
            this->setTextureRect(this->IntRectForTile(8,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear9: {
            this->setTextureRect(this->IntRectForTile(9,0,34,34));
            break;
        }
        case RingMenuItemTypeSpear10: {
            this->setTextureRect(this->IntRectForTile(10,0,34,34));
            break;
        }
        default: {
            break;
        }
    }
}

sf::IntRect RingMenuItem::IntRectForTile(uint8_t x, uint8_t y, uint8_t tileWidth, uint8_t tileHeight) {
    return sf::IntRect(x * tileWidth, y * tileHeight, tileWidth, tileHeight);
}

RingMenuItem::~RingMenuItem() {

}
void RingMenuItem::drawToWindow(sf::RenderWindow &windowRef) {
    //if (this->parent->isHidden() == false) {
        windowRef.draw(*this);
    //}
}

float RingMenuItem::width() {
    return this->getTextureRect().width;
}
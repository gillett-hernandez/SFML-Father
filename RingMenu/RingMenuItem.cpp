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
    float radius = this->parent->getRadius();
    float origin = (this->parent->getPosition().x + radius)/sqrt(2) - this->parent->getPosition().x - (17 * sqrt(2)); //17 is 34 / 2, 34 is the width of the tiles in the sprite tileset
    this->setOrigin(origin, origin);
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
    windowRef.draw(*this);
}
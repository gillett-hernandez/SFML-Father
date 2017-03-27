#ifndef RINGMENUITEM_H
#define RINGMENUITEM_H
#include <SFML/Graphics.hpp>
#include "../FatherDrawable.hpp"
#include "RingMenuItemType.hpp"
class RingMenuItem: public FatherDrawable, public sf::Sprite {
private:
    sf::Texture texture;
    RingMenuItemType type;
    void setType(RingMenuItemType type);
public:
    RingMenuItem();
    RingMenuItem(RingMenuItemType type);
    ~RingMenuItem();
    void drawToWindow(sf::RenderWindow &windowRef) override;
};
#endif
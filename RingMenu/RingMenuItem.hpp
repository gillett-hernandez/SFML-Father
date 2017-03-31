#ifndef RINGMENUITEM_H
#define RINGMENUITEM_H
#include <SFML/Graphics.hpp>
#include "../FatherDrawable.hpp"
#include "RingMenu.hpp"
#include "RingMenuItemType.hpp"

class RingMenu;

class RingMenuItem: public FatherDrawable, public sf::Sprite {
private:
    sf::Texture texture;
    RingMenuItemType type;
    void setType(RingMenuItemType type);
    RingMenu* parent;
public:
    RingMenuItem();
    RingMenuItem(RingMenu* parent, RingMenuItemType type);
    ~RingMenuItem();
    void drawToWindow(sf::RenderWindow &windowRef) override;
};
#endif
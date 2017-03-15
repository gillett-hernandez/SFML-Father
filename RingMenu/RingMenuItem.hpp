#ifndef RINGMENUITEM_H
#define RINGMENUITEM_H
#include <SFML/Graphics.hpp>
#include "../FatherDrawable.hpp"
class RingMenuItem: public FatherDrawable, public sf::Sprite {
private:
public:
    RingMenuItem();
    ~RingMenuItem();
    void drawToWindow(sf::RenderWindow &windowRef) override;
};
#endif
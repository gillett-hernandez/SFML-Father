#ifndef FATHERDRAWABLE_H
#define FATHERDRAWABLE_H
#include <SFML/Window.hpp>
class FatherDrawable
{
public:
    virtual void drawToWindow(sf::RenderWindow &windowRef) = 0;    
};
#endif
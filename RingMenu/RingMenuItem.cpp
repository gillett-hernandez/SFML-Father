#include "RingMenuItem.hpp"
RingMenuItem::RingMenuItem() {

}
// RingMenuItem::RingMenuItem(std::string textureName) {
//     if (this->myTexture.loadFromFile(textureName)) {
//         this->setTexture(this->myTexture);
//         this->setTextureRect(sf::IntRect(0, 0, 256, 256));
//         this->setColor(sf::Color(255, 255, 255, 255));
//         this->setPosition(100, 25);
//     }
// }
RingMenuItem::~RingMenuItem() {

}
void RingMenuItem::drawToWindow(sf::RenderWindow &windowRef) {
    windowRef.draw(*this);
}
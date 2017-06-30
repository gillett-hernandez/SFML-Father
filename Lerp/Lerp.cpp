//
// Created by Estevan Hernandez on 6/29/17.
//

#include "Lerp.hpp"

namespace Lerp {
    sf::Uint8 sfUint8Lerp(sf::Uint8 a, sf::Uint8 b, sf::Uint8 top, sf::Uint8 bottom) {
        // lerp stands for Linear intERPolation
        // this function returns the point that is exactly `top/bottom` of the way from `a` to `b`
        return (a * bottom + (b - a) * top) / bottom;
    }
}

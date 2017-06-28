//
// Created by Estevan Hernandez on 6/27/17.
//

#ifndef SFML_FATHER_ALARMLISTENER_HPP
#define SFML_FATHER_ALARMLISTENER_HPP

#include <cstdint>
#include "Alarm.hpp"
#include <SFML/System.hpp>

//class Alarm;

class AlarmListener {
public:
    virtual void frameTick(Alarm *alarm, sf::Uint8 currentFrame, sf::Uint8 frames) = 0;
};


#endif //SFML_FATHER_ALARMLISTENER_HPP

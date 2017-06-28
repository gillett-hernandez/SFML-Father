//
// Created by Estevan Hernandez on 6/27/17.
//

#ifndef SFML_FATHER_ALARM_HPP
#define SFML_FATHER_ALARM_HPP

//#include "AlarmListener.hpp"
#include "AlarmManager.hpp"
#include <cstdint>
#include <SFML/System.hpp>

class AlarmListener;

class Alarm {
private:
    sf::Uint8 currentFrame;
    sf::Uint8 frames;
    //std::vector<AlarmListener *> listeners; // maybe one alarm will need to inform several listeners?
    AlarmListener *listener;
public:
    Alarm();
    void incrementFrame();
    Alarm(int frames, AlarmListener *listener);
    void setAlarmListener(AlarmListener *listener);
    void addToManager(AlarmManager *manager);
    void configure(int frames, AlarmListener *listener);
    Alarm(AlarmListener *listener);
    ~Alarm();
};


#endif //SFML_FATHER_ALARM_HPP

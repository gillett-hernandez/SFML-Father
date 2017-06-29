//
// Created by Estevan Hernandez on 6/27/17.
//

#include "AlarmManager.hpp"
#include "Alarm.hpp"
#include <iostream>

const bool debug = true;

AlarmManager *AlarmManager::s_instance = nullptr;

AlarmManager::AlarmManager() {

}

AlarmManager::~AlarmManager() {

}

void AlarmManager::incrementFrame() {
    if (debug) std::cout << "alarms: " << this->alarms.size() << std::endl;
    for (Alarm *alarm: this->alarms) {
        if (debug) std::cout << "calling alarm->incrementFrame()" << std::endl;
        alarm->incrementFrame();
    }
}

void AlarmManager::addAlarm(Alarm *alarm) {
    this->alarms.push_back(alarm);
}

void AlarmManager::removeAlarm(Alarm *alarm) {
    this->alarms.erase(std::remove(this->alarms.begin(), this->alarms.end(), alarm), this->alarms.end());
}
//
// Created by Estevan Hernandez on 6/27/17.
//

#include "Alarm.hpp"
#include "AlarmManager.hpp"
#include "AlarmListener.hpp"
#include <iostream>

const bool debug = true;

Alarm Alarm::*listener = nullptr;

Alarm::Alarm() {
    this->currentFrame = 0;
    //this->listener->frameTick(this, this->currentFrame);
}

Alarm::Alarm(AlarmListener *listener) {
    this->currentFrame = 0;
    this->listener = listener;
}

Alarm::Alarm(int frames, AlarmListener *listener) {
    this->currentFrame = 0;
    this->frames = frames;
    this->listener = listener;
    AlarmManager::instance()->addAlarm(this);
}

Alarm::~Alarm() {

}

void Alarm::incrementFrame() {
    if (debug) {
        std::cout << "currentFrame: " << (int) this->currentFrame << " frames: " << (int) this->frames << std::endl;
    }
    if (this->currentFrame <= this->frames) {
        if (this->listener != nullptr) {
            this->listener->frameTick(this, this->currentFrame, this->frames);
            if (debug) std::cout << "Alarm: " << this << " informing listener: " << this->listener << "of incrementFrame" << std::endl;
        } else {
            if (debug) std::cout << "There is no listener" << std::endl;
        }
        this->currentFrame++;
    } else {
        AlarmManager::instance()->removeAlarm(this);
        if (debug) {
            std::cout << "AlarmManager removed alarm" << std::endl;
        }
    }
}

void Alarm::setAlarmListener(AlarmListener *listener) {
    this->listener = listener;
}
void Alarm::addToManager(AlarmManager *manager) {
    manager->addAlarm(this);
}

void Alarm::configure(int frames, AlarmListener *listener) {
    this->frames = frames;
    this->setAlarmListener(listener);
}
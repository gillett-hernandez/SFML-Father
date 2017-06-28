//
// Created by Estevan Hernandez on 6/27/17.
//

#ifndef SFML_FATHER_ALARMMANAGER_HPP
#define SFML_FATHER_ALARMMANAGER_HPP

//#include "Alarm.hpp"

class Alarm;
#include <vector>

class AlarmManager {
private:
    AlarmManager();
    static AlarmManager *s_instance;
    std::vector<Alarm *> alarms;
public:
    static AlarmManager *instance() {
        if (!s_instance) {
            s_instance = new AlarmManager;
        }
        return s_instance;
    }
    void addAlarm(Alarm *alarm);
    void removeAlarm(Alarm *alarm);
    void incrementFrame();
    ~AlarmManager();
};


#endif //SFML_FATHER_ALARMMANAGER_HPP

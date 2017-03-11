#ifndef INFO_H
#define INFO_H
#include <iostream>
class Info {
    private:
        std::string info;
    public:
        std::string getInfo();
        void setInfo(std::string info);
        Info();
        ~Info();

};
#endif
#ifndef LEDS_H
#define LEDS_H
#include "motion.h"
#include <string>

class Leds : public Motion
{
public:
    Leds(std::string ledName, AL::ALValue colorList, AL::ALValue targetTimes);
    void action();
protected:
    std::string ledName;
    AL::ALValue colorList;
    AL::ALValue targetTimes;
};

#endif // LEDS_H

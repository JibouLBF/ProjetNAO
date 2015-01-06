#ifndef LEG_H
#define LEG_H

#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

#include "basicmotion.h"

class Leg : public BasicMotion
{
public:
    Leg();

    Leg(AL::ALValue stiffness, AL::ALValue time);

    Leg(AL::ALValue jointName, AL::ALValue targetAngles,
         AL::ALValue time, bool isAbsolute);

    Leg(AL::ALValue stiffness, AL::ALValue time,
         AL::ALValue jointName, AL::ALValue targetAngles,
         bool isAbsolute);

};

#endif // LEG_H

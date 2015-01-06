#ifndef ARM_H
#define ARM_H
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

#include "basicmotion.h"

class Arm : public BasicMotion
{
public:
    Arm();

    Arm(AL::ALValue stiffness, AL::ALValue time);

    Arm(AL::ALValue jointName, AL::ALValue targetAngles,
         AL::ALValue time, bool isAbsolute);

    Arm(AL::ALValue stiffness, AL::ALValue time,
         AL::ALValue jointName, AL::ALValue targetAngles,
         bool isAbsolute);

private:
    AL::ALValue motionNameProperties;

};

#endif // ARM_H

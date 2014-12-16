#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

#include "basicmotion.h"


class Head : public BasicMotion
{
public:
    Head();

    Head(AL::ALValue stiffness, AL::ALValue time);

    Head(AL::ALValue jointName, AL::ALValue targetAngles,
         AL::ALValue targetTimes, bool isAbsolute);

    Head(AL::ALValue stiffness, AL::ALValue time,
         AL::ALValue jointName, AL::ALValue targetAngles,
         AL::ALValue targetTimes, bool isAbsolute);

private:

};

#endif // HEAD_H

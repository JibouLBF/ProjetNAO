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
    /** Target stiffness. */
    AL::ALValue stiffness = 1.0f;
    /** Time (in seconds) to reach the target. */
    AL::ALValue time = 1.0f;

    /** The name of the joint to be moved. */
    AL::ALValue jointName;
    /** Set the target angle list, in radians. */
    AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
    /** Set the corresponding time lists, in seconds. */
    AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
    /** Specify that the desired angles are absolute. */
    bool isAbsolute = true;


};

#endif // HEAD_H

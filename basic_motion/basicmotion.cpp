#include "basicmotion.h"
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

AL::ALMotionProxy* BasicMotion::basicMotionProxy = new AL::ALMotionProxy ("192.168.0.1", 9559);

BasicMotion::BasicMotion()
{

}
AL::ALValue BasicMotion::getMotionName() const
{
    return motionName;
}

void BasicMotion::setMotionName(const AL::ALValue &value)
{
    motionName = value;
}
AL::ALValue BasicMotion::getAngleList() const
{
    return angleList;
}

void BasicMotion::setAngleList(const AL::ALValue &value)
{
    angleList = value;
}
AL::ALValue BasicMotion::getTimeList() const
{
    return timeList;
}

void BasicMotion::setTimeList(const AL::ALValue &value)
{
    timeList = value;
}
AL::ALValue BasicMotion::getStiffness() const
{
    return stiffness;
}

void BasicMotion::setStiffness(const AL::ALValue &value)
{
    stiffness = value;
}
bool BasicMotion::getIsAbsolute() const
{
    return isAbsolute;
}

void BasicMotion::setIsAbsolute(bool value)
{
    isAbsolute = value;
}

void BasicMotion::action()
{
    std::cout << "BasicMotion Action" << std::endl;

    /** Call the angle interpolation method. The joint will reach the
    * desired angles at the desired times.
    */
    basicMotionProxy->angleInterpolation(motionName, angleList, timeList, isAbsolute);
}






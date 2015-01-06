#include "leg.h"
#include <iostream>

Leg::Leg()
{
}

Leg::Leg(AL::ALValue stiffness, AL::ALValue time){
    this->stiffness = stiffness;
    this->timeList = time;
}

Leg::Leg(AL::ALValue jointName, AL::ALValue targetAngles,
     AL::ALValue time, bool isAbsolute){

    this->motionName = jointName;
    this->angleList = targetAngles;
    this->timeList = time;
    this->isAbsolute = isAbsolute;
}

Leg::Leg(AL::ALValue stiffness, AL::ALValue time,
     AL::ALValue jointName, AL::ALValue targetAngles, bool isAbsolute){

    this->stiffness = stiffness;
    this->timeList = time;
    this->motionName = jointName;
    this->angleList = targetAngles;
    this->isAbsolute = isAbsolute;
}

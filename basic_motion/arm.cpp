#include <iostream>
#include "arm.h"

Arm::Arm()
{
}

Arm::Arm(AL::ALValue stiffness, AL::ALValue time){
    this->stiffness = stiffness;
    this->timeList = time;
}

Arm::Arm(AL::ALValue jointName, AL::ALValue targetAngles,
     AL::ALValue time, bool isAbsolute){

    this->motionName = jointName;
    this->angleList = targetAngles;
    this->timeList = time;
    this->isAbsolute = isAbsolute;
}

Arm::Arm(AL::ALValue stiffness, AL::ALValue time,
     AL::ALValue jointName, AL::ALValue targetAngles,
     bool isAbsolute){

    this->stiffness = stiffness;
    this->timeList = time;
    this->motionName = jointName;
    this->angleList = targetAngles;
    this->isAbsolute = isAbsolute;
}

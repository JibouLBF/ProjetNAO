#include <iostream>
#include "head.h"
#include "common.h"

Head::Head()
{
    std::cout << "Head" << std::endl;
}

Head::Head(AL::ALValue stiffness, AL::ALValue time){
    this->stiffness = stiffness;
    this->timeList = time;
}

Head::Head(AL::ALValue jointName, AL::ALValue targetAngles,
     AL::ALValue targetTimes, bool isAbsolute){

    this->motionName = jointName;
    this->angleList = targetAngles;
    this->timeList = targetTimes;
    this->isAbsolute = isAbsolute;
}

Head::Head(AL::ALValue stiffness, AL::ALValue time,
     AL::ALValue jointName, AL::ALValue targetAngles,
     AL::ALValue targetTimes, bool isAbsolute){

    this->stiffness = stiffness;
    this->timeList = time;
    this->motionName = jointName;
    this->angleList = targetAngles;
    this->timeList = targetTimes;
    this->isAbsolute = isAbsolute;
}

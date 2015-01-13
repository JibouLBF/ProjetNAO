#include "motion.h"

AL::ALMotionProxy* Motion::basicMotionProxy = NULL;
AL::ALRobotPostureProxy* Motion::postureProxy = NULL;


Motion::Motion()
{
    //this->name= name;
}

void Motion::initProxy(std::string ip, int port){
    basicMotionProxy = new AL::ALMotionProxy (ip, port);
    postureProxy = new AL::ALRobotPostureProxy (ip, port);
}

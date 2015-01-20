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

void Motion::relax(){
    basicMotionProxy->rest();
}

void Motion::moveTo(int x, int y, int z){
    this->basicMotionProxy->move(x, y, z);
}

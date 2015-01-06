#include "posture.h"

AL::ALRobotPostureProxy* Posture::postureProxy = new AL::ALRobotPostureProxy ("192.168.0.1", 9559);

Posture::Posture()
{
}

void Posture::action()
{
    this->postureProxy->goToPosture(typeOfPosture,1.0);
}

#include "posture.h"

AL::ALRobotPostureProxy* Posture::postureProxy = new AL::ALRobotPostureProxy ("192", 9552);

Posture::Posture()
{
}

void Posture::action()
{
    this->postureProxy->goToPosture(typeOfPosture,1.0);
}

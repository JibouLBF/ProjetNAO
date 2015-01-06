#include "posture.h"

AL::ALRobotPostureProxy* Posture::postureProxy = new AL::ALRobotPostureProxy ("147.171.35.236", 9559);

Posture::Posture()
{
}

void Posture::action()
{
    this->postureProxy->goToPosture(typeOfPosture,1.0);
}

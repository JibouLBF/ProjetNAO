#include "posture.h"

AL::ALRobotPostureProxy* postureProxy = new AL::ALRobotPostureProxy ("192", 9552);

Posture::Posture()
{
}

Posture::action()
{
    postureProxy->goToPosture(TypeOfPosture,1.0);
}

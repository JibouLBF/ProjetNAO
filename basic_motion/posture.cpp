#include "posture.h"
#include "common.h"

Posture::Posture()
{
}

void Posture::action()
{
    Common::postureProxy->goToPosture(typeOfPosture,1.0);
}

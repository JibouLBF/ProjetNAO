#include "walk.h"
#include "common.h"

Walk::Walk(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void Walk::action(){
    Common::basicMotionProxy->moveTo(x, y, z, AL::ALValue::array(AL::ALValue::array("MaxStepX", 0.05f),         // step of 2 cm in front
                                                                 AL::ALValue::array("MaxStepY", 0.16f),         // default value
                                                                 AL::ALValue::array("MaxStepTheta", 0.4f),      // default value
                                                                 AL::ALValue::array("MaxStepFrequency", 0.0f),  // low frequency
                                                                 AL::ALValue::array("StepHeight", 0.03f),       // step height of 1 cm
                                                                 AL::ALValue::array("TorsoWx", 0.0f),           // default value
                                                                 AL::ALValue::array("TorsoWy", 0.1f)));
}

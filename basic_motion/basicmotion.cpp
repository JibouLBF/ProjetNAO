#include <iostream>
#include "basicmotion.h"
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

AL::ALMotionProxy* BasicMotion::motion = new AL::ALMotionProxy ("192", 9552);

BasicMotion::BasicMotion()
{

}

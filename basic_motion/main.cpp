#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

#include "motion.h"
#include "basicmotion.h"
#include "head.h"


int main()
{
   std::cout << "Hello, world" << std::endl;

    try {
        AL::ALValue jointName = "HeadYaw";
        AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
        AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
        bool isAbsolute = true;
        Motion* bm = new Head(jointName,targetAngles, targetTimes, isAbsolute);
        bm->action();

    }
    catch (const AL::ALError& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return(1);
    }

  return 0;
}

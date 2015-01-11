#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

#include "motion.h"
#include "basicmotion.h"
#include "head.h"
#include "stand.h"
#include "sit.h"


int main(int argc, char* argv[])
{
   std::cout << "Hello, world" << std::endl;

    try {
        Motion* bm = new Sit();
        bm->action();
        AL::ALValue jointName = "HeadYaw";
        AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
        AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
        bool isAbsolute = true;
        bm = new Head(jointName,targetAngles, targetTimes, isAbsolute);
        bm->action();
    }
    catch (const AL::ALError& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return(1);
    }

  return 0;
}

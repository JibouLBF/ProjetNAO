#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

#include <signal.h>
#include <boost/shared_ptr.hpp>
#include <alcommon/albroker.h>
#include <alcommon/almodule.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>

#include "motion.h"
#include "basicmotion.h"
#include "head.h"
#include "stand.h"
#include "sit.h"
#include "sensorlistener.h"
#include "sensorlistenertest.h"
#include "common.h"
#include "arm.h"


int main(int argc, char* argv[])
{
    std::cout << "Hello, world" << std::endl;

    try {
        boost::shared_ptr<AL::ALBroker> broker = Common::makeLocalBroker("192.168.0.1", 9559);
        AL::ALModule::createModule<SensorListenerTest>(broker, "SensorListenerTest");

        Common::initProxy("192.168.0.1", 9559);

        Motion* bm = new Stand();
        bm->action();
        //bm->relax();
        bm->moveTo(0,0,0);

        /*AL::ALValue jointName = AL::ALValue::array("LShoulderPitch","RShoulderPitch");
        AL::ALValue targetAngles = AL::ALValue::array(AL::ALValue::array(-1.5f, 1.5f, 0.0f), AL::ALValue::array(-1.5f, 1.5f, 0.0f));
        AL::ALValue targetTimes =AL::ALValue::array( AL::ALValue::array(3.0f, 6.0f, 9.0f), AL::ALValue::array(3.0f, 6.0f, 9.0f));
        bool isAbsolute = true;
        Motion* arm = new Arm(jointName,targetAngles, targetTimes, isAbsolute);
        arm->action();
        /*AL::ALValue jointName = "HeadYaw";
        Motion* bm = new Head(jointName,targetAngles, targetTimes, isAbsolute);
        bm->action();*/
        while(1){}
    }
    catch (const AL::ALError& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return(1);
    }

    return 0;
}

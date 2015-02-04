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
#include "scheduler.h"
#include "crouch.h"
#include "facedetectionlistenertest.h"
#include "sounddetectionlistenertest.h"
#include "soundlocalizationlistener.h"
#include "walk.h"
#include "leds.h"
#include "say.h"
#include "posture/sitrelax.h"
#include "waitforevent.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello, world" << std::endl;

    try {
        Common::broker = Common::makeLocalBroker("192.168.0.1", 9559);
        Common::initProxy("192.168.0.1", 9559);

        AL::ALModule::createModule<SensorListenerTest>(Common::broker, "SensorListenerTest");
        AL::ALModule::createModule<FaceDetectionListenerTest>( Common::broker, "FaceDectionListenerTest" );
        AL::ALModule::createModule<SoundLocalizationListener>(Common::broker, "SoundLocalizationListener" );


        AL::ALValue jointName = AL::ALValue::array("LShoulderPitch","RShoulderPitch");
        AL::ALValue targetAngles = AL::ALValue::array(AL::ALValue::array(-1.5f, 1.5f, 0.0f), AL::ALValue::array(-1.5f, 1.5f, 0.0f));
        AL::ALValue targetTimes =AL::ALValue::array( AL::ALValue::array(3.0f, 6.0f, 9.0f), AL::ALValue::array(3.0f, 6.0f, 9.0f));
        bool isAbsolute = true;
        Motion* arm = new Arm(jointName,targetAngles, targetTimes, isAbsolute);
        //Common::scheduler.addEvent(new Crouch());
        //Common::scheduler.addEvent(arm);
        //Common::scheduler.addEvent(new Walk(1,0,0));
        /*Common::scheduler.addEvent(new Leds("RightEyeLeds",AL::ALValue::array(0x00FF0066),AL::ALValue::array(1.0f)));
        Common::scheduler.addEvent(new Leds("LeftEyeLeds",AL::ALValue::array(0x00FF0066),AL::ALValue::array(1.0f)));
        Common::scheduler.addEvent(new Leds("RightEarLeds",AL::ALValue::array(0x000000FF),AL::ALValue::array(1.0f)));
        Common::scheduler.addEvent(new Leds("LeftEarLeds",AL::ALValue::array(0x00FF0066),AL::ALValue::array(1.0f)));

        Common::scheduler.addEvent(new Leds("RightFootLeds",AL::ALValue::array(0x00FF0006),AL::ALValue::array(1.0f)));
        Common::scheduler.addEvent(new Leds("LeftFootLeds",AL::ALValue::array(0x00FF0006),AL::ALValue::array(1.0f)));

        Common::scheduler.addEvent(new Stand());*/
        //Common::scheduler.addEvent(new Say("Bonjour les petits pères"));
        Common::scheduler.addEvent(new Stand());
        Common::scheduler.addEvent(new WaitForEvent(&Common::soundDetected));
        Common::scheduler.addEvent(new Sit());
        Common::scheduler.play();

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

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

#include "./motion/motion.h"
#include "./motion/basicmotion/basicmotion.h"
#include "./motion/basicmotion/head.h"
#include "./motion/posture/stand.h"
#include "./motion/posture/sit.h"
#include "./listener/sensorlistener.h"
#include "./listener/sensorlistenertest.h"
#include "./common/common.h"
#include "./motion/basicmotion/arm.h"
#include "./common/scheduler.h"
#include "./motion/posture/crouch.h"
#include "./listener/facedetectionlistenertest.h"
#include "./listener/sounddetectionlistenertest.h"
#include "./listener/soundlocalizationlistener.h"
#include "./motion/basicmotion/walk.h"
#include "./motion/others/leds.h"
#include "./motion/others/say.h"
#include "./motion/posture/sitrelax.h"
#include "./motion/others/waitforevent.h"
#include "./listener/soundlocalizationlistenertest.h"

int main(int argc, char* argv[])
{
    std::cout << "Hello, world" << std::endl;

    try {
        Common::init("192.168.0.1", 9559);

        AL::ALModule::createModule<SensorListenerTest>(Common::broker, "SensorListenerTest");
        AL::ALModule::createModule<FaceDetectionListenerTest>( Common::broker, "FaceDectionListenerTest" );
        AL::ALModule::createModule<SoundLocalizationListenerTest>(Common::broker, "SoundLocalizationListenerTest" );


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
        Common::scheduler.addEvent(new Stand());
        Common::scheduler.addEvent(new WaitForEvent(&Common::soundDetected));
        Common::scheduler.addEvent(new Sit());
        Common::scheduler.play();

        while(1){}
    }
    catch (const AL::ALError& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return(1);
    }

    return 0;
}

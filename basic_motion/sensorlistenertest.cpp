#include <string.h>
#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <qi/log.hpp>
#include <althread/alcriticalsection.h>

#include "sensorlistenertest.h"
#include "common.h"


using namespace std;

SensorListenerTest::SensorListenerTest(boost::shared_ptr<AL::ALBroker> broker,const std::string& name):
    SensorListener::SensorListener(broker, name)
{
    cout<<"init"<<endl;
}


void SensorListenerTest::onRightBumperPressed(){
    cout<<"action catch"<<endl;
    Common::basicMotionProxy->killAll();
}

void SensorListenerTest::onMiddleTactilTouched(){

    //As long as this is defined, the code is thread-safe.
    AL::ALCriticalSection section(fCallbackMutex);
    std::cout<<"RightBumperPressed"<<std::endl;
    //Check that the bumper is pressed.

    fState =  fMemoryProxy.getData("RightBumperPressed");
    // Motion::initProxy("192.168.0.1", 9559);
    // Motion* m = new LyingBelly();
    if (fState  > 0.5f) {
        return;
    }
    try {
        fTtsProxy = AL::ALTextToSpeechProxy(getParentBroker());
        // fTtsProxy.say("alors ça bagotte ! une sacré chié!");
        // m->action();
        //m->relax();
    }
    catch (const AL::ALError& e) {
        qiLogError("module.example") << e.what() << std::endl;
    }

}

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

#ifdef BUMPER_IS_REMOTE
# define ALCALL
#else
# ifdef _WIN32
#  define ALCALL __declspec(dllexport)
# else
#  define ALCALL
# endif
#endif

extern "C"
{
  ALCALL int _createModule(boost::shared_ptr<AL::ALBroker> pBroker)
  {
    // init broker with the main broker instance
    // from the parent executable
    AL::ALBrokerManager::setInstance(pBroker->fBrokerManager.lock());
    AL::ALBrokerManager::getInstance()->addBroker(pBroker);
      AL::ALModule::createModule<SensorListener>( pBroker, "SensorListener" );

    return 0;
  }

  ALCALL int _closeModule()
  {
    return 0;
  }
}

#ifdef BUMPER_IS_REMOTE
int main(int argc, char* argv[])
{
   std::cout << "Hello, world" << std::endl;

    try {
        // pointer to createModule
        TMainType sig;
        sig = &_createModule;
        // call main
        //Motion::initProxy("192.168.0.1", 9559);
        ALTools::mainFunction("sensorlistener", argc, argv, sig);

        //SensorListener* sens = new SensorListener("BumperLFootLeft");
        /*Motion* bm = new Sit();
        bm->action();
        AL::ALValue jointName = "HeadYaw";
        AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
        AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
        bool isAbsolute = true;
        Motion* bm = new Head(jointName,targetAngles, targetTimes, isAbsolute);
        bm->action();*/
    }
    catch (const AL::ALError& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return(1);
    }

  return 0;
}
#endif

#include "sensorlistener.h"

#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <qi/log.hpp>
#include <althread/alcriticalsection.h>

SensorListener::SensorListener(
  boost::shared_ptr<AL::ALBroker> broker,
  const std::string& name): AL::ALModule(broker, name),
    fCallbackMutex(AL::ALMutex::createALMutex())
{
  setModuleDescription("This module presents how to subscribe to a simple event (here RightBumperPressed) and use a callback method.");

  functionName("onRightBumperPressed", getName(), "Method called when the right bumper is pressed. Makes a LED animation.");
  BIND_METHOD(SensorListener::onRightBumperPressed)
}

SensorListener::~SensorListener() {
  fMemoryProxy.unsubscribeToEvent("onRightBumperPressed", "SensorListener");
}

void SensorListener::init() {
  try {
        std::cout<<"coucou jibou"<<std::endl;
    /** Create a proxy to ALMemory.
    */
    fMemoryProxy = AL::ALMemoryProxy(getParentBroker());

    fState = fMemoryProxy.getData("RightBumperPressed");
    /** Subscribe to event LeftBumperPressed
    * Arguments:
    * - name of the event
    * - name of the module to be called for the callback
    * - name of the bound method to be called on event
    */
    fMemoryProxy.subscribeToEvent("RightBumperPressed", "SensorListener",
                                  "onRightBumperPressed");
  }
  catch (const AL::ALError& e) {
    qiLogError("module.example") << e.what() << std::endl;
  }
}

void SensorListener::onRightBumperPressed() {
    qiLogInfo("module.example") << "Executing callback method on right bumper event" << std::endl;
    /**
    * As long as this is defined, the code is thread-safe.
    */
    AL::ALCriticalSection section(fCallbackMutex);

    /**
    * Check that the bumper is pressed.
    */
    fState =  fMemoryProxy.getData("RightBumperPressed");
    if (fState  > 0.5f) {
      return;
    }
    try {
      fTtsProxy = AL::ALTextToSpeechProxy(getParentBroker());
      fTtsProxy.say("Right bumper pressed");
    }
    catch (const AL::ALError& e) {
      qiLogError("module.example") << e.what() << std::endl;
    }
  }

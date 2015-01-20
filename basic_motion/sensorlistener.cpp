#include "sensorlistener.h"

#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <qi/log.hpp>
#include <althread/alcriticalsection.h>
#include "motion.h"
#include "stand.h"
#include "sit.h"
#include "crouch.h"
#include "lyingback.h"
#include "lyingbelly.h"

SensorListener::SensorListener(boost::shared_ptr<AL::ALBroker> broker,const std::string& name):
    AL::ALModule(broker, name), fCallbackMutex(AL::ALMutex::createALMutex())
{
    setModuleDescription("This module presents how to subscribe to a simple event (here RightBumperPressed) and use a callback method.");
    std::cout<<"coucoutest " <<getName();

    functionName("onRightBumperPressed", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onRightBumperPressed);
    functionName("onLeftBumperPressed", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onLeftBumperPressed);
    functionName("onChestButtonPressed", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onChestButtonPressed);

    functionName("onFrontTactilTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onFrontTactilTouched);
    functionName("onMiddleTactilTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onMiddleTactilTouched);
    functionName("onRearTactilTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onRearTactilTouched);

    functionName("onHotJoinedDetected", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onHotJoinedDetected);

    functionName("onHandRightBackTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onHandRightBackTouched);
    functionName("onHandRightLeftTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onHandRightLeftTouched);
    functionName("onHandRightRightTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onHandRightBackTouched);

    functionName("onHandLeftBackTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onHandLeftBackTouched);
    functionName("onHandLeftLeftTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onHandLeftLeftTouched);
    functionName("onHandRightBackTouched", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onHandRightBackTouched);

    functionName("onBodyStiffnessChanged", getName(), "Method called when the event raises.");
    BIND_METHOD(SensorListener::onBodyStiffnessChanged);
}

SensorListener::~SensorListener() {
    fMemoryProxy.unsubscribeToEvent("RightBumperPressed", "SensorListener");
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
        fMemoryProxy.subscribeToEvent("RightBumperPressed", getName(),"onRightBumperPressed");
        fMemoryProxy.subscribeToEvent("LeftBumperPressed", getName(),"onLeftBumperPressed");
        fMemoryProxy.subscribeToEvent("ChestButtonPressed", getName(),"onChestButtonPressed");

        fMemoryProxy.subscribeToEvent("FrontTactilTouched", getName(),"onFrontTactilTouched");
        fMemoryProxy.subscribeToEvent("MiddleTactilTouched", getName(),"onMiddleTactilTouched");
        fMemoryProxy.subscribeToEvent("RearTactilTouched", getName(),"onRearTactilTouched");
        fMemoryProxy.subscribeToEvent("HotJoinedDetected", getName(),"onHotJoinedDetected");

        fMemoryProxy.subscribeToEvent("HandRightBackTouched", getName(),"onHandRightBackTouched");
        fMemoryProxy.subscribeToEvent("HandRightLeftTouched", getName(),"onHandRightLeftTouched");
        fMemoryProxy.subscribeToEvent("HandRightRightTouched", getName(),"onHandRightRightTouched");

        fMemoryProxy.subscribeToEvent("HandLeftBackTouched", getName(),"onHandLeftBackTouched");
        fMemoryProxy.subscribeToEvent("HandLeftLeftTouched", getName(),"onHandLeftLeftTouched");
        fMemoryProxy.subscribeToEvent("HandLeftRightTouched", getName(),"onHandLeftRightTouched");

        fMemoryProxy.subscribeToEvent("BodyStiffnessChanged", getName(),"onBodyStiffnessChanged");

    }
    catch (const AL::ALError& e) {
        qiLogError("module.example") << e.what() << std::endl;
    }
}


void SensorListener::onRightBumperPressed() {
    qiLogInfo("module.example") << "Executing callback method on right bumper event" << std::endl;
}


void SensorListener::onLeftBumperPressed(){
    qiLogInfo("module.example") << "onLeftBumperPressed" << std::endl;
}

void SensorListener::onChestButtonPressed(){
    qiLogInfo("module.example") << "onChestButtonPressed" << std::endl;
}

void SensorListener::onFrontTactilTouched(){
    qiLogInfo("module.example") << "onFrontTactilTouched" << std::endl;
}

void SensorListener::onMiddleTactilTouched(){
    qiLogInfo("module.example") << "onMiddleTactilTouched" << std::endl;
}

void SensorListener::onRearTactilTouched(){
    qiLogInfo("module.example") << "onRearTactilTouched" << std::endl;
}

void SensorListener::onHotJoinedDetected(){
    qiLogInfo("module.example") << "onHotJoinedDetected" << std::endl;
}

void SensorListener::onHandRightBackTouched(){
    qiLogInfo("module.example") << "onHandRightBackTouched" << std::endl;
}

void SensorListener::onHandRightLeftTouched(){
    qiLogInfo("module.example") << "onHandRightLeftTouched" << std::endl;
}

void SensorListener::onHandRightRightTouched(){
    qiLogInfo("module.example") << "onHandRightRightTouched"<<std::endl;
}

void SensorListener::onHandLeftBackTouched(){
    qiLogInfo("module.example") << "onHandLeftBackTouched"<<std::endl;
}

void SensorListener::onHandLeftLeftTouched(){
    qiLogInfo("module.example") << "onHandLeftLeftTouched"<<std::endl;
}

void SensorListener::onHandLeftRightTouched(){
    qiLogInfo("module.example") << "onHandLeftRightTouched"<<std::endl;
}

void SensorListener::onBodyStiffnessChanged(){
    qiLogInfo("module.example") << "onBodyStiffnessChanged"<<std::endl;
}

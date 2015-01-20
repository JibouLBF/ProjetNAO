#ifndef SENSORLISTENER_H
#define SENSORLISTENER_H

#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>
#include <string>

#include <alproxies/almemoryproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <althread/almutex.h>

namespace AL
{
class ALBroker;
}

class SensorListener :  public AL::ALModule
{
public:
    SensorListener(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

    virtual ~SensorListener();

    /** Overloading ALModule::init().
     * This is called right after the module has been loaded
     */
    void init();

    /**
     * These methods will be called every time the event is raised.
     */
    void virtual onRightBumperPressed();
    void virtual onLeftBumperPressed();
    void virtual onChestButtonPressed();
    void virtual onFrontTactilTouched();
    void virtual onMiddleTactilTouched();
    void virtual onRearTactilTouched();
    void virtual onHotJoinedDetected();
    void virtual onHandRightBackTouched();
    void virtual onHandRightLeftTouched();
    void virtual onHandRightRightTouched();
    void virtual onHandLeftBackTouched();
    void virtual onHandLeftLeftTouched();
    void virtual onHandLeftRightTouched();
    void virtual onBodyStiffnessChanged();

private :
    boost::shared_ptr<AL::ALBroker> makeLocalBroker(const std::string parentBrokerIP, int parentBrokerPort);

protected:
    AL::ALMemoryProxy fMemoryProxy;
    AL::ALTextToSpeechProxy fTtsProxy;
    boost::shared_ptr<AL::ALMutex> fCallbackMutex;
    float fState;

};

#endif // SENSORLISTENER_H

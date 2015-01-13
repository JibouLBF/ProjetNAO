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
     virtual void init();

     /**
     * This method will be called every time the event RightBumperPressed is raised.
     */
     void onRightBumperPressed();

private:
     AL::ALMemoryProxy fMemoryProxy;
     AL::ALTextToSpeechProxy fTtsProxy;

     boost::shared_ptr<AL::ALMutex> fCallbackMutex;

     float fState;

};

#endif // SENSORLISTENER_H

#ifndef SENSORLISTENER_H
#define SENSORLISTENER_H

#include <alcommon/almodule.h>
#include <string>
#include <alproxies/almemoryproxy.h>

namespace AL
{
  class ALBroker;
}

class SensorListener
{
public:
    SensorListener(std::string name);
    virtual void actionToDo() = 0;
protected:
    AL::ALMemoryProxy fMemoryProxy;
    std::string eventName;
    float sensorValue;


};

#endif // SENSORLISTENER_H

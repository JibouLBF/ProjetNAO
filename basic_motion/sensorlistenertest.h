#ifndef SENSORLISTENERTEST_H
#define SENSORLISTENERTEST_H
#include <string.h>

#include "sensorlistener.h"

#include <alproxies/almemoryproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <althread/almutex.h>

class SensorListenerTest : public SensorListener
{
public:
    SensorListenerTest(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);
    void onRightBumperPressed();
    void onMiddleTactilTouched();
};

#endif // SENSORLISTENERTEST_H

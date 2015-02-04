#ifndef COMMON_H
#define COMMON_H

#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <alproxies/alledsproxy.h>
#include <alproxies/alaudiosourcelocalizationproxy.h>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/almemoryproxy.h>
#include <boost/shared_ptr.hpp>
#include <alcommon/albroker.h>
#include <alcommon/almodule.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>

#include <string.h>
#include "scheduler.h"


class Common
{
public:
    static AL::ALMotionProxy* basicMotionProxy;
    static AL::ALRobotPostureProxy* postureProxy;
    static AL::ALLedsProxy* ledsProxy;
    static AL::ALAudioSourceLocalizationProxy* soundLocProxy;
    static AL::ALTextToSpeechProxy* fTtsProxy;
    static Scheduler scheduler;

    static boost::shared_ptr<AL::ALBroker> makeLocalBroker(const std::string parentBrokerIP, int parentBrokerPort);
    static void initProxy(std::string ip, int port);
private:
    static void createLedsGroup();

};

#endif // COMMON_H

#ifndef COMMON_H
#define COMMON_H

#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <boost/shared_ptr.hpp>
#include <alcommon/albroker.h>
#include <alcommon/almodule.h>
#include <alcommon/albrokermanager.h>
#include <alcommon/altoolsmain.h>
#include <string.h>


class Common
{
public:
    static AL::ALMotionProxy* basicMotionProxy;
    static AL::ALRobotPostureProxy* postureProxy;

    static boost::shared_ptr<AL::ALBroker> makeLocalBroker(const std::string parentBrokerIP, int parentBrokerPort);
    static void initProxy(std::string ip, int port);

};

#endif // COMMON_H

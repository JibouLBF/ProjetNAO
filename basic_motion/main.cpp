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
#include "sensorlistenertest.h"

boost::shared_ptr<AL::ALBroker> makeLocalBroker(const std::string parentBrokerIP, int parentBrokerPort) {
    // Name, IP and port of our local broker that talks to NAO's broker:
    const std::string brokerName = "localbroker";
    int brokerPort = 54000;   // FIXME: would be a good idea to look for a free port first
    const std::string brokerIp   = "0.0.0.0";  // listen to anything
    try {
        boost::shared_ptr<AL::ALBroker> broker = AL::ALBroker::createBroker(
                    brokerName,
                    brokerIp,
                    brokerPort,
                    parentBrokerIP,
                    parentBrokerPort,
                    0    // you can pass various options for the broker creation, but default is fine
                    );
        // ALBrokerManager is a singleton class (only one instance).
        AL::ALBrokerManager::setInstance(broker->fBrokerManager.lock());
        AL::ALBrokerManager::getInstance()->addBroker(broker);
        return broker;
    } catch(const AL::ALError& /* e */) {
        std::cerr << "Faild to connect broker to: " << parentBrokerIP << ":" << parentBrokerPort << std::endl;
        AL::ALBrokerManager::getInstance()->killAllBroker();
        AL::ALBrokerManager::kill();
        exit(2);
    }
}
int main(int argc, char* argv[])
{
    std::cout << "Hello, world" << std::endl;

    try {
        boost::shared_ptr<AL::ALBroker> broker = makeLocalBroker("192.168.0.1", 9559);
        AL::ALModule::createModule<SensorListenerTest>(broker, "SensorListenerTest");

        Motion::initProxy("192.168.0.1", 9559);

        /*  Motion* bm = new Stand();
        bm->relax();*/

        /*AL::ALValue jointName = "HeadYaw";
        AL::ALValue targetAngles = AL::ALValue::array(-1.5f, 1.5f, 0.0f);
        AL::ALValue targetTimes = AL::ALValue::array(3.0f, 6.0f, 9.0f);
        bool isAbsolute = true;
        Motion* bm = new Head(jointName,targetAngles, targetTimes, isAbsolute);
        bm->action();*/
        while(1){}
    }
    catch (const AL::ALError& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
        return(1);
    }

    return 0;
}

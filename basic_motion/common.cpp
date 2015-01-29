#include "common.h"

AL::ALMotionProxy* Common::basicMotionProxy = NULL;
AL::ALRobotPostureProxy* Common::postureProxy = NULL;

void Common::initProxy(std::string ip, int port){
    basicMotionProxy = new AL::ALMotionProxy (ip, port);
    postureProxy = new AL::ALRobotPostureProxy (ip, port);
}

boost::shared_ptr<AL::ALBroker> Common::makeLocalBroker(const std::string parentBrokerIP, int parentBrokerPort) {
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

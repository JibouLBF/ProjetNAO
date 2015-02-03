#include "common.h"

AL::ALMotionProxy* Common::basicMotionProxy = NULL;
AL::ALRobotPostureProxy* Common::postureProxy = NULL;
AL::ALLedsProxy* Common::ledsProxy = NULL;
Scheduler Common::scheduler;

void Common::initProxy(std::string ip, int port){
    basicMotionProxy = new AL::ALMotionProxy (ip, port);
    postureProxy = new AL::ALRobotPostureProxy (ip, port);
    ledsProxy = new AL::ALLedsProxy (ip, port);
    createLedsGroup();
    scheduler = Scheduler();
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

void Common::createLedsGroup(){
    std::vector<std::string> names;

    names.push_back("RightFaceLed8");
    names.push_back("RightFaceLed7");
    names.push_back("RightFaceLed6");
    names.push_back("RightFaceLed5");
    names.push_back("RightFaceLed4");
    names.push_back("RightFaceLed3");
    names.push_back("RightFaceLed2");
    names.push_back("RightFaceLed1");
    ledsProxy->createGroup("RightEyeLeds",names);

    names.clear();
    names.push_back("LeftFaceLed8");
    names.push_back("LeftFaceLed7");
    names.push_back("LeftFaceLed6");
    names.push_back("LeftFaceLed5");
    names.push_back("LeftFaceLed4");
    names.push_back("LeftFaceLed3");
    names.push_back("LeftFaceLed2");
    names.push_back("LeftFaceLed1");
    ledsProxy->createGroup("LeftEyeLeds",names);

    names.clear();
    names.push_back("RightEarLed10");
    names.push_back("RightEarLed9");
    names.push_back("RightEarLed8");
    names.push_back("RightEarLed7");
    names.push_back("RightEarLed6");
    names.push_back("RightEarLed5");
    names.push_back("RightEarLed4");
    names.push_back("RightEarLed3");
    names.push_back("RightEarLed2");
    names.push_back("RightEarLed1");
    ledsProxy->createGroup("RightEarLeds",names);

    names.clear();
    names.push_back("LeftEarLed10");
    names.push_back("LeftEarLed9");
    names.push_back("LeftEarLed8");
    names.push_back("LeftEarLed7");
    names.push_back("LeftEarLed6");
    names.push_back("LeftEarLed5");
    names.push_back("LeftEarLed4");
    names.push_back("LeftEarLed3");
    names.push_back("LeftEarLed2");
    names.push_back("LeftEarLed1");
    ledsProxy->createGroup("LeftEarLeds",names);
}

#include "sounddetectionlistenertest.h"


SoundDetectionListenerTest::SoundDetectionListenerTest(boost::shared_ptr<ALBroker> broker,const std::string& name):
    SoundDetectionListener(broker, name)
{
}

#ifndef SOUNDDETECTIONLISTENERTEST_H
#define SOUNDDETECTIONLISTENERTEST_H
#include "sounddetectionlistener.h"

class SoundDetectionListenerTest : public SoundDetectionListener
{
public:
    SoundDetectionListenerTest(boost::shared_ptr<ALBroker> broker,const std::string& name);

};

#endif // SOUNDDETECTIONLISTENERTEST_H

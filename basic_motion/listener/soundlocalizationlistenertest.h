#ifndef SOUNDLOCALIZATIONLISTENERTEST_H
#define SOUNDLOCALIZATIONLISTENERTEST_H

#include "soundlocalizationlistener.h"
#include <althread/alcriticalsection.h>
#include "../motion/basicmotion/head.h"
#include <althread/almutex.h>

class SoundLocalizationListenerTest : public SoundLocalizationListener
{
public:
    SoundLocalizationListenerTest(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);
    void onSoundDetected();
private:
    Head* head;
    /** Mutex to make the callback function thread-safe. */
    boost::shared_ptr<AL::ALMutex> fCallbackMutex;
};

#endif // SOUNDLOCALIZATIONLISTENERTEST_H

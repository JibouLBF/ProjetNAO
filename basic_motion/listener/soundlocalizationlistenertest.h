#ifndef SOUNDLOCALIZATIONLISTENERTEST_H
#define SOUNDLOCALIZATIONLISTENERTEST_H

#include "soundlocalizationlistener.h"
#include <althread/alcriticalsection.h>
#include <althread/almutex.h>
#include "../motion/basicmotion/head.h"


class SoundLocalizationListenerTest : public SoundLocalizationListener
{
public:
    SoundLocalizationListenerTest(boost::shared_ptr<AL::ALBroker> broker, const std::string& name);

    /**
     * Method called each time a sound is detected.
     * This implementation move the robot's head in the noise direction.
     */
    void onSoundDetected();
private:
    Head* head;
    int count;
    /** Mutex to make the callback function thread-safe. */
    boost::shared_ptr<AL::ALMutex> fCallbackMutex;
};

#endif // SOUNDLOCALIZATIONLISTENERTEST_H

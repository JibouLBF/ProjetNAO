#ifndef SOUNDLOCALIZATIONLISTENER_H
#define SOUNDLOCALIZATIONLISTENER_H

#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>
#include <string>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/alaudiosourcelocalizationproxy.h>
#include <alproxies/almemoryproxy.h>
#include <althread/alcriticalsection.h>
#include "head.h"
#include <althread/almutex.h>


using namespace AL;

class SoundLocalizationListener : public ALModule
{
public:

  SoundLocalizationListener(boost::shared_ptr<ALBroker> broker, const std::string & name);
  ~SoundLocalizationListener();

  void init();
  void onSoundDetected();

private:
  ALTextToSpeechProxy fProxyToTextToSpeech;
  ALMemoryProxy fMemoryProxy;
  Head* head;
  /** Mutex to make the callback function thread-safe. */
  boost::shared_ptr<AL::ALMutex> fCallbackMutex;
};

#endif // SOUNDLOCALIZATIONLISTENER_H

#ifndef SOUNDLOCALIZATIONLISTENER_H
#define SOUNDLOCALIZATIONLISTENER_H

#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>
#include <string>
#include <alproxies/altexttospeechproxy.h>
#include <alproxies/alaudiosourcelocalizationproxy.h>
#include <alproxies/almemoryproxy.h>
#include "head.h"


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
};

#endif // SOUNDLOCALIZATIONLISTENER_H

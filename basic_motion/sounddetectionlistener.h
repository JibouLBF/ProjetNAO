#ifndef SOUNDDETECTIONLISTENER_H
#define SOUNDDETECTIONLISTENER_H

#include <boost/shared_ptr.hpp>
#include <alcommon/almodule.h>
#include <string>
#include <alproxies/altexttospeechproxy.h>
#include "alaudio/alsoundextractor.h"
#include <alproxies/almemoryproxy.h>

using namespace AL;

class SoundDetectionListener : public ALSoundExtractor
{
public:

  SoundDetectionListener(boost::shared_ptr<ALBroker> broker,
                       const std::string & name);
  virtual ~SoundDetectionListener();

  void init();

  virtual void process(const int & nbOfChannels,
               const int & nbrOfSamplesByChannel,
               const AL_SOUND_FORMAT * buffer,
               const ALValue & timeStamp);

private:
  ALTextToSpeechProxy fProxyToTextToSpeech;
  ALMemoryProxy fMemoryProxy;
};

#endif // SOUNDDETECTIONLISTENER_H


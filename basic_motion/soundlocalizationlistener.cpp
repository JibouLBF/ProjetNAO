#include "soundlocalizationlistener.h"

#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>
#include <alproxies/alaudiosourcelocalizationproxy.h>
#include <althread/alcriticalsection.h>
#include <althread/almutex.h>

#include <iostream>
#include <fstream>
#include "common.h"

SoundLocalizationListener::SoundLocalizationListener(boost::shared_ptr<ALBroker> broker,
                                           const std::string& name) :
  ALModule(broker, name),  fCallbackMutex(AL::ALMutex::createALMutex())
{

  fMemoryProxy = AL::ALMemoryProxy(getParentBroker());
  head = new Head();
  AL::ALValue joints = AL::ALValue::array("HeadPitch","HeadYaw");
  head->setMotionName(joints);
  AL::ALValue targetTimes =AL::ALValue::array( AL::ALValue::array(1.0f), AL::ALValue::array(1.0f));
  head->setTimeList(targetTimes);
  head->setIsAbsolute(false);

  /// This line will display a description of this module on the web page of the robot
  setModuleDescription("This module launch a texttospeech command when a "
                       "sudden and significative noise is heard.");
  functionName("onSoundDetected", getName(), "");
  BIND_METHOD(SoundLocalizationListener::onSoundDetected);

}

void SoundLocalizationListener::init()
{
    std::cout << "EST CE QUE CA MARCHE" << std::endl;
  /// Setting up the appropriate language
  fProxyToTextToSpeech.setLanguage("French");
  fMemoryProxy.subscribeToEvent("ALAudioSourceLocalization/SoundLocated",getName(),"onSoundDetected");
}

SoundLocalizationListener::~SoundLocalizationListener()
{
}

void SoundLocalizationListener::onSoundDetected()
{
  AL::ALCriticalSection section(fCallbackMutex);
  AL::ALValue value = fMemoryProxy.getData("ALAudioSourceLocalization/SoundLocated");
  float confidence = value[1][2];
  float azimuth = value[1][0];
  float elevation = value[1][1];
  std::cout << elevation << " "  << azimuth << " " << confidence << std::endl;

  /// Launch a texttospeech command when it is appropriate
  if(confidence > 0.5f)
  {

    AL::ALValue targetAngles = AL::ALValue::array(AL::ALValue::array(elevation), AL::ALValue::array(azimuth));
    head->setAngleList(targetAngles);
    head->action();
    Common::soundDetected = true;
    //fProxyToTextToSpeech.say("Hello there!");
  }
}


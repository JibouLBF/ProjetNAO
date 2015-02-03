#include "sounddetectionlistener.h"
#include <alvalue/alvalue.h>
#include <alcommon/alproxy.h>
#include <alcommon/albroker.h>

#include <iostream>
#include <fstream>
#include "head.h"

SoundDetectionListener::SoundDetectionListener(boost::shared_ptr<ALBroker> broker,
                                           const std::string& name) :
  ALSoundExtractor(broker, name)
{
  /// This line will display a description of this module on the web page of the robot
  setModuleDescription("This module launch a texttospeech command when a "
                       "sudden and significative noise is heard.");
}

void SoundDetectionListener::init()
{
  /// Setting up the appropriate language
  fProxyToTextToSpeech.setLanguage("English");

  audioDevice->callVoid("setClientPreferences",
                        getName(),                //Name of this module
                        16000,                    //16000 Hz requested
                        (int)FRONTCHANNEL,        //Front Channels requested
                        0                         //Deinterleaving is not needed here
                        );
  fMemoryProxy = AL::ALMemoryProxy(getParentBroker());
  fMemoryProxy.getData("ALAudioSourceLocalization/SoundLocated");

  startDetection();
}

SoundDetectionListener::~SoundDetectionListener()
{
  stopDetection();
}

/// This function will be automatically called by the module ALAudioDevice
/// every 170ms with the appropriate audio buffer (front channel at 16000Hz)
void SoundDetectionListener::process(const int & nbOfChannels,
                                   const int & nbrOfSamplesByChannel,
                                   const AL_SOUND_FORMAT * buffer,
                                   const ALValue & timeStamp)
{
  /// Compute the maximum value of the front microphone signal.
  int maxValueFront = 0;
  for(int i = 0 ; i < nbrOfSamplesByChannel ; i++)
  {
    if(buffer[i] > maxValueFront)
    {
      maxValueFront = buffer[i];
    }
  }

  /// Print it in the console
  /// (Naoqi needs to be launched in console mode to see the log)
  std::cout << "maxvalue : " << maxValueFront << std::endl;

  /// Launch a texttospeech command when it is appropriate
  if(maxValueFront > 10000)
  {
    AL::ALValue fState =  fMemoryProxy.getData("ALAudioSourceLocalization/SoundLocated");
    float azimuth = fState[1][0];
    float elevation = fState[1][1];
    AL::ALValue joints = AL::ALValue::array("HeadPitch","HeadYaw");
    std::cout << elevation << " "  << azimuth << std::endl;

    AL::ALValue targetAngles = AL::ALValue::array(AL::ALValue::array(elevation), AL::ALValue::array(azimuth));
    AL::ALValue targetTimes =AL::ALValue::array( AL::ALValue::array(2.0f), AL::ALValue::array(2.0f));

    Head* head = new Head(joints,targetAngles,targetTimes,false);
    head->action();

    //fProxyToTextToSpeech.say("Hello there!");

  }
}

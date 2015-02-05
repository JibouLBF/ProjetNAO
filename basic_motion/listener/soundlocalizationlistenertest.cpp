#include "soundlocalizationlistenertest.h"
#include "../common/common.h"
#include "../motion/basicmotion/walk.h"

SoundLocalizationListenerTest::SoundLocalizationListenerTest(boost::shared_ptr<AL::ALBroker> broker, const std::string& name):
    SoundLocalizationListener(broker,name) , fCallbackMutex(AL::ALMutex::createALMutex())
{
    head = new Head();
    count = 0;
    AL::ALValue joints = AL::ALValue::array("HeadPitch","HeadYaw");
    head->setMotionName(joints);
    AL::ALValue targetTimes =AL::ALValue::array( AL::ALValue::array(1.0f), AL::ALValue::array(1.0f));
    head->setTimeList(targetTimes);
    head->setIsAbsolute(false);

}

void SoundLocalizationListenerTest::onSoundDetected(){
    AL::ALCriticalSection section(fCallbackMutex);

    AL::ALValue value = Common::fMemoryProxy->getData("ALAudioSourceLocalization/SoundLocated");
    float confidence = value[1][2];
    float azimuth = value[1][0];
    float elevation = value[1][1];
    float headPosition = value [2][5];
    std::cout << elevation << " "  << azimuth << " " << confidence << " " << headPosition  << std::endl;

    /** Move the head in the noise direction */
    if(confidence > 0.9f)
    {
      count ++;
      AL::ALValue targetAngles = AL::ALValue::array(AL::ALValue::array(elevation), AL::ALValue::array(azimuth));
      head->setAngleList(targetAngles);
      head->action();
      if(count == 3){
          Common::fMemoryProxy->unsubscribeToEvent("ALAudioSourceLocalization/SoundLocated",getName());
          head->setAngleList(AL::ALValue::array(0, 0));
          head->setIsAbsolute(true);
          head->action();
          /*Walk w = Walk(0,0,headPosition + azimuth);
          w.action();*/
          Common::soundDetected = true;
          Common::eventRaised = true;
      }
    }

}

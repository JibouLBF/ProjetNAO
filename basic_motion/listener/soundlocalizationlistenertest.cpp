#include "soundlocalizationlistenertest.h"
#include "../common/common.h"

SoundLocalizationListenerTest::SoundLocalizationListenerTest(boost::shared_ptr<AL::ALBroker> broker, const std::string& name):
    SoundLocalizationListener(broker,name) , fCallbackMutex(AL::ALMutex::createALMutex())
{
    head = new Head();
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
    std::cout << elevation << " "  << azimuth << " " << confidence << std::endl;

    /// Launch a texttospeech command when it is appropriate
    if(confidence > 0.5f)
    {
      AL::ALValue targetAngles = AL::ALValue::array(AL::ALValue::array(elevation), AL::ALValue::array(azimuth));
      head->setAngleList(targetAngles);
      head->action();
      Common::soundDetected = true;
      Common::eventRaised = true;
    }
}

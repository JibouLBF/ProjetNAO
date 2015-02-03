#include "leds.h"
#include "common.h"

Leds::Leds(std::string ledName, AL::ALValue colorList, AL::ALValue targetTimes){
    this->ledName = ledName;
    this->colorList = colorList;
    this->targetTimes = targetTimes;
}

void Leds::action(){
    Common::ledsProxy->post.fadeListRGB(ledName, colorList, targetTimes );
}

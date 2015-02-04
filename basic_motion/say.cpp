#include "say.h"
#include "common.h"

Say::Say(std::string textToSay)
{
    this->textToSay = textToSay;
}

void Say::action(){
    Common::fTtsProxy->say(textToSay);
}

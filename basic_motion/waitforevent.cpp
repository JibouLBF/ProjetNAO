#include "waitforevent.h"
#include "common.h"

WaitForEvent::WaitForEvent(bool* event)
{
    this->event = event;
}

void WaitForEvent::action(){
    *event = false;
    while((*event)==false){}
    std::cout << "EVENT RAISED" << std::endl;
   *event = false;
}

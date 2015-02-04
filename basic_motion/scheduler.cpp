#include "scheduler.h"
#include "common.h"

using namespace std;

Scheduler::Scheduler()
{
}

void Scheduler::addEvent(Motion* m){
    eventQueue.push(m);
}

void Scheduler::play(){
    isPaused = false;
    while((!isPaused) && (!eventQueue.empty())){
        Motion* m = eventQueue.front();
        cout << "ACTION EN COURS " << m->getName() << endl;
        m->action();
        cout << "ACTION FINIE" << endl;
        eventQueue.pop();
    }
}

void Scheduler::stop(){
    isPaused = true;
    Common::basicMotionProxy->killAll();
    Common::postureProxy->stopMove();
}


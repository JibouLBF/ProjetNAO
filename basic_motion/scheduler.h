#ifndef SCHEDULER_H
#define SCHEDULER_H

#include<queue>
#include"motion.h"

class Scheduler
{
public:
    Scheduler();
    void addEvent(Motion* m);
    void play();
    void stop();
private:
    std::queue<Motion*> eventQueue;
    bool isPaused;

};

#endif // SCHEDULER_H

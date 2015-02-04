#ifndef WAITFOREVENT_H
#define WAITFOREVENT_H

#include "motion.h"

class WaitForEvent : public Motion
{
public:
    WaitForEvent(bool* event);
    void action();
private:
    bool* event;
};

#endif // WAITFOREVENT_H

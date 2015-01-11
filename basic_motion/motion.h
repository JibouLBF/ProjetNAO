#ifndef MOTION_H
#define MOTION_H

#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>

class Motion
{
public:
    Motion();
    virtual void action ()= 0;
protected:
    AL::ALValue name;
};

#endif // MOTION_H

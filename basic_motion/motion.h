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
    static AL::ALMotionProxy* motion;
    AL::ALValue name;
};

#endif // MOTION_H

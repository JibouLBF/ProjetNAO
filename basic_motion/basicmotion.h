#ifndef BASICMOTION_H
#define BASICMOTION_H
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>
#include <string.h>

class BasicMotion
{
public:
    BasicMotion();
    virtual void action ();
    virtual void actionWhileConcurrency ();

protected:
    static AL::ALMotionProxy* motion;
};

#endif // BASICMOTION_H

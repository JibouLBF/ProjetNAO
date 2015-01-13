#ifndef MOTION_H
#define MOTION_H

#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <string.h>

class Motion
{
public:
    Motion();
    virtual void action ()= 0;
    static void initProxy(std::string ip, int port);
    void relax();

protected:
    AL::ALValue name;
    static AL::ALMotionProxy* basicMotionProxy;
    static AL::ALRobotPostureProxy* postureProxy;


};

#endif // MOTION_H

#ifndef POSTURE_H
#define POSTURE_H

#include <alproxies/alrobotpostureproxy.h>

class Posture
{
public:
    Posture();
    void action();
protected:
    String typeOfPosture;
    static AL::ALRobotPostureProxy* postureProxy;
};

#endif // POSTURE_H

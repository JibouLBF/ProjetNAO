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
    void relax();
    std::string getName();

protected:
    AL::ALValue name;
};

#endif // MOTION_H

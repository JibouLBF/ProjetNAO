#ifndef POSTURE_H
#define POSTURE_H
#include <string.h>
#include <alproxies/alrobotpostureproxy.h>
#include "motion.h"

class Posture : public Motion
{
public:
    Posture();
    void action();
protected:
    std::string typeOfPosture;
};

#endif // POSTURE_H

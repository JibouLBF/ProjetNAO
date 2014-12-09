#ifndef HEAD_H
#define HEAD_H
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>

#include "basicmotion.h"


class Head : public BasicMotion
{
public:
    Head();

private:
    AL::ALValue jointName;
};

#endif // HEAD_H

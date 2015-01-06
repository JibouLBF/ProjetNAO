#ifndef BASICMOTION_H
#define BASICMOTION_H
#include <iostream>
#include <alerror/alerror.h>
#include <alproxies/almotionproxy.h>
#include <alproxies/alrobotpostureproxy.h>
#include <unistd.h>
#include <string.h>

#include "motion.h"

class BasicMotion : public Motion
{
public:
    BasicMotion();

    AL::ALValue getMotionName() const;
    void setMotionName(const AL::ALValue &value);

    AL::ALValue getAngleList() const;
    void setAngleList(const AL::ALValue &value);

    AL::ALValue getTimeList() const;
    void setTimeList(const AL::ALValue &value);

    AL::ALValue getStiffness() const;
    void setStiffness(const AL::ALValue &value);

    bool getIsAbsolute() const;
    void setIsAbsolute(bool value);

    void action();

protected:
    /** The name of the joint to be moved. */
    AL::ALValue motionName;
    /** Set the target angle list, in radians. */
    AL::ALValue angleList;
    /** Set the corresponding time lists, in seconds. */
    AL::ALValue timeList;
    /** Target stiffness. */
    AL::ALValue stiffness;
    /** Specify that the desired angles are absolute. */
    bool isAbsolute;

    static AL::ALMotionProxy* basicMotionProxy;

};

#endif // BASICMOTION_H

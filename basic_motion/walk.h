#ifndef WALK_H
#define WALK_H

#include "motion.h"

class Walk : public Motion
{
public:
    Walk(float x, float y, float z);
    void action();

protected:
    float x,y,z;

};

#endif // WALK_H

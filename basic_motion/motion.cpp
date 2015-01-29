#include "motion.h"
#include "common.h"

Motion::Motion()
{
    //this->name= name;
}


void Motion::relax(){
    Common::basicMotionProxy->rest();
}

void Motion::moveTo(int x, int y, int z){
    Common::basicMotionProxy->move(x, y, z);
}

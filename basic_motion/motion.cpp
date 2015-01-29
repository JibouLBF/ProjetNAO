#include "motion.h"
#include "common.h"

using namespace std;

Motion::Motion()
{
    //this->name= name;
}


void Motion::relax(){
    Common::basicMotionProxy->rest();
}

string Motion::getName(){
    return name;
}

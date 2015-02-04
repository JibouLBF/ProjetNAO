#ifndef SAY_H
#define SAY_H

#include "motion.h"

class Say : public Motion
{
public:
    Say(std::string textToSay);
    void action();
private:
    std::string textToSay;
};

#endif // SAY_H

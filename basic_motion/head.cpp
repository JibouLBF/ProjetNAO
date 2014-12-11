#include <iostream>
#include "head.h"

Head::Head()
{
    std::cout << "Head" << std::endl;
}

void BasicMotion::action(){
    std::cout << "action" << std::endl;

}

void BasicMotion::actionWhileConcurrency(){
    std::cout << "actionWhileConcurrency" << std::endl;
}

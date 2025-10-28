#ifndef  WALKIETALKIE_H
#define  WALKIETALKIE_H

#include <string>
#include "Mediator.h"

using namespace std;

class WalkieTalkie{
    public:
    void delegate(Request* task);
};

#endif
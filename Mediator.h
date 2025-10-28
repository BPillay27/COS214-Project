#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <string>
#include "Request.h"

using namespace std;
class Employee;

class Mediator{

    protected:
    Employee* root;

    public:
    virtual void attachRoot(Employee* root);
    virtual void delegate(Request* task);
};

#endif
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <queue>
#include "Request.h"

using namespace std;

class Mediator;

class Employee{
    protected:
    queue<string> names;
    bool isAvailable;
    Employee* next;
    
    public:
    Employee();
    virtual ~Employee();

    virtual void handle(Request* task);
    virtual void update(Request* request);
    virtual void available();
    virtual void unavailable();
    virtual void setNext(Employee* next);
    
};

#endif
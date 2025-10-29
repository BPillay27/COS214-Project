#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <queue>
#include "Request.h"

using namespace std;

struct EmployeePerson {
    string name;
    bool isAvailable;
    
    EmployeePerson(string n) : name(n), isAvailable(true) {}
};

class Employee{
    protected:
    queue<EmployeePerson> employees;
    Employee* next;
    
    public:
    Employee();
    virtual ~Employee();
    virtual void handle(Request* task);
    virtual void setNext(Employee* next);
    
};

#endif
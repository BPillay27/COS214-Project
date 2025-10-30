#include "Employee.h"

Employee::Employee()
{
    next = nullptr;
}

Employee::~Employee()
{
    //default destructor
}

void Employee::handle(Request* task)
{
    //virtual function
}

void Employee::setNext(Employee* next)
{
    this->next = next;
}

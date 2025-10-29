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

}

void Employee::setNext(Employee* next)
{
    this->next = next;
}

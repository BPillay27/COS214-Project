#include "Employee.h"

/**
 * @details Default constructor for the Employee class
 * Initializes the next handler in the chain to nullptr
 */
Employee::Employee()
{
    next = nullptr;
}

/**
 * @details Destructor for the Employee class
 */
Employee::~Employee()
{
    //default destructor
}

/**
 * @details Virtual method for handling requests
 * To be overridden by concrete employee types to implement specific request handling logic
 * @param task The request to handle
 */
void Employee::handle(Requests* task)
{
    //virtual function
}

/**
 * @details Sets the next handler in the chain of responsibility
 * @param next Pointer to the next Employee handler in the chain
 */
void Employee::setNext(Employee* next)
{
    this->next = next;
}

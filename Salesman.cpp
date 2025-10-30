#include "Salesman.h"

/**
 * @details Constructor for the Salesman class
 * constructor that initializes the queue with 5 default salesman employees
 */
Salesman::Salesman() : Employee()
{
    for(int i = 1; i <= 5; i++)
    {
        employees.push(EmployeePerson("salesman" + to_string(i)));
    }
}

/**
 * @details Handles sales-related requests
 * @param task The request to handle
 */
void Salesman::handle(Requests* task)
{
    //currently there are no requests that the salesman can handle
    //pass onto the next handler
    if(next != nullptr)
    {
        next->handle(task);
    }
}

/**
 * @details Hires a new salesman by adding new employee to the queue
 * @param name The name of the new salesman
 */
void Salesman::HireSalesman(string name)
{
    employees.push(EmployeePerson(name));
}

/**
 * @details Updates the salesman queue by moving the front salesman to the back of the queue
 */
void Salesman::updateQueue()
{
    if(!employees.empty())
    {
        EmployeePerson current = employees.front();
        employees.pop();
        employees.push(current);
    }
}

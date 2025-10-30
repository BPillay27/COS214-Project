/**
 * @file Employee.h
 * @defgroup EmployeeCOR
 * @brief Employee Chain of Responsibility pattern.
 * @author Arran Lamond
 * @date October 2025
 */

/**
 * @struct EmployeePerson
 * @ingroup Chain
 * @brief Structure representing an individual employee person.
 * @author Arran Lamond
 * @date October 2025
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <queue>
#include "Request.h"

using namespace std;

struct EmployeePerson {
    string name; ///< The name of the employee
    bool isAvailable; ///< The availability status of the employee
    
    /**
     * @brief Constructor for EmployeePerson
     * @param n The name of the employee
     */
    EmployeePerson(string n) : name(n), isAvailable(true) {}
};

/**
 * @class Employee
 * @ingroup EmployeeCOR
 * @brief Abstract handler class in the Chain of Responsibility pattern
 * @author Arran Lamond
 * @date October 2025
 */
class Employee{
    protected:
    queue<EmployeePerson> employees; ///< Queue of employees of this type
    Employee* next; ///< Pointer to the next handler in the chain
    
    public:
    /**
     * @brief Default constructor for Employee
     */
    Employee();
    
    /**
     * @brief Virtual destructor for Employee
     */
    virtual ~Employee();
    
    /**
     * @brief Handle a request in the chain
     * @param task The request to handle
     * Virtual method to be overridden by concrete employee types
     */
    virtual void handle(Requests* task);
    
    /**
     * @brief Set the next handler in the chain
     * @param next Pointer to the next Employee handler
     */
    virtual void setNext(Employee* next);
    
};

#endif
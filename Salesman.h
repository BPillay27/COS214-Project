/**
 * @file Salesman.h
 * @class Salesman
 * @ingroup EmployeeCOR
 * @brief Handler for sales-related requests
 * @author Arran Lamond
 * @date October 2025
 */

#ifndef SALESMAN_H
#define SALESMAN_H

#include <string>
#include "Employee.h"

using namespace std;

class Salesman : public Employee {
    public:
    /**
     * @brief Constructor for Salesman
     * Initializes 5 salesman employees by default
     */
    Salesman();
    
    /**
     * @brief Handle sales-related requests
     * @param task The request to handle
     */
    void handle(Requests* task);
    
    /**
     * @brief Hire a new salesman
     * @param name The name of the new salesman to hire
     * Adds a new EmployeePerson to the salesman queue
     */
    void HireSalesman(string name);
    
    /**
     * @brief Update the salesman queue
     * Rotates the queue by moving the front salesman to the back
     */
    void updateQueue();
};

#endif
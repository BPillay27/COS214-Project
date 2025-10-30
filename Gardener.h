<<<<<<< HEAD
#ifndef GARDENER_H
#define GARDENER_H

class Gardener {
    // Intentionally empty for now
};

#endif // GARDENER_H
=======
/**
 * @file Gardener.h
 * @class Gardener
 * @ingroup EmployeeCOR
 * @brief Handler for gardening-related requests
 * @author Arran Lamond
 * @date October 2025
 */

#ifndef GARDENER_H
#define GARDENER_H

#include <string>
#include "Employee.h"

using namespace std;

class Gardener : public Employee {
    public:
    /**
     * @brief Constructor for Gardener
     * Initializes 5 gardener employees by default
     */
    Gardener();
    
    /**
     * @brief Handle gardening-related requests
     * @param task The request to handle
     */
    void handle(Requests* task);
    
    /**
     * @brief Hire a new gardener
     * @param name The name of the new gardener to hire
     * Adds a new Employee to the gardener queue
     */
    void HireGardener(string name);
    
    /**
     * @brief Update the gardener queue
     * Rotates the queue by moving the front gardener to the back
     */
    void updateQueue();
};

#endif
>>>>>>> 97a76819fd95c2d82e754bed2ee80657500dc9d4

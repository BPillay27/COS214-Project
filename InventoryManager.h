/**
 * @file InventoryManager.h
 * @class InventoryManager
 * @ingroup EmployeeCOR
 * @brief Handler for inventory-related requests.
 * @author Arran Lamond
 * @date October 2025
 */

#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <string>
#include "Employee.h"

using namespace std;

class InventoryManager : public Employee{
    public:
    /**
     * @brief Constructor for InventoryManager
     * Initializes 5 inventory manager employees by default
     */
    InventoryManager();
    
    /**
     * @brief Handle inventory-related requests
     * @param task The request to handle
     */
    void handle(Requests* task);
    
    /**
     * @brief Hire a new inventory manager
     * @param name The name of the new inventory manager to hire
     * Adds a new Employee to the inventory manager queue
     */
    void HireInventoryManager(string name);
    
    /**
     * @brief Update the inventory manager queue
     * Rotates the queue by moving the front manager to the back
     */
    void updateQueue();
};

#endif
#include "InventoryManager.h"

/**
 * @details Constructor for the InventoryManager class
 * constructor initializes the queue with 5 default inventory manager employees
 */
InventoryManager::InventoryManager() : Employee()
{
    for(int i = 1; i <= 5; i++)
    {
        employees.push(EmployeePerson("inventorymanager" + to_string(i)));
    }
}

/**
 * @details Handles inventory-related requests
 * @param task The request to handle
 */
void InventoryManager::handle(Requests* task)
{
    //currently still no requests
    //pass to next handler
    if(next != nullptr)
    {
        next->handle(task);
    }
}

/**
 * @details Hires a new inventory manager by adding a new EmployeePerson to the queue
 * @param name The name of the new inventory manager
 */
void InventoryManager::HireInventoryManager(string name)
{
    employees.push(EmployeePerson(name));
}

/**
 * @details Updates the inventory manager queue by moving the front manager to the back of the queue
 */
void InventoryManager::updateQueue()
{
    if(!employees.empty())
    {
        EmployeePerson current = employees.front();
        employees.pop();
        employees.push(current);
    }
}

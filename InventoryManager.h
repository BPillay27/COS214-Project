#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H

#include <string>
#include "Employee.h"

using namespace std;

class InventoryManager : public Employee{
    public:
    InventoryManager();
    void handle(Request* task);
    void HireInventoryManager(string name);
    void update(Request* request);
};

#endif
#ifndef INVENTORY_H
#define INVENTORY_H

#include "Nursery.h"
#include "Supplier.h"
#include "Request.h"
#include <map>
#include "InventoryManager.h"
/**
 * @file Inventory.h
 * @class Inventory
 * @brief Singleton class that manages the inventory of plants in the nursery.
 * It handles adding and removing plants from the nursery and storage,
 * as well as notifying the InventoryManager of requests.
 */
class Inventory {
    private: 
        Nursery * activePlants;
        // int balance;
        vector<Plant*> storageRoom;
        map<string, Supplier*> suppliers;
        InventoryManager * observer;
        void initSuppliers(map<string, Supplier*> & suppliers);
    protected:
        Inventory();
        ~Inventory();
        Inventory & operator=(Inventory & other);
    public: 
        static Inventory & instance();
        // int getBalance();
        // void addBalance(int Balance);
        bool moveToNursery(Plant * plant);
        void removeFromNursery(Plant * plant);
        void addToStorage(Plant * plant);
        Nursery * getSalesArea();
        void supply(Plant * plant);
        void notify(Requests * request);
        void setManager(InventoryManager * manager);
};

#endif
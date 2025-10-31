#ifndef INVENTORY_H
#define INVENTORY_H

#include "Nursery.h"
#include "Supplier.h"
#include <map>
// #include "InventoryManager"
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
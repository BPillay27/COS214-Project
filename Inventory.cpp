#include "Inventory.h"

Inventory & Inventory::instance() {
    static Inventory singy;
    return singy;
}

Inventory::Inventory() {
    activePlants = new Nursery(50);
    storageRoom = vector<Plant*>();
    suppliers = map<string, Supplier*>();
    initSuppliers(suppliers);
    // balance = 0;
    // observer = new InventoryManager();
}

void Inventory::initSuppliers(map<string, Supplier*> & suppliers) {
    suppliers["Rose"] = new RoseSupplier();
    suppliers["AppleTree"] = new AppleSupplier();
    suppliers["Dandelion"] = new DandelionSupplier();
}

Inventory::~Inventory() {
    delete activePlants;
    for (auto plant : storageRoom) {
        delete plant;
    }
    
    for (auto& pair : suppliers) {
        delete pair.second;
    }
    // delete observer;
}

// int Inventory::getBalance() {
//     return balance;
// }

// void Inventory::addBalance(int Balance) {
//     balance += Balance;
// }

bool Inventory::moveToNursery(Plant * plant) {
    if(activePlants->space()) {
        if (activePlants->addPlant(plant)) {
            auto it = std::find(storageRoom.begin(), storageRoom.end(), plant);
            if (it != storageRoom.end()) {
                storageRoom.erase(it);
                return true;
            }
        }
    }
    return false;
} 

void Inventory::removeFromNursery(Plant * plant) {
    activePlants->removePlant(plant);
}

void Inventory::addToStorage(Plant * plant) {
    storageRoom.push_back(plant);
}

Nursery * Inventory::getSalesArea() {
    return activePlants;
}

void Inventory::supply(Plant * plant) {
    std::string species = plant->getSpecies();
    auto it = suppliers.find(species);
    if (it != suppliers.end()) {
        Plant* newPlant = it->second->resupply();
        if(moveToNursery(newPlant)) {
            return;
        }
        storageRoom.push_back(newPlant);
    }
}



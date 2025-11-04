#include "Inventory.h"

/**
 * @brief Gets the singleton instance of the Inventory class.
 * @return Reference to the singleton Inventory instance.
 */
Inventory & Inventory::instance() {
    static Inventory singy;
    return singy;
}
/**
 * @brief Constructor for the Inventory class.
 */

Inventory::Inventory():Subject() {
    activePlants = new Nursery(50);
    storageRoom = vector<Plant*>();
    suppliers = map<string, Supplier*>();
    initSuppliers(suppliers);
    // balance = 0;
    // observer = new InventoryManager();
}
/**
 * @brief Initializes the suppliers map with specific plant suppliers.
 * @param suppliers Reference to the suppliers map to be initialized.
 */

void Inventory::initSuppliers(map<string, Supplier*> & suppliers) {
    suppliers["Rose"] = new RoseSupplier();
    suppliers["Apple tree"] = new AppleSupplier();
    suppliers["Dandelion"] = new DandelionSupplier();
}
/**
 * @brief Destructor for the Inventory class.
 */
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

/**
 * @brief Moves a plant from storage to the nursery if there is space.
 * @param plant Pointer to the Plant object to be moved.
 * @return true if the plant was successfully moved, false otherwise.
 */
bool Inventory::moveToNursery(Plant * plant) {
    if(activePlants->space()) {
        if (activePlants->addPlant(plant)) {
            auto it = std::find(storageRoom.begin(), storageRoom.end(), plant);
            if (it != storageRoom.end()) {
                storageRoom.erase(it);
            }
            return true;
        }
    }
    return false;
} 
/**
 * @brief Removes a plant from the nursery.
 * @param plant Pointer to the Plant object to be removed.
 */

void Inventory::removeFromNursery(Plant * plant) {
    std::string species = plant->getSpecies();
    activePlants->removePlant(plant);  // This deletes the plant
    std::cout<<"Resupplying a new "<<species<<" to the nursery."<<std::endl;
    auto it = suppliers.find(species);
    if (it != suppliers.end()) {
        Plant* newPlant = it->second->resupply();
        Requests* req=new Place(newPlant);
        notify(req);
        delete req;
        if(storageRoom.size() > 0) {
            Plant* storedPlant = storageRoom.front();
            storageRoom.erase(storageRoom.begin());
            if(moveToNursery(storedPlant)) {
                storageRoom.push_back(newPlant);
            }else {
                storageRoom.push_back(storedPlant);
                storageRoom.push_back(newPlant);
            }
            return;
        }
        if(!moveToNursery(newPlant)) {
            storageRoom.push_back(newPlant);
        }
        // If storageRoom is empty, try to add newPlant to nursery, or store it
        
    }
}
/**
 * @brief Adds a plant to the storage room.
 * @param plant Pointer to the Plant object to be added.
 */
void Inventory::addToStorage(Plant * plant) {
    storageRoom.push_back(plant);
}

/**
 * @brief Gets the nursery's sales area.
 * @return Pointer to the Nursery object representing the sales area.
 */
Nursery * Inventory::getSalesArea() {
    return activePlants;
}

/**
 * @brief Supplies a new plant based on the given plant's species.
 * @param plant Pointer to the Plant object that needs resupplying.
 */
void Inventory::supply(Plant * plant) {
    std::string species = plant->getSpecies();
    auto it = suppliers.find(species);
    if (it != suppliers.end()) {
        Plant* newPlant = it->second->resupply();
        Requests* req=new Place(newPlant);
        notify(req);
        delete req;
        if(moveToNursery(newPlant)) {
            return;
        }
        storageRoom.push_back(newPlant);
    }
}

/**
 * @brief Notifies the InventoryManager of a request.
 * @param request Pointer to the Requests object.
 */

void Inventory::notify(Requests * request) {
    if (observer != nullptr) {
        observer->handle(request);
    }
}

/**
 * @brief Sets the InventoryManager observer for the Inventory.
 * @param manager Pointer to the InventoryManager object.
 */
void Inventory::setManager(InventoryManager * manager) {
    this->observer = manager;
}


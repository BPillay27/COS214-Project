#include "Nursery.h"
#include <iostream>

/**
* @file Nursery.cpp
 * @brief Implementation of the Nursery class that manages a collection of plants.
 * This class provides functionalities to add, remove, and manage plants within the nursery.
 * It also includes helper functions to display plant information.
 * 
 * @author Keegan Lewis
 * @date October 2025
 */
Nursery::Nursery(int capacity){
    greenHouse =new PlantArea(50);
    salesArea = std::vector<Plant*>();
    this->capacity = capacity;
    walk = 0;
    walking = false;
}
/**
* @brief Adds a plant to the green house.
 * @param plant A pointer to the Plant object to be added.
 * @return true if the plant was successfully added, false otherwise.
 */

bool Nursery::addPlant(Plant* plant) {
    if(plant == nullptr) {
        return false;
    }
    return greenHouse->addPlant(plant);
}
/**
* @brief Removes a plant from the nursery.
 * @param plant A pointer to the Plant object to be removed.
 * @return true if the plant was successfully removed, false otherwise.
 */

bool Nursery::removePlant(Plant* plant) {
    if(plant == nullptr) {
        return false;
    }
    greenHouse->removePlant(plant);
    return true;
}

/**
* @brief Destructor for the Nursery class.
* Cleans up dynamically allocated Plant objects.
*/
Nursery::~Nursery() {
    for (Plant* plant : salesArea) {
        delete plant;
    }
    delete greenHouse;
}

/**
* @brief Begins a walkthrough of the nursery, by setting the walk to 0 to show it is at salesArea[0].
*/

void Nursery::WalkThrough() {
    walk = 0;
    walking = true;
}

/**
* @brief Prints the plants that are currently in line of sight during the walkthrough.
* @return a string representation of the plants in line of sight.
*/

std::string Nursery::printPlants() {
    if (!walking) {
        return "You have not entered the Nusery.";
    }
    if(salesArea.empty() || walk >= (int)salesArea.size()) {
        return "No plants available in the sales area.";
    }
    

    std::string result;
    
    for (int plantsInSight = 0; plantsInSight < 5; plantsInSight++) {
        size_t i = walk + plantsInSight;
        if(i >= salesArea.size()) {
            result += plantsInSight+". |--|--|--|--|--|\n";
            continue;
        }else if(salesArea[i] == nullptr) {
            result += plantsInSight+". |--|--|--|--|--|\n";
            continue;
        }else{
            result += plantsInSight+". "+salesArea[i]->getSpecies()+"\n";
        }
    }
    return result;
}

bool Nursery::nextRow() {
    if (!walking) {
        return false;
    }
    if (walk + 5 < (int)salesArea.size()) {
        walk += 5;
        return true;
    } else {
        return false;
    }
}
/**
* @brief Moves to the previous row in the walkthrough.
 * @return true if there are previous rows to walk back to, false if at the beginning.
 */

bool Nursery::prevRow() {
    if (!walking) {
        return false;
    }
    if (walk - 5 >= 0) {
        walk -= 5;
        return true;
    } else {
        return false;
    }
}
/**
* @brief Gets the plant at the specified index in the sales area.
 * @param index The index of the plant to retrieve.
 * @return A pointer to the Plant object at the specified index.
*/

Plant* Nursery::getPlant(int index) {
    if(index<0|| index>5){
        return nullptr;
    }
    if((index+walk) >=(int)salesArea.size()) {
        return nullptr;
    }else{
        return salesArea[(index+walk)];
    }
}


/**
* @brief Provides a list of recommended plants based on the current sales area.
 * @return A vector of strings representing the recommended plant species.
*/
std::vector<string> Nursery::recommendations() {
    std::vector<string> recommendedPlants;

    for (Plant* plant : salesArea) {
        if (plant == nullptr) {
            continue;
        }else if(plant!=nullptr && std::find(recommendedPlants.begin(), recommendedPlants.end(), plant->getSpecies()) == recommendedPlants.end()) {
            recommendedPlants.push_back(plant->getSpecies());
        }    
    }

    return recommendedPlants;
}


/**
* @brief Checks if there is space in the GreenHoes area.
* @return true if there is space, false otherwise.
*/
bool Nursery::space() {
    return (greenHouse->getCount() < greenHouse->getCapacity());
}

/**
* @brief Moves a plant to the sales area.
* @param plant A pointer to the Plant object to be moved.
* @return true if the plant was successfully moved, false otherwise.
*/

bool Nursery::moveToSales(std::string plantType) {
    Plant* plant = greenHouse->givePlant(plantType);
    if (plant != nullptr && (int)salesArea.size() < capacity) {
        salesArea.push_back(plant);
        greenHouse->removePlant(plant);
        return true;
    }else if(plant != nullptr && (int)salesArea.size() >= capacity){
        return false;        
    }else{
        return false;
    }
}

/**
* @brief Grows all plants in the nursery.
 * @return void
*/

void Nursery::grow() {
    greenHouse->grow();
    for (Plant* plant : salesArea) {
        if (plant != nullptr) {
            plant->grow();
        }
    }
}

/**
* @brief Examines all plants in the nursery and prints their details.
*/

void Nursery::examine() {
    greenHouse->examine(true);
    for (Plant* plant : salesArea) {
        if (plant != nullptr) {
            plant->examine(true);
        }
    }
    greenHouse->examine(false);
    for (Plant* plant : salesArea) {
        if (plant != nullptr) {
            plant->examine(false);
        }
    }
}
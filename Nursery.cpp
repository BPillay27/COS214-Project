#include "Nursery.h"
#include <iostream>

Nursery::Nursery(int capacity) : capacity(capacity), walk(0), walking(false) {
    greenHouse = PlantArea(50);
}

bool Nursery::addPlant(Plant* plant) {
    if(plant == nullptr) {
        return false;
    }
    return greenHouse.addPlant(plant);
}

bool Nursery::removePlant(Plant* plant) {
    if(plant == nullptr) {
        return false;
    }
    greenHouse.removePlant(plant);
}

Nursery::~Nursery() {
    for (Plant* plant : salesArea) {
        delete plant;
    }
}

void Nursery::WalkThrough() {
    walk = 0;
    walking = true;
}

std::string Nursery::printPlants() {
    if (!walking) {
        return "You have not entered the Nusery.";
    }
    if(salesArea.empty() || walk >= salesArea.size()) {
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
    if (walk + 5 < salesArea.size()) {
        walk += 5;
        return true;
    } else {
        return false;
    }
}

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

Plant* Nursery::getPlant(int index) {
    if(index<0|| index>5){
        return nullptr;
    }
    if((index+walk) >= salesArea.size()) {
        return nullptr;
    }else{
        return salesArea[(index+walk)];
    }
}

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

bool Nursery::space() {
    return (greenHouse.getCount() < greenHouse.getCapacity());
}

bool Nursery::moveToSales(std::string plantType) {
    Plant* plant = greenHouse.givePlant(plantType);
    if (plant != nullptr && salesArea.size() < capacity) {
        salesArea.push_back(plant);
        greenHouse.removePlant(plant);
        return true;
    }else if(plant != nullptr && salesArea.size() >= capacity){
        return false;        
    }else{
        return false;
    }
}

void Nursery::grow() {
    greenHouse.grow();
    for (Plant* plant : salesArea) {
        if (plant != nullptr) {
            plant->grow();
        }
    }
}

void Nursery::examine() {
    greenHouse.examine(true);
    for (Plant* plant : salesArea) {
        if (plant != nullptr) {
            plant->examine(true);
        }
    }
    greenHouse.examine(false);
    for (Plant* plant : salesArea) {
        if (plant != nullptr) {
            plant->examine(false);
        }
    }
}
#include "Nursery.h"
#include <algorithm>

Nursery::Nursery(int capacity) : capacity(capacity) {}

bool Nursery::addPlant(Plant* plant) {
    if (plants.size() < capacity) {
        plants.push_back(plant);
        return true;
    }
    return false;
}

void Nursery::removePlant(Plant* plant) {
    plants.erase(std::remove(plants.begin(), plants.end(), plant), plants.end());
}

bool Nursery::space() {
    return plants.size() < capacity;
}
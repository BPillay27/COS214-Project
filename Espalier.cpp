#include "Espalier.h"
#include "Plant.h"
#include <iostream>

void Espalier::water(Plant* plant) {
    std::cout << "Watering Espalier plant '" << plant->getSpecies() << "' at the base." << std::endl;
}

void Espalier::prune(Plant* plant) {
    std::cout << "Pruning Espalier plant '" << plant->getSpecies() << "' to maintain flat, trained growth." << std::endl;
}

void Espalier::fertilise(Plant* plant) {
    std::cout << "Fertilising Espalier plant '" << plant->getSpecies() << "' with general-purpose feed." << std::endl;
}
#include "Topiary.h"
#include "Plant.h"
#include <iostream>

void Topiary::water(Plant* plant) {
    std::cout << "Watering Topiary plant '" << plant->getSpecies() << "' sparingly." << std::endl;
    plant->water();
}

void Topiary::prune(Plant* plant) {
    std::cout << "Pruning Topiary plant '" << plant->getSpecies() << "' for specific shape." << std::endl;
    plant->prune();
}

void Topiary::fertilise(Plant* plant) {
    std::cout << "Fertilising Topiary plant '" << plant->getSpecies() << "' with balanced feed." << std::endl;
    plant->fertilise();
}
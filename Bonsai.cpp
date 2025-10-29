#include "Bonsai.h"
#include "Plant.h"
#include <iostream>

void Bonsai::water(Plant* plant) {
    std::cout << "Watering Bonsai plant '" << plant->getSpecies() << "' precisely, checking soil moisture." << std::endl;
    plant->water();
}

void Bonsai::prune(Plant* plant) {
    std::cout << "Pruning Bonsai plant '" << plant->getSpecies() << "' for artistic shaping and ramification." << std::endl;
    plant->prune();
}

void Bonsai::fertilise(Plant* plant) {
    std::cout << "Fertilising Bonsai plant '" << plant->getSpecies() << "' with slow-release, low-nitrogen feed." << std::endl;
    plant->fertilise();
}
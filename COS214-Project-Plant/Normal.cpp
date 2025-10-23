#include "Normal.h"
#include "Plant.h"
#include <iostream>

void Normal::water(Plant* plant) {
    std::cout << "Watering Normal plant '" << plant->getSpecies() << "' when topsoil is dry." << std::endl;
}

void Normal::prune(Plant* plant) {
    std::cout << "Pruning Normal plant '" << plant->getSpecies() << "' to remove dead/diseased branches." << std::endl;
}

void Normal::fertilise(Plant* plant) {
    std::cout << "Fertilising Normal plant '" << plant->getSpecies() << "' periodically." << std::endl;
}
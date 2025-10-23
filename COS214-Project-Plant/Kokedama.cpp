#include "Kokedama.h"
#include "Plant.h"
#include <iostream>

void Kokedama::water(Plant* plant) {
    std::cout << "Watering Kokedama plant '" << plant->getSpecies() << "' by soaking the moss ball." << std::endl;
}

void Kokedama::prune(Plant* plant) {
    std::cout << "Pruning Kokedama plant '" << plant->getSpecies() << "' to maintain compact form." << std::endl;
}

void Kokedama::fertilise(Plant* plant) {
    std::cout << "Fertilising Kokedama plant '" << plant->getSpecies() << "' with diluted liquid feed." << std::endl;
}
#include "Topiary.h"
#include "Plant.h" // Include your existing Plant.h
#include <iostream>

void Topiary::water(Plant* plant) {
    // Example: Call a public method from your Plant class
    // plant->addWater(10); 
    std::cout << "Watering Topiary plant '" << plant->getSpecies() << "' sparingly." << std::endl;
}

void Topiary::prune(Plant* plant) {
    // Example: Call a public method from your Plant class
    // plant->addGrowth(-5); // Assuming pruning might reduce 'growth' score?
    std::cout << "Pruning Topiary plant '" << plant->getSpecies() << "' for specific shape." << std::endl;
}

void Topiary::fertilise(Plant* plant) {
    // Example: Call a public method from your Plant class
    // plant->addNutrition(15);
    std::cout << "Fertilising Topiary plant '" << plant->getSpecies() << "' with balanced feed." << std::endl;
}
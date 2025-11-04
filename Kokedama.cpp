#include "Kokedama.h"
#include "Plant.h"
#include <iostream>

void Kokedama::water(Plant* plant) {
    int moistureLevel = plant->waterMax()+25;
    plant->addWater(moistureLevel);
}

void Kokedama::prune(Plant* plant) {
    int pruneAmount = plant->pruneMax()/4;
    pruneAmount=pruneAmount>0?(-1*pruneAmount):pruneAmount;
    plant->addGrowth(pruneAmount);
}

void Kokedama::fertilise(Plant* plant) {
    int fertiliseAmount = plant->fertiliseMax()+19;
    plant->addNutrition(fertiliseAmount);
}
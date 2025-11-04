#include "Bonsai.h"
#include "Plant.h"
#include <iostream>

void Bonsai::water(Plant* plant) {
    int moistureLevel = plant->waterMax()+15;
    plant->addWater(moistureLevel);
}

void Bonsai::prune(Plant* plant) {
    int pruneAmount = plant->pruneMax()/2;
    pruneAmount=pruneAmount>0?(-1*pruneAmount):pruneAmount;
    plant->addGrowth(pruneAmount);
}

void Bonsai::fertilise(Plant* plant) {
    int fertiliseAmount = plant->fertiliseMax()+10;
    plant->addNutrition(fertiliseAmount);
}
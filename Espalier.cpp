#include "Espalier.h"
#include "Plant.h"
#include <iostream>

void Espalier::water(Plant* plant) {
    int moistureLevel = plant->waterMax()+27;
    plant->addWater(moistureLevel);
}

void Espalier::prune(Plant* plant) {
    int pruneAmount = plant->pruneMax()/7;
    pruneAmount=pruneAmount>0?(-1*pruneAmount):pruneAmount;
    plant->addGrowth(pruneAmount);
}

void Espalier::fertilise(Plant* plant) {
    int fertiliseAmount = plant->fertiliseMax()+17;
    plant->addNutrition(fertiliseAmount);
}
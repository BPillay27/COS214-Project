#include "Topiary.h"
#include "Plant.h"
#include <iostream>

void Topiary::water(Plant* plant) {
    int moistureLevel = plant->waterMax()+30;
    plant->addWater(moistureLevel);
}

void Topiary::prune(Plant* plant) {
    int pruneAmount = plant->pruneMax()/8;
    pruneAmount=pruneAmount>0?(-1*pruneAmount):pruneAmount;
    plant->addGrowth(pruneAmount);
}

void Topiary::fertilise(Plant* plant) {
    int fertiliseAmount = plant->fertiliseMax()+17;
    plant->addNutrition(fertiliseAmount);
}
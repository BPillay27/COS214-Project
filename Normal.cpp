#include "Normal.h"
#include "Plant.h"
#include <iostream>

void Normal::water(Plant* plant) {
    plant->addWater(plant->waterMax()+30);
}

void Normal::prune(Plant* plant) {
    int pruneAmount = plant->pruneMax()/9;
    pruneAmount=pruneAmount>0?(-1*pruneAmount):pruneAmount;
    plant->addGrowth(pruneAmount);
}

void Normal::fertilise(Plant* plant) {
    int fertiliseAmount = plant->fertiliseMax()+23;
    plant->addNutrition(fertiliseAmount);
}
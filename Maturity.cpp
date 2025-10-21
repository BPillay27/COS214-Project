/**
 * @file Maturity.cpp
 * @brief Implementation of the Maturity state pattern classes.
 * @ingroup Maturity
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */

#include "Maturity.h"

Maturity::Maturity(Plant* plant) : mPlant(plant) {

}

Maturity::~Maturity() {

}

//seed class
Seed::Seed(Plant* plant) : Maturity(plant) {

}
Seed::~Seed() {

}

void Seed::grow() {
    // Transition to Sprout stage
    mPlant->setLifeStage(new Sprout(mPlant));
}

bool Seed::canSale() {
    return false;
}

std::string Seed::lifeCycle() {
    return "Seed";
}

//sprout class
Sprout::Sprout(Plant* plant) : Maturity(plant) {

}

Sprout::~Sprout() {

}

void Sprout::grow() {
    // Transition to Seedling stage.
    // a plant can only grow to Seedling if its lifetime >= lifeIntervals[size-2] and growth[0] >= growth[1]
    // if (mPlant->getLifetime() >= mPlant->getLifeIntervals()[mPlant->getLifeIntervals().size() - 2] &&
    //     mPlant->getGrowth()[0] >= mPlant->getGrowth()[1]) {
    //     mPlant->setLifeStage(new Seedling(mPlant));
    // }

    mPlant->setLifeStage(new Seedling(mPlant));
}

bool Sprout::canSale() {
    return false;
}

std::string Sprout::lifeCycle() {
    return "Sprout";
}

//seedling class
Seedling::Seedling(Plant* plant) : Maturity(plant) {

}

Seedling::~Seedling() {

}

void Seedling::grow() {
    // Transition to Mature stage
    mPlant->setLifeStage(new Mature(mPlant));
}

bool Seedling::canSale() {
    return false;
}

std::string Seedling::lifeCycle() {
    return "Seedling";
}

//mature class
Mature::Mature(Plant* plant) : Maturity(plant) {

}

Mature::~Mature() {

}

void Mature::grow() {
    // Already at mature stage, no further growth
}

bool Mature::canSale() {
    return true;
}

std::string Mature::lifeCycle() {
    return "Mature";
}
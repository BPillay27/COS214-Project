/**
 * @file Maturity.cpp
 * @brief Implementation of the Maturity state pattern classes.
 * @ingroup Maturity
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */

#include "Maturity.h"


/**
 * @brief Constructor for the Maturity base class.
 * @param plant Pointer to the plant object that this maturity state belongs to.
 */
Maturity::Maturity(Plant* plant) : mPlant(plant) {

}

/**
 * @brief Destructor for the Maturity base class.
 */
Maturity::~Maturity() {

}

//seed class
/**
 * @brief Constructor for the Seed class.
 * @param plant Pointer to the plant object that this seed state belongs to.
 */
Seed::Seed(Plant* plant) : Maturity(plant) {

}

/**
 * @brief Destructor for the Seed class.
 */
Seed::~Seed() {

}

/**
 * @brief Grows the plant from seed to sprout stage.
 * Transitions the plant's life stage to Sprout when lifeTime reaches the first interval.
 */
void Seed::grow() {

    int* intervals = mPlant->getLifeIntervals();
    
    // Seed needs water to germinate
    if (mPlant->getLifeTime() >= 0 && 
        !mPlant->toWater()) {  // Has sufficient water
        mPlant->setLifeStage(new Sprout(mPlant));
    }
}

/**
 * @brief Checks if the plant can be sold at the seed stage.
 * @return false, as seeds cannot be sold.
 */
bool Seed::canSale() {
    return false;
}

/**
 * @brief Returns the name of the current life cycle stage.
 * @return String "Seed" representing the current stage.
 */
std::string Seed::lifeCycle() {
    return "Seed";
}

//sprout class
/**
 * @brief Constructor for the Sprout class.
 * @param plant Pointer to the plant object that this sprout state belongs to.
 */
Sprout::Sprout(Plant* plant) : Maturity(plant) {

}

/**
 * @brief Destructor for the Sprout class.
 */
Sprout::~Sprout() {

}

/**
 * @brief Grows the plant from sprout to seedling stage.
 * Transitions the plant's life stage to Seedling when lifeTime reaches the second interval
 * and the plant has healthy growth (not overgrown).
 */
void Sprout::grow() {
    // Transition to Seedling stage when time is right and plant size is above it's measure at this state
    int* intervals = mPlant->getLifeIntervals();
    if (mPlant->getLifeTime() >= intervals[0] && mPlant->toPrune()) {
        mPlant->setLifeStage(new Seedling(mPlant));
    }
}

/**
 * @brief Checks if the plant can be sold at the sprout stage.
 * @return false, as sprouts cannot be sold.
 */
bool Sprout::canSale() {
    return false;
}

/**
 * @brief Returns the name of the current life cycle stage.
 * @return String "Sprout" representing the current stage.
 */
std::string Sprout::lifeCycle() {
    return "Sprout";
}

//seedling class
/**
 * @brief Constructor for the Seedling class.
 * @param plant Pointer to the plant object that this seedling state belongs to.
 */
Seedling::Seedling(Plant* plant) : Maturity(plant) {

}

/**
 * @brief Destructor for the Seedling class.
 */
Seedling::~Seedling() {

}

/**
 * @brief Grows the plant from seedling to mature stage.
 * Transitions the plant's life stage to Mature when lifeTime reaches the third interval
 * and the plant has healthy growth (not overgrown).
 */
void Seedling::grow() {
    // Transition to Mature stage when time is right and plant is healthy (not needing pruning)
    int* intervals = mPlant->getLifeIntervals();
    if (mPlant->getLifeTime() >= intervals[1] && mPlant->toPrune()) {
        mPlant->setLifeStage(new Mature(mPlant));
    }
}

/**
 * @brief Checks if the plant can be sold at the seedling stage.
 * @return false, as seedlings cannot be sold (Not yet Mature).
 */
bool Seedling::canSale() {
    return false;
}

/**
 * @brief Returns the name of the current life cycle stage.
 * @return String "Seedling" representing the current stage.
 */
std::string Seedling::lifeCycle() {
    return "Seedling";
}

//mature class
/**
 * @brief Constructor for the Mature class.
 * @param plant Pointer to the plant object that this mature state belongs to.
 */
Mature::Mature(Plant* plant) : Maturity(plant) {

}

/**
 * @brief Destructor for the Mature class.
 */
Mature::~Mature() {

}

/**
 * @brief Attempts to grow the plant at the mature stage.
 * Checks if the plant has exceeded its lifespan and transitions to DeadPlant state if so.
 */
void Mature::grow() {
    // Check if plant has reached the end of its lifespan (4th interval)
    int* intervals = mPlant->getLifeIntervals();
    if (mPlant->getLifeTime() >= intervals[2]) {
        Maturity* dead = new Dead(mPlant);
        mPlant->setLifeStage(dead);
    }
    // Otherwise, already at mature stage, no further growth
}

/**
 * @brief Checks if the plant can be sold at the mature stage.
 * @return true, as mature plants can be sold.
 */
bool Mature::canSale() {
    return true;
}

/**
 * @brief Returns the name of the current life cycle stage.
 * @return String "Mature" representing the current stage.
 */
std::string Mature::lifeCycle() {
    return "Mature";
}

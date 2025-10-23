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
 * Transitions the plant's life stage to Sprout.
 */
void Seed::grow() {
    // Transition to Sprout stage
    mPlant->setLifeStage(new Sprout(mPlant));
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
 * Transitions the plant's life stage to Seedling.
 */
void Sprout::grow() {
    // Transition to Seedling stage.
    // a plant can only grow to Seedling if its lifetime >= lifeIntervals[size-2] and growth[0] >= growth[1]
    // if (mPlant->getLifetime() >= mPlant->getLifeIntervals()[mPlant->getLifeIntervals().size() - 2] &&
    //     mPlant->getGrowth()[0] >= mPlant->getGrowth()[1]) {
    //     mPlant->setLifeStage(new Seedling(mPlant));
    // }

    mPlant->setLifeStage(new Seedling(mPlant));
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
 * Transitions the plant's life stage to Mature.
 */
void Seedling::grow() {
    // Transition to Mature stage
    mPlant->setLifeStage(new Mature(mPlant));
}

/**
 * @brief Checks if the plant can be sold at the seedling stage.
 * @return false, as seedlings cannot be sold.
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
 * No further growth occurs as the plant is already mature.
 */
void Mature::grow() {
    // Already at mature stage, no further growth
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
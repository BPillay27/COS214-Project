#include "Condition.h"

/**
 * @brief Constructor for the Condition base class.
 * @param plant Pointer to the plant object that this condition state belongs to.
 */
Condition::Condition(Plant* plant) : cPlant(plant) {

}

/**
 * @brief Destructor for the Condition base class.
 */
Condition::~Condition() {

}

/**
 * @brief Adjusts the growth level of the plant.
 * @param amount The amount to adjust growth by (can be positive or negative).
 */
void Condition::adjustGrowth(int amount) {
    cPlant->addGrowth(amount);
}

/**
 * @brief Adjusts the water level of the plant.
 * @param amount The amount to adjust water by (can be positive or negative).
 */
void Condition::adjustWater(int amount) {
    cPlant->addWater(amount);
}

/**
 * @brief Adjusts the nutrition level of the plant.
 * @param amount The amount to adjust nutrition by (can be positive or negative).
 */
void Condition::adjustNutrition(int amount) {
    cPlant->addNutrition(amount);
}

// Healthy class
/**
 * @brief Constructor for the Healthy class.
 * @param plant Pointer to the plant object that this healthy state belongs to.
 */
Healthy::Healthy(Plant* plant) : Condition(plant) {

}

/**
 * @brief Destructor for the Healthy class.
 */
Healthy::~Healthy() {

}

/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Checks if the plant needs water, fertilizer, or pruning and transitions accordingly:
 * - To Dehydrated if water is needed
 * - To Malnurished if fertilizer is needed
 * - To OverGrown if pruning is needed
 */
void Healthy::examine() {
    //If plant is healthy, no adjustments needed.

    //go to dehydrated state if water level is low
    if (toWater()) {
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    //go to malnurished state if nutrition level is low
    else if (toFertilise()) {
        cPlant->setCondition(new Malnurished(cPlant));
    }
    //go to overgrown state if growth level is high
    else if (toPRune()) {
        cPlant->setCondition(new OverGrown(cPlant));
    }
}

// Dehydrated class
/**
 * @brief Constructor for the Dehydrated class.
 * @param plant Pointer to the plant object that this dehydrated state belongs to.
 */
Dehydrated::Dehydrated(Plant* plant) : Condition(plant) {

}

/**
 * @brief Destructor for the Dehydrated class.
 */
Dehydrated::~Dehydrated() {

}

/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Transitions based on water restoration and additional issues:
 * - To Healthy if water is restored
 * - To DehydratedMalnurished if also malnourished
 * - To DehydratedOverGrown if also overgrown
 */
void Dehydrated::examine() {
    //if the water levels are restored, go back to healthy
    if (!toWater()) {
        cPlant->setCondition(new Healthy(cPlant));    
    }
    //if the plant is also malnurished, go to DehydratedMalnurished state
    else if (toFertilise()) {
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    //if the plant is also overgrown, go to DehydratedOverGrown state
    else if (toPRune()) {
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
}

// DehydratedOverGrown class
/**
 * @brief Constructor for the DehydratedOverGrown class.
 * @param plant Pointer to the plant object that this dehydrated and overgrown state belongs to.
 */
DehydratedOverGrown::DehydratedOverGrown(Plant* plant) : Condition(plant) {

}

/**
 * @brief Destructor for the DehydratedOverGrown class.
 */
DehydratedOverGrown::~DehydratedOverGrown() {

}

/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Transitions based on resolution of dehydration, overgrowth, or additional issues:
 * - To OverGrown if water is restored
 * - To Dehydrated if overgrowth is fixed
 * - To DehydratedMalnurishedOverGrown if also malnourished
 */
void DehydratedOverGrown::examine() {
    //if water levels are restored, go to OverGrown state
    if (!toWater()) {
        cPlant->setCondition(new OverGrown(cPlant));
    }
    //if overgrowth is fixed, go to Dehydrated state
    else if (!toPRune()) {
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    //if plant also malnutrished, go to DehydratedMalnurishedOverGrown state
    else if (toFertilise()) {
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
}

// DehydratedMalnurished class
/**
 * @brief Constructor for the DehydratedMalnurished class.
 * @param plant Pointer to the plant object that this dehydrated and malnourished state belongs to.
 */
DehydratedMalnurished::DehydratedMalnurished(Plant* plant) : Condition(plant) {

}

/**
 * @brief Destructor for the DehydratedMalnurished class.
 */
DehydratedMalnurished::~DehydratedMalnurished() {

}

/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Transitions based on resolution of dehydration, malnutrition, or additional issues:
 * - To Healthy if both water and nutrition are restored
 * - To Malnurished if water is restored
 * - To Dehydrated if nutrition is restored
 * - To DehydratedMalnurishedOverGrown if also overgrown
 */
void DehydratedMalnurished::examine() {

    //if all restored, go to Healthy state
    if (!toWater() && !toFertilise()) {
        cPlant->setCondition(new Healthy(cPlant));
    }
    //if plane water levels are restored, go to Malnurished state
    if (!toWater()) {
        cPlant->setCondition(new Malnurished(cPlant));
    }
    //if nutrition levels are restored, go to Dehydrated state
    else if (!toFertilise()) {
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    //if plant also overgrown, go to DehydratedMalnurishedOverGrown state
    else if (toPRune()) {
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }

    
}

// DehydratedMalnurishedOverGrown class
/**
 * @brief Constructor for the DehydratedMalnurishedOverGrown class.
 * @param plant Pointer to the plant object that this dehydrated, malnourished, and overgrown state belongs to.
 */
DehydratedMalnurishedOverGrown::DehydratedMalnurishedOverGrown(Plant* plant) : Condition(plant) {

}

/**
 * @brief Destructor for the DehydratedMalnurishedOverGrown class.
 */
DehydratedMalnurishedOverGrown::~DehydratedMalnurishedOverGrown() {

}

/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Transitions based on resolution of any or all of the three issues:
 * - To MalnurishedOverGrown if water is restored
 * - To DehydratedOverGrown if nutrition is restored
 * - To DehydratedMalnurished if overgrowth is fixed
 * - To Healthy if all conditions are restored
 */
void DehydratedMalnurishedOverGrown::examine() {
    //if the plant water levels are restored, go to MalnurishedOverGrown state
    if (!toWater()) {
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    //if nutrition levels are restored, go to DehydratedOverGrown state
    else if (!toFertilise()) {
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    //if overgrowth is fixed, go to DehydratedMalnurished state
    else if (!toPRune()) {
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }

    //if all restored, go to Healthy state
    else if (!toWater() && !toFertilise() && !toPRune()) {
        cPlant->setCondition(new Healthy(cPlant));
    }
}

//Malnurished class
/**
 * @brief Constructor for the Malnurished class.
 * @param plant Pointer to the plant object that this malnourished state belongs to.
 */
Malnurished::Malnurished(Plant* plant) : Condition(plant) {

}

/**
 * @brief Destructor for the Malnurished class.
 */
Malnurished::~Malnurished() {

}

/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Transitions based on nutrition restoration and additional issues:
 * - To Healthy if nutrition is restored
 * - To DehydratedMalnurished if also dehydrated
 * - To MalnurishedOverGrown if also overgrown
 */
void Malnurished::examine() {
    //if the nutrition levels are restored, go back to healthy
    if (!toFertilise()) {
        cPlant->setCondition(new Healthy(cPlant));    
    }
    //if the plant is also dehydrated, go to DehydratedMalnurished state
    else if (toWater()) {
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    //if the plant is also overgrown, go to MalnurishedOverGrown state
    else if (toPRune()) {
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
}

//Malnurished OverGrown class
/**
 * @brief Constructor for the MalnurishedOverGrown class.
 * @param plant Pointer to the plant object that this malnourished and overgrown state belongs to.
 */
MalnurishedOverGrown::MalnurishedOverGrown(Plant* plant) : Condition(plant) {

}

/**
 * @brief Destructor for the MalnurishedOverGrown class.
 */
MalnurishedOverGrown::~MalnurishedOverGrown() {

}

/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Transitions based on resolution of malnutrition, overgrowth, or additional issues:
 * - To Malnurished if overgrowth is fixed
 * - To OverGrown if nutrition is restored
 * - To DehydratedMalnurishedOverGrown if also dehydrated
 * - To Healthy if both nutrition and pruning are addressed
 */
void MalnurishedOverGrown::examine() {
    //if overgrowth is fixed, go to Malnurished state
    if (!toPRune()) {
        cPlant->setCondition(new Malnurished(cPlant));
    }
    //if nutrition levels are restored, go to OverGrown state
    else if (!toFertilise()) {
        cPlant->setCondition(new OverGrown(cPlant));
    }
    //if plant also dehydrated, go to DehydratedMalnurishedOverGrown state
    else if (toWater()) {
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }

    //if plant is fertilised and pruned, go to Healthy state
    else if (!toFertilise() && !toPRune()) {
        cPlant->setCondition(new Healthy(cPlant));
    }
}

// OverGrown class
/**
 * @brief Constructor for the OverGrown class.
 * @param plant Pointer to the plant object that this overgrown state belongs to.
 */
OverGrown::OverGrown(Plant* plant) : Condition(plant) {

}

/**
 * @brief Destructor for the OverGrown class.
 */
OverGrown::~OverGrown() {

}

/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Transitions based on resolution of overgrowth or additional issues:
 * - To Healthy if overgrowth is fixed
 * - To MalnurishedOverGrown if also malnourished
 * - To DehydratedOverGrown if also dehydrated
 */
void OverGrown::examine() {
    //if overgrowth is fixed, go back to healthy
    if (!toPRune()) {
        cPlant->setCondition(new Healthy(cPlant));
    }
    //if plant also malnourished, go to MalnurishedOverGrown state
    else if (toFertilise()) {
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    //if plant also dehydrated, go to DehydratedOverGrown state
    else if (toWater()) {
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }

}

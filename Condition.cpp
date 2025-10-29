#include "Condition.h"
#include <cstdlib>  // For rand()
#include <ctime>    // For seeding
std::srand(std::time(0)); // Seed for random number generation
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

// /**
//  * @brief Adjusts the growth level of the plant.
//  * @param amount The amount to adjust growth by (can be positive or negative).
//  */
// void Condition::adjustGrowth(int amount) {
//     cPlant->addGrowth(amount);
// }

// /**
//  * @brief Adjusts the water level of the plant.
//  * @param amount The amount to adjust water by (can be positive or negative).
//  */
// void Condition::adjustWater(int amount) {
//     cPlant->addWater(amount);
// }

// /**
//  * @brief Adjusts the nutrition level of the plant.
//  * @param amount The amount to adjust nutrition by (can be positive or negative).
//  */
// void Condition::adjustNutrition(int amount) {
//     cPlant->addNutrition(amount);
// }

/** Helper methods for natural resource degradation */
void Condition::degradeWater() {
    // Random water consumption between 1-8 units
    int waterLoss = (rand() % 7) + 1;
    cPlant->addWater(-waterLoss);  // Negative amount to reduce
}

void Condition::degradeNutrition() {
    // Random nutrition consumption between 1-4 units
    int nutritionLoss = (rand() % 3) + 1;
    cPlant->addNutrition(-nutritionLoss);  // Negative amount to reduce
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
 * @param shouldDegrade Indicates if natural degradation should occur.
 */
void Healthy::examine(bool shouldDegrade) {
    if (shouldDegrade) {
        degradeWater();
        degradeNutrition();
    }

    bool needsWater = cPlant->toWater();
    bool needsFertiliser = cPlant->toFertilise();
    bool needsPrune = cPlant->toPrune();

    // Most specific to least specific
    if (needsWater && needsFertiliser && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
    else if (needsWater && needsFertiliser) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    else if (needsWater && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    else if (needsFertiliser && needsPrune) {
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    else if (needsWater) {
        cPlant->notify("water");
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    else if (needsFertiliser) {
        cPlant->notify("fertiliser");
        cPlant->setCondition(new Malnurished(cPlant));
    }
    else if (needsPrune) {
        cPlant->notify("prune");
        cPlant->setCondition(new OverGrown(cPlant));
    }
    // else: stay Healthy
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
void Dehydrated::examine(bool shouldDegrade) {
    if (shouldDegrade) {
        degradeWater();
        degradeNutrition();
    }

    // Simple death check - only if completely depleted
    if (cPlant->isResourcesDepleted()) {
        cPlant->notify("dead");
        cPlant->setCondition(new DeadPlant(cPlant));
        cPlant->setLifeStage(new DeadPlant(cPlant));
        return;
    }

    bool needsWater = cPlant->toWater();
    bool needsFertiliser = cPlant->toFertilise();
    bool needsPrune = cPlant->toPrune();

    // Check all conditions and transition to appropriate state
    
    // Triple compound (still dehydrated + 2 new problems)
    if (needsWater && needsFertiliser && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
    // Double compounds
    else if (needsWater && needsFertiliser) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    else if (needsWater && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    //!! Need double check
    else if (needsFertiliser && needsPrune) { 
        // Water was restored! But now has other issues
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    // Single states
    else if (needsWater) {
        // Still dehydrated, notify gardener again
        cPlant->notify("dead");
        cPlant->setCondition(new DeadPlant(cPlant));
        return;
    }
    else if (needsFertiliser) { //!! Need double check
        // Water restored, but now malnourished
        cPlant->notify("fertiliser");
        cPlant->setCondition(new Malnurished(cPlant));
    }
    else if (needsPrune) {//!! Need double check
        // Water restored, but now overgrown
        cPlant->notify("prune");
        cPlant->setCondition(new OverGrown(cPlant));
    }
    else {
        // Water restored and no other issues - back to healthy!
        cPlant->setCondition(new Healthy(cPlant));
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
void DehydratedOverGrown::examine(bool shouldDegrade) {
    if (shouldDegrade) {
        degradeWater();
        degradeNutrition();
    }

    // Simple death check - only if completely depleted
    if (cPlant->isResourcesDepleted()) {
        cPlant->notify("dead");
        cPlant->setCondition(new DeadPlant(cPlant));
        cPlant->setLifeStage(new DeadPlant(cPlant));
        return;
    }
    
    bool needsWater = cPlant->toWater();
    bool needsFertiliser = cPlant->toFertilise();
    bool needsPrune = cPlant->toPrune();
    
    // Triple compound (both primary issues still present + fertiliser needed)
    if (needsWater && needsFertiliser && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
    // Double compounds
    else if (needsWater && needsFertiliser) { //!! Need double check
        // Pruning done! But still dehydrated and now malnourished
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    else if (needsWater && needsPrune) {
        // Both primary issues still present, no new issues
        cPlant->notify("water");
        cPlant->notify("prune");
        // Stay in DehydratedOverGrown - no state change
    }
    else if (needsFertiliser && needsPrune) { //!! Need double check
        // Water applied! But still overgrown and now malnourished
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    // Single states (one of the two primary issues resolved)
    else if (needsWater) { //!! Need double check
        // Pruning done, but still dehydrated
        cPlant->notify("water");
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    else if (needsFertiliser) { //!! Need double check
        // Both primary issues resolved! But now malnourished
        cPlant->notify("fertiliser");
        cPlant->setCondition(new Malnurished(cPlant));
    }
    else if (needsPrune) { //!! Need double check
        // Water applied, but still overgrown
        cPlant->notify("prune");
        cPlant->setCondition(new OverGrown(cPlant));
    }
    else {
        // Both primary issues resolved and no other issues - back to healthy!
        cPlant->setCondition(new Healthy(cPlant));
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
void DehydratedMalnurished::examine(bool shouldDegrade) {
    if (shouldDegrade) {
        degradeWater();
        degradeNutrition();
    }

    // Simple death check - only if completely depleted
    if (cPlant->isResourcesDepleted()) {
        cPlant->notify("dead");
        cPlant->setCondition(new DeadPlant(cPlant));
        cPlant->setLifeStage(new DeadPlant(cPlant));
        return;
    }
    
    bool needsWater = cPlant->toWater();
    bool needsFertiliser = cPlant->toFertilise();
    bool needsPrune = cPlant->toPrune();
    
    // Triple compound (both primary issues still present + pruning needed)
    if (needsWater && needsFertiliser && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
    // Double compounds
    else if (needsWater && needsFertiliser) {
        // Both primary issues still present, no new issues
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        // Stay in DehydratedMalnurished - no state change
    }
    else if (needsWater && needsPrune) {
        // Fertiliser applied! But still dehydrated and now overgrown
        cPlant->notify("water");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    else if (needsFertiliser && needsPrune) {
        // Water applied! But still malnourished and now overgrown
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    // Single states (one of the two primary issues resolved)
    else if (needsWater) {
        // Fertiliser applied, but still dehydrated
        cPlant->notify("water");
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    else if (needsFertiliser) {
        // Water applied, but still malnourished
        cPlant->notify("fertiliser");
        cPlant->setCondition(new Malnurished(cPlant));
    }
    else if (needsPrune) {
        // Both primary issues resolved! But now overgrown
        cPlant->notify("prune");
        cPlant->setCondition(new OverGrown(cPlant));
    }
    else {
        // Both primary issues resolved and no other issues - back to healthy!
        cPlant->setCondition(new Healthy(cPlant));
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
void DehydratedMalnurishedOverGrown::examine(bool shouldDegrade) {
    if (shouldDegrade) {
        degradeWater();
        degradeNutrition();
    }

    // Simple death check - only if completely depleted
    if (cPlant->isResourcesDepleted()) {
        cPlant->notify("dead");
        cPlant->setCondition(new DeadPlant(cPlant));
        cPlant->setLifeStage(new DeadPlant(cPlant));
        return;
    }
    
    bool needsWater = cPlant->toWater();
    bool needsFertiliser = cPlant->toFertilise();
    bool needsPrune = cPlant->toPrune();

    // Triple compound (all three primary issues still present)
    if (needsWater && needsFertiliser && needsPrune) {
        // All three issues still present - STAY
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        // Stay in DehydratedMalnurishedOverGrown - no state change
    }
    // Double compounds (one issue resolved)
    else if (needsWater && needsFertiliser) {
        // Pruning done! Still dehydrated and malnourished
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    else if (needsWater && needsPrune) {
        // Fertiliser applied! Still dehydrated and overgrown
        cPlant->notify("water");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    else if (needsFertiliser && needsPrune) {
        // Water applied! Still malnourished and overgrown
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    // Single states (two issues resolved)
    else if (needsWater) {
        // Fertiliser and pruning done, but still dehydrated
        cPlant->notify("water");
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    else if (needsFertiliser) {
        // Water and pruning done, but still malnourished
        cPlant->notify("fertiliser");
        cPlant->setCondition(new Malnurished(cPlant));
    }
    else if (needsPrune) {
        // Water and fertiliser done, but still overgrown
        cPlant->notify("prune");
        cPlant->setCondition(new OverGrown(cPlant));
    }
    else {
        // All three issues resolved - back to healthy!
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
void Malnurished::examine(bool shouldDegrade) {
    if (shouldDegrade) {
        degradeWater();
        degradeNutrition();
    }

    // Simple death check - only if completely depleted
    if (cPlant->isResourcesDepleted()) {
        cPlant->notify("dead");
        cPlant->setCondition(new DeadPlant(cPlant));
        cPlant->setLifeStage(new DeadPlant(cPlant));
        return;
    }
    
    bool needsWater = cPlant->toWater();
    bool needsFertiliser = cPlant->toFertilise();
    bool needsPrune = cPlant->toPrune();
    
    // Triple compound (still malnourished + 2 new problems)
    if (needsWater && needsFertiliser && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
    // Double compounds
    else if (needsWater && needsFertiliser) {
        // Still malnourished + now dehydrated
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    else if (needsWater && needsPrune) {
        // Fertiliser was applied! But now has water and pruning issues
        cPlant->notify("water");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    else if (needsFertiliser && needsPrune) {
        // Still malnourished + now overgrown
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    // Single states
    else if (needsWater) {
        // Fertiliser applied, but now dehydrated
        cPlant->notify("water");
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    else if (needsFertiliser) {
        // Still malnourished, notify gardener again
        cPlant->notify("fertiliser");
        // Stay in Malnurished - no state change
    }
    else if (needsPrune) {
        // Fertiliser applied, but now overgrown
        cPlant->notify("prune");
        cPlant->setCondition(new OverGrown(cPlant));
    }
    else {
        // Fertiliser applied and no other issues - back to healthy!
        cPlant->setCondition(new Healthy(cPlant));
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
void MalnurishedOverGrown::examine(bool shouldDegrade) {
    if (shouldDegrade) {
        degradeWater();
        degradeNutrition();
    }

    // Simple death check - only if completely depleted
    if (cPlant->isResourcesDepleted()) {
        cPlant->notify("dead");
        cPlant->setCondition(new DeadPlant(cPlant));
        cPlant->setLifeStage(new DeadPlant(cPlant));
        return;
    }
    
    bool needsWater = cPlant->toWater();
    bool needsFertiliser = cPlant->toFertilise();
    bool needsPrune = cPlant->toPrune();
    
    // Triple compound (both primary issues still present + water needed)
    if (needsWater && needsFertiliser && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
    // Double compounds
    else if (needsWater && needsFertiliser) {
        // Pruning done! But still malnourished and now dehydrated
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    else if (needsWater && needsPrune) {
        // Fertiliser applied! But still overgrown and now dehydrated
        cPlant->notify("water");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    else if (needsFertiliser && needsPrune) {
        // Both primary issues still present, no new issues
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        // Stay in MalnurishedOverGrown - no state change
    }
    // Single states (one of the two primary issues resolved)
    else if (needsWater) {
        // Both primary issues resolved! But now dehydrated
        cPlant->notify("water");
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    else if (needsFertiliser) {
        // Pruning done, but still malnourished
        cPlant->notify("fertiliser");
        cPlant->setCondition(new Malnurished(cPlant));
    }
    else if (needsPrune) {
        // Fertiliser applied, but still overgrown
        cPlant->notify("prune");
        cPlant->setCondition(new OverGrown(cPlant));
    }
    else {
        // Both primary issues resolved and no other issues - back to healthy!
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
void OverGrown::examine(bool shouldDegrade) {
    if (shouldDegrade) {
        degradeWater();
        degradeNutrition();
    }
    
    bool needsWater = cPlant->toWater();
    bool needsFertiliser = cPlant->toFertilise();
    bool needsPrune = cPlant->toPrune();

    // Check all conditions and transition to appropriate state
    
    // Triple compound (still overgrown + 2 new problems)
    if (needsWater && needsFertiliser && needsPrune) {
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
    // Double compounds
    else if (needsWater && needsFertiliser) { //!! Need double check
        // Pruning was done! But now has water and fertiliser issues
        cPlant->notify("water");
        cPlant->notify("fertiliser");
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    else if (needsWater && needsPrune) {
        // Still overgrown + now dehydrated
        cPlant->notify("water");
        cPlant->notify("prune");
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    else if (needsFertiliser && needsPrune) {
        // Still overgrown + now malnourished
        cPlant->notify("fertiliser");
        cPlant->notify("prune");
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    // Single states
    else if (needsWater) { //!! Need double check
        // Pruning done, but now dehydrated
        cPlant->notify("water");
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    else if (needsFertiliser) { //!! Need double check
        // Pruning done, but now malnourished
        cPlant->notify("fertiliser");
        cPlant->setCondition(new Malnurished(cPlant));
    }
    else if (needsPrune) {
        // Still overgrown, notify gardener again
        cPlant->notify("prune");
        // Stay in OverGrown - no state change
    }
    else {
        // Pruning done and no other issues - back to healthy!
        cPlant->setCondition(new Healthy(cPlant));
    }
}

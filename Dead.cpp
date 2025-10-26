#include "Dead.h"

DeadPlant::DeadPlant(Plant* plant) : Maturity(plant), Condition(plant) {}

DeadPlant::~DeadPlant() {}

/**
 * @brief Grows the dead plant (no operation as dead plants do not grow).
 */
void DeadPlant::grow() {
    // Dead plants do not grow
}

/**
 * @brief Checks if the dead plant can be sold.
 * @return false, as dead plants cannot be sold.
 */
bool DeadPlant::canSale() {
    return false; // Dead plants cannot be sold
}

/**
 * @brief Returns the name of the current life cycle stage.
 * @return String indicating the dead plant's decomposition status.
 */
std::string DeadPlant::lifeCycle() {
    return "Dead plant is decomposing.";
}
/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Dead plants do not change state.
 */
void DeadPlant::examine() {
    // Dead plants do not change state
}   
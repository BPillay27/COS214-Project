#include "Dead.h"

Dead::Dead(Plant* plant) : Maturity(plant), Condition(plant) {}

Dead::~Dead() {}

/**
 * @brief Grows the dead plant (no operation as dead plants do not grow).
 */
void Dead::grow() {
    // Dead plants do not grow. SO call examine to notify gardener
    examine(false);
}

/**
 * @brief Checks if the dead plant can be sold.
 * @return false, as dead plants cannot be sold.
 */
bool Dead::canSale() {
    return false; // Dead plants cannot be sold
}

/**
 * @brief Returns the name of the current life cycle stage.
 * @return String indicating the dead plant's decomposition status.
 */
std::string Dead::lifeCycle() {
    return "Dead plant is decomposing.";
}
/**
 * @brief Examines the plant's condition and transitions to appropriate states.
 * Dead plants do not change state.
 */
void DeadP::examine(bool shouldDegrade) {
    // it should notify the gardener that the plant is dead
    cPlant->notify("dead");
}   
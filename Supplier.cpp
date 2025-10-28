#include "Supplier.h"


/**
 * @brief Initializes a Rose plant object and returns it.
 */
Plant * RoseSupplier::resupply() {
    return new Rose();
}

/**
 * @brief Initializes a Apple plant object and returns it.
 */
Plant * AppleSupplier::resupply() {
    return new AppleTree();
}

/**
 * @brief Initializes a Dandelion plant object and returns it.
 */
Plant * DandelionSupplier::resupply() {
    return new Dandelion();
}
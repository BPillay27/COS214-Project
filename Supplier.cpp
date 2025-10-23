#include "Supplier.h"


/**
 * @brief Initializes a Rose plant object and returns it.
 */
Plant * RoseSupplier::Resupply() {
    return new Rose();
}

/**
 * @brief Initializes a Apple plant object and returns it.
 */
Plant * AppleSupplier::Resupply() {
    return new AppleTree();
}

/**
 * @brief Initializes a Dandelion plant object and returns it.
 */
Plant * DandelionSupplier::Resupply() {
    return new Dandelion();
}

/**
 * @brief Returns the species name Rose as a string
 */
string RoseSupplier::getSpecies() {
return "Rose";
}

/**
 * @brief Returns the species name AppleTree as a string
 */
string AppleSupplier::getSpecies() {
return "AppleTree";
}

/**
 * @brief Returns the species name Dandelion as a string
 */
string DandelionSupplier::getSpecies() {
return "Dandelion";
}
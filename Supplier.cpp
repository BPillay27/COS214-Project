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

string RoseSupplier::getSpecies() {

}

string RoseSupplier::getSpecies() {

}

string RoseSupplier::getSpecies() {

}
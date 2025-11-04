#include "Supplier.h"


/**
 * @brief Initializes a Rose plant object and returns it.
 */
Plant * RoseSupplier::resupply() {
    Plant* rose = new Rose();
    rose->setCare(new Normal());
    return rose;
}

/**
 * @brief Initializes a Apple plant object and returns it.
 */
Plant * AppleSupplier::resupply() {
    Plant* apple = new AppleTree();
    apple->setCare(new Espalier());
    return apple;
}

/**
 * @brief Initializes a Dandelion plant object and returns it.
 */
Plant * DandelionSupplier::resupply() {
    Plant* dandelion = new Dandelion();
    dandelion->setCare(new Kokedama());
    return dandelion;
}
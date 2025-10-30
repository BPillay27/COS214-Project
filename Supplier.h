#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Plant.h"

/**
 * @class Supplier
 * @brief A base class that is a represantation of a generic Supplier.
 * This class serves as a foundation for the creation of plant objects.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * @ingroup Inventory Singelton
 * @author Mulondi Makhado
 * @date October 2025
 * @link Gardener
 */
class Supplier {
    public:
        virtual Plant * resupply() = 0;
};

/**
 * @class RoseSupplier
 * @brief A derived class that is represents a Rose supplier.
 * Inherits from the Supplier base class.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * @ingroup Inventory Singelton
 * @author Mulondi Makhado
 * @date October 2025
 * @link Gardener
 */
class RoseSupplier : public Supplier {
    public:
        /**
        *@brief Creates a Rose plant object.
        */
        Plant * resupply();
};

/**
 * @class AppleSupplier
 * @brief A derived class that is represents a AppleTree supplier.
 * Inherits from the Supplier base class.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * @ingroup Inventory Singelton
 * @author Mulondi Makhado
 * @date October 2025
 * @link Gardener
 */
class AppleSupplier : public Supplier {
    public:
         /**
        *@brief Creates a AppleTree plant object.
        */
        Plant * resupply();
};

/**
 * @class DandelionSupplier
 * @brief A derived class that is represents a Dandelion supplier.
 * Inherits from the Supplier base class.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * @ingroup Inventory Singelton
 * @author Mulondi Makhado
 * @date October 2025
 * @link Gardener
 */
class DandelionSupplier : public Supplier {
    public:
         /**
        *@brief Creates a Dandelion plant object.
        */
        Plant * resupply();
};

#endif
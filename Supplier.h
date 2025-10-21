#ifndef SUPPLIER_H
#define SUPPLIER_H

#include "Plant.h"

/**
 * @class Supplier
 * @brief A base class representing a generic plant.
 * This class serves as a foundation for specific plant types.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * @ingroup Inventory Singelton
 * @author Mulondi Makhado
 * @date October 2025
 * @link Gardener
 */
class Supplier {
    protected:
        virtual Plant * Resupply(int growth,int water,int nutrition, int lifeCycle[4]) = 0;
        virtual void getSpecies() = 0;
};

/**
 * @class RoseSupplier
 * @brief A base class representing a generic plant.
 * This class serves as a foundation for specific plant types.
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
        *@brief Creates a Rose plant object then adds it to the inventory.
        *@param growth The 
        *@param water 
        *@param nutrition 
        *@param lifeCycle 
        */
        Plant * Resupply(int growth,int water,int nutrition, int lifeCycle[4]);
        void getSpecies();
};

/**
 * @class AppleSupplier
 * @brief A base class representing a generic plant.
 * This class serves as a foundation for specific plant types.
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
        Plant * Resupply(int growth,int water,int nutrition, int lifeCycle[4]);
        void getSpecies();
};

/**
 * @class DandelionSupplier
 * @brief A base class representing a generic plant.
 * This class serves as a foundation for specific plant types.
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

        Plant * Resupply(int growth,int water,int nutrition, int lifeCycle[4]);
        void getSpecies();
};

#endif
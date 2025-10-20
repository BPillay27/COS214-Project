#ifndef PLANT_H
#define PLANT_H
//Wait to see dependencies --- IGNORE ---
//#include "Gardener.h"
//#include "Condition.h"
//#include "Maturity.h"
#include <string>
#include <iostream> 
using namespace std;
/**
 * @class Plant
 * @brief A base class representing a generic plant.
 * This class serves as a foundation for specific plant types.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * @ingroup Order Composite
 * @author Keegan Lewis
 * @date October 2025
 * @link Gardener
 */
class Plant {
    private:
        int lifeIntervals[4];  
        int lifeTime;  // How long the plant has been active
        int growth[2];
        int waterLevel[2];
        int soilNutrition[2];
        string species; 
        Gardener* gardener;
        /**
         * @link Condition
         */
        Condition* condition;
        /**
         * @link Maturity
         */
        Maturity* maturity;
    public:
        
        Plant(string name,int growth,int water,int nutrition, int lifeCycle[4]);
        /**
        *@brief Sets the condition state for the plant.
        *@param condition Pointer to the new Condition state.
        */
       void setCondition(Condition* condition);
       /**
        * @brief Sets the maturity state for the plant.
        * @param life Pointer to the new Maturity state.
        */
       void setLifeStage(Maturity* life);
       /**
        * @brief Simulates the growth of the plant and aging process.
        */
       void grow();
       /**
        * @brief virtual Destructor for the Plant class.
        */
        virtual ~Plant();
        bool addGrowth(int amount);
        bool addWater(int amount);
        bool addNutrition(int amount);
        bool canSale();
        string getSpecies();
        string getDetails();
        void notify(string request);
        int pruneMax();
        int waterMax();
        int fertiliseMax();
        void prune();
        void water();
        void fertilise();
};

/**
 * @class Rose
 * @brief A derived class representing a rose plant.
 * Inherits from the Plant base class.
 * @details This is the product of the Plant factory method.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * 
 * @author Keegan Lewis
 * @date October 2025
 */
class Rose: public Plant {
    public:
        Rose();
        ~Rose();
};

/**
 * @class Dandelion
 * @brief A derived class representing a dandelion plant.
 * Inherits from the Plant base class.
 * @details This is the product of the Plant factory method.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * 
 * @author Keegan Lewis
 * @date October 2025
 */

class Dandelion: public Plant {
    public:
        /**
         * @brief Constructor for the Dandelion class.
         * Initializes a Dandelion plant with specific attributes.
         */
        Dandelion();
        ~Dandelion();
};

/**
 * @class AppleTree
 * @brief A derived class representing an apple tree.
 * Inherits from the Plant base class.
 * @details This is the product of the Plant factory method.
 * 
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * 
 * @author Keegan Lewis
 * @date October 2025
 */

class AppleTree: public Plant {
    public:
        /**
         * @brief Constructor for the AppleTree class.
         * Initializes an AppleTree plant with specific attributes.
         */
        AppleTree();
        ~AppleTree();
};



#endif // PLANT_H

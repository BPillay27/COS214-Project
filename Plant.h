#ifndef PLANT_H
#define PLANT_H
//Wait to see dependencies --- IGNORE ---
#include "Gardener.h"

#include "Maturity.h"
#include "OrderComponent.h"
#include "GreenHouseCare.h"
#include "Topiary.h"
#include "Kokedama.h"
#include "Espalier.h"
#include "Bonsai.h"
#include "Request.h"
#include <string>
#include <iostream> 
using namespace std;

class Gardener;
class Condition;
class Maturity;
class GreenHouseCare;
/**
 * @file Plant.h
 * @class Plant
 * @ingroup Plant decorator
 * @ingroup Order Composite
 * @ingroup Maturity
 * @ingroup Condition
 * @ingroup Plants
 * @ingroup Plant Factory Method
 *
 * @brief A base class representing a generic plant.
 * This class serves as a foundation for specific plant types.
 * @author Keegan Lewis
 * @date October 2025
 */


class Plant : public OrderComponent {
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
        GreenHouseCare* careStrategy;
    public:
        
        Plant(string name,int growth,int water,int nutrition, int lifeCycle[4],int price);
        
       void setCondition(Condition* condition);
       void setLifeStage(Maturity* life);
       void grow();
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
        bool toPrune();
        bool toWater();
        bool toFertilise();
        void setGardener(Gardener* gardener);
        int* getLifeIntervals();
        Plant* getPlant();
        int getWaterLevel() const;
        int getGrowth() const;
        int getSoilNutrition() const;
        bool isResourcesDepleted();
        int getLifeTime();
        OrderComponent* getChild(int index);
        int getPrice();
        void add(OrderComponent* toAdd);
        OrderComponent* remove(OrderComponent* toRemove);
        void examine(bool j);
};

/**
 * @class Rose
 * @brief A derived class representing a rose plant.
 * Inherits from the Plant base class.
 * @details This is the product of the Plant factory method.
 * 
 * @ingroup Plant decorator
 * @ingroup Order Composite
 * @ingroup Maturity
 * @ingroup Condition
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
 * @ingroup Plant decorator
 * @ingroup Order Composite
 * @ingroup Maturity
 * @ingroup Condition
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
 * @ingroup Plant decorator
 * @ingroup Order Composite
 * @ingroup Maturity
 * @ingroup Condition
 * @ingroup Plants
 * @ingroup Plant Factory Method
 * 
 * @author Keegan Lewis
 * @date October 2025
 */

class AppleTree: public Plant {
    public:
        AppleTree();
        ~AppleTree();
};


#include "Condition.h"
#endif // PLANT_H
#ifndef REQUEST_H
#define REQUEST_H


#include <iostream>
class Gardener;
class Salesman;
class InventoryManager;
class plant;
/**
 * @file Request.h
 * @ingroup Requests
 * @class Requests
 * @brief Base class for request that are sent internally
 * @author Keegan Lewis
 * @date October 2025
 */
class Requests{
    private: 
        std::string type;
    public:
        virtual void execute()=0;
        virtual void setParam(Gardener* me){};
        virtual void setParam(Salesman* me){};
        virtual void setParam(InventoryManager* me){};
        Requests(std::string myType){
            type=myType;
        };
        std::string getType(){
            return type;
        }

};

/**
 * @ingroup Requests
 * @class Place
 * @brief Class representing a place request
 * @author Keegan Lewis
 * @date October 2025
 */
class Place : public Requests{
    private:
        Plant* plant;
        Gardener* param;
    public:
        Place(Plant* plant);
        void setParam(Gardener* me);
        void execute();
};

/**
 * @ingroup Requests
 * @class Water
 * @brief Class representing a water request
 * @author Keegan Lewis
 * @date October 2025
 */
class Water : public Requests{
    private:
        Plant* plant;
    public:
        Water(Plant* plant);
        void execute();
};

/**
 * @ingroup Requests
 * @class Fertilize
 * @brief Class representing a fertilize request
 * @author Keegan Lewis
 * @date October 2025
 */
class Fertilise : public Requests{
    private:
        Plant* plant;
    public:
        Fertilise(Plant* plant);
        void execute();
};
/**
 * @ingroup Requests
 * @class Prune
 * @brief Class representing a prune request
 * @author Keegan Lewis
 * @date October 2025
 */

class Prune : public Requests{
    private:
        Plant* plant;
    public:
        Prune(Plant* plant);
        void execute();
};

#include "Plant.h"
#endif
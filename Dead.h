#ifndef DEAD_H
#define DEAD_H

class Plant;
#include <string>
#include "Maturity.h"
#include "Condition.h"

//Double inheritance from Maturity and Condition
/**
 * @class DeadPlant
 * @brief Represents a dead plant with its decomposition stages.
 * @ingroup Condition
 * @ingroup Maturity
 * @author Tshepiso Makelana
 * @date 26 October 2025
 **/
class DeadPlant : public Maturity, public Condition {
    public:
        DeadPlant(Plant* plant);
        ~DeadPlant();
        void grow() override;
        bool canSale() override;
        std::string lifeCycle() override;
};


#endif // DEAD_H
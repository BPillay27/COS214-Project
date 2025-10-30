#ifndef DEAD_H
#define DEAD_H

class Plant;
#include <string>
#include "Maturity.h"
#include "Condition.h"

//Double inheritance from Maturity and Condition
/**
 * @class Dead
 * @brief Represents a dead plant with its decomposition stages.
 * @ingroup Condition
 * @ingroup Maturity
 * @author Tshepiso Makelana
 * @date 26 October 2025
 **/
class Dead : public Maturity, public Condition {
    public:
        Dead(Plant* plant);
        ~Dead();
        void grow() override;
        void examine(bool shouldDegrade) override;
        bool canSale() override;
        std::string lifeCycle() override;
};


#endif // DEAD_H
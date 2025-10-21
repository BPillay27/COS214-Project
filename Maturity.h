#ifndef MATURITY_H
#define MATURITY_H

class Plant;
#include <string>

/**
 * @class Maturity
 * @brief An abstract base class representing the maturity state of a plant.
 * This class defines the interface for different maturity states.
 * @ingroup Maturity
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class Maturity {
    protected:
        Plant* mPlant;
    public:
    Maturity(Plant* plant);
    virtual ~Maturity();
    virtual void grow() = 0;
    virtual bool canSale() = 0;
    virtual std::string lifeCycle() = 0;
};

/**
 * @class Seed
 * @brief Represents the seed stage of a plant's maturity.
 * @ingroup Maturity
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class Seed : public Maturity {
    public:
        Seed(Plant* plant);
        ~Seed();
        void grow() override;
        bool canSale() override;
        std::string lifeCycle() override;
};

class Sprout : public Maturity {
    public:
        Sprout(Plant* plant);
        ~Sprout();
        void grow() override;
        bool canSale() override;
        std::string lifeCycle() override;
};

class Seedling : public Maturity {
    public:
        Seedling(Plant* plant);
        ~Seedling();
        void grow() override;
        bool canSale() override;
        std::string lifeCycle() override;
};

class Mature : public Maturity {
    public:
        Mature(Plant* plant);
        ~Mature();
        void grow() override;
        bool canSale() override;
        std::string lifeCycle() override;
};

#include "Plant.h"

#endif // MATURITY_H
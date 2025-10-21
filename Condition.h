#ifndef CONDITION_H
#define CONDITION_H

class Plant;

/**
 * @class Condition
 * @brief An abstract base class representing the health condition state of a plant.
 * This class defines the interface for different condition states.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class Condition {
    protected:
        Plant* cPlant;
        void adjustGrowth(int amount);
        void adjustWater(int amount);
        void adjustNutrition(int amount);

    public:
    Condition(Plant* plant);
    virtual ~Condition();
    virtual void examine() = 0;
};

/**
 * @class Healthy
 * @brief Represents a healthy condition state of a plant.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class Healthy : public Condition {
    public:
        Healthy(Plant* plant);
        ~Healthy();
        void examine() override;
};

/**
 * @class Dehydrated
 * @brief Represents a dehydrated condition state of a plant.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class Dehydrated : public Condition {
    public:
        Dehydrated(Plant* plant);
        ~Dehydrated();
        void examine() override;
};

/**
 * @class DehydratedOverGrown
 * @brief Represents a dehydrated and overgrown condition state of a plant.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class DehydratedOverGrown : public Condition {
    public:
        DehydratedOverGrown(Plant* plant);
        ~DehydratedOverGrown();
        void examine() override;
};

/**
 * @class DehydratedMalnurished
 * @brief Represents a dehydrated and malnourished condition state of a plant.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class DehydratedMalnurished : public Condition {
    public:
        DehydratedMalnurished(Plant* plant);
        ~DehydratedMalnurished();
        void examine() override;
};

/**
 * @class DehydratedMalnurishedOverGrown
 * @brief Represents a dehydrated, malnourished, and overgrown condition state of a plant.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class DehydratedMalnurishedOverGrown : public Condition {
    public:
        DehydratedMalnurishedOverGrown(Plant* plant);
        ~DehydratedMalnurishedOverGrown();
        void examine() override;
};

/**
 * @class Malnurished
 * @brief Represents a malnourished condition state of a plant.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class Malnurished : public Condition {
    public:
        Malnurished(Plant* plant);
        ~Malnurished();
        void examine() override;
};

/**
 * @class MalnurishedOverGrown
 * @brief Represents a malnourished and overgrown condition state of a plant.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class MalnurishedOverGrown : public Condition {
    public:
        MalnurishedOverGrown(Plant* plant);
        ~MalnurishedOverGrown();
        void examine() override;
};

/**
 * @class OverGrown
 * @brief Represents an overgrown condition state of a plant.
 * @ingroup Condition
 * @author Tshepiso Makelana
 * @date 21 October 2025
 */
class OverGrown : public Condition {
    public:
        OverGrown(Plant* plant);
        ~OverGrown();
        void examine() override;
};

#include "Plant.h"

#endif // CONDITION_H
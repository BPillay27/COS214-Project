#ifndef CONDITION_H
#define CONDITION_H

<<<<<<< HEAD
class Condition {
    // Intentionally empty for now
};

=======
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


        // Helper methods for natural resource degradation
        void degradeWater();
        void degradeNutrition();

    public:
    Condition(Plant* plant);
    virtual ~Condition();
    virtual void examine(bool shouldDegrade) = 0;
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
        void examine(bool shouldDegrade) override;
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
        void examine(bool shouldDegrade) override;
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
        void examine(bool shouldDegrade) override;
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
        void examine(bool shouldDegrade) override;
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
        void examine(bool shouldDegrade) override;
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
        void examine(bool shouldDegrade) override;
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
        void examine(bool shouldDegrade) override;
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
        void examine(bool shouldDegrade) override;
};

#include "Plant.h"

>>>>>>> 97a76819fd95c2d82e754bed2ee80657500dc9d4
#endif // CONDITION_H
#ifndef GREEN_HOUSE_CARE_H
#define GREEN_HOUSE_CARE_H

// Forward declaration of Plant to avoid circular dependency
// This allows us to use Plant* as a parameter.
class Plant;

class GreenHouseCare {
public:
    virtual ~GreenHouseCare() = default;

    /**
     * @brief Defines the watering logic for a specific strategy.
     * @param plant A pointer to the Plant (Context) to operate on.
     */
    virtual void water(Plant* plant) = 0;

    /**
     * @brief Defines the pruning logic for a specific strategy.
     * @param plant A pointer to the Plant (Context) to operate on.
     */
    virtual void prune(Plant* plant) = 0;

    /**
     * @brief Defines the fertilising logic for a specific strategy.
     * @param plant A pointer to the Plant (Context) to operate on.
     */
    virtual void fertilise(Plant* plant) = 0;
};

#endif // GREEN_HOUSE_CARE_H
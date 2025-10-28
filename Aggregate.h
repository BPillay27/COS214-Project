#ifndef AGGREGATE_H
#define AGGREGATE_H

#include <vector>
#include <string>
#include <algorithm>

class Plant;
class PlantRow;
template <typename T>
class Iterator;

/**
 * @defgroup Aggregates
 * @ingroup IteratorPattern
 * @brief Abstract base class for Aggregate containers.
 */

/**
 * @defgroup ConcreteAggregates
 * @ingroup IteratorPattern
 * @details Concrete containers for the Iterator Pattern.
 */

 /**
  * @class Aggregate
  * @ingroup Aggregates
  * @brief Abstract container class.
  * @tparam T Template type.
  */
template <typename T>
class Aggregate
{
public:
    Aggregate() = default; ///< Default constructor.
    virtual ~Aggregate() = default; ///< Default destructor.
    virtual bool addPlant(Plant *toAdd) = 0; ///< Pure virutal method to add a `Plant`.
    virtual Iterator<T> *createIterator() = 0; ///< Pure virtual method to create an `Iterator`.
};

/**
 * @class PlantArea
 * @details Subclass of the Aggregate class. This class is a Concrete Aggregate which holds the rows of the 2D array.
 * @ingroup ConcreteAggregates
 */
class PlantArea : public Aggregate<PlantRow *>
{
public:
    Iterator<PlantRow *> *createIterator() override; ///< Returns an Iterator for a `PlantRow` container.
    bool addPlant(Plant *toAdd) override; ///< Adds a plant.
    bool removePlant(Plant *toRemove); ///< Removes a plant.
    PlantArea(int capacity); ///< Constructor.
    ~PlantArea() override; ///< Destructor.
    Plant *givePlant(std::string plantType); ///< Finds a mature plant.
    int getCount(); ///< Returns `count`.
    int getCapacity(); ///< Returns `capacity`.
    int getRowTotal(Plant *plant); ///< Gets a rows total.
    void examine(bool con); ///< Examines the plants.
    void grow(); ///< Grows the plants.

private:
    int capacity; ///< Limits amount of plants.
    std::vector<PlantRow *> plantRows; ///< Containes the 2d arrays rows.
    int count; ///< Current amount of plants.
};

/**
 * @class PlantRow
 * @ingroup ConcreteAggregates
 * @details The row of `Plant` objects in the 2d Array. This ConcreteAggregate holds the actual `Plant` references.
 */
class PlantRow : public Aggregate<Plant *>
{
public:
    PlantRow(); ///< Constructor.
    ~PlantRow() override; ///< Destructor.
    int getNumPlants(); ///< Gets the number of plants.
    bool addPlant(Plant *toAdd) override; ///< Adds a plant.
    bool removePlant(Plant *toRemove); ///< Removes a plant.
    std::string typePlant(); ///< Returns the plants type.
    Plant *givePlant(); ///< Returns a mature plant.
    Iterator<Plant *> *createIterator() override; ///< Creates an `Iterator`.
    void examine(bool con); ///< Examines the plants.
    void grow(); ///< Grows the plant.

private:
    std::vector<Plant *> plants; ///< Contains the `Plant` references.
};

#endif

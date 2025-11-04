#include "Plant.h"
#include "Iterator.h"
#include "VectorIterator.h"
#include <cstddef>
#include <algorithm>
#include "Aggregate.h"

/**
 * @details Constructor for the `PlantRow` class. Calls the base class, `Aggregate`, contructor.
 */
PlantRow::PlantRow() : Aggregate<Plant *>()
{
    plants.clear();
}

/**
 * @details Destructor for the `PlantRow` class. Iterates over the `plants` vector and deletes the plant.
 */

PlantRow::~PlantRow()
{
    for (Plant *p : plants)
    {
        delete p;
    }

    plants.clear();
}

/**
 * @details This method returns the size of the `plants` array. In context, this is how much of a specific `Plant` is in stock.
 * @returns The size of the `plants` vector.
 */

int PlantRow::getNumPlants()
{
    return static_cast<int>(plants.size());
}

/**
 * @details Method to add a plant to the array. Validates the plant and either places the plant in the appropriate row (If this plant type already had a row) or makes a new row and places the plant there (Plant type has no existing row).
 * @returns This method returns true if the plant was successfully added to the 2D array, and false otherwise.
 * @param toAdd The plant you wish to add to the array.
 */
bool PlantRow::addPlant(Plant *toAdd)
{
    if (toAdd == nullptr)
    {
        return false;
    }

    if (plants.size() == 0)
    {
        plants.push_back(toAdd);
        return true;
    }

    if (plants[0]->getSpecies() == toAdd->getSpecies())
    {
        plants.push_back(toAdd);
        return true;
    }

    return false;
}
/**
 * @details Removes a plant from the `plants` vector.
 * @param toRemove The plant you wish to remove.
 * @returns This method returns true if the plant was removed successfully, and false otherwise.
 */

bool PlantRow::removePlant(Plant *toRemove)
{
    if (toRemove == nullptr)
        return false;

    auto it = std::find(plants.begin(), plants.end(), toRemove);

    if (it == plants.end())
        return false;

    delete *it;
    plants.erase(it);
    return true;
}

/**
 * @details This method returns the type of plants this row is holding. Each row in the 2D array holds a specific plant type.
 * @returns Will return an empty string if the vector is empty, otherwise return `plants[0]->getSpecies()`.
 */

std::string PlantRow::typePlant()
{
    return (plants.empty()) ? "" : plants[0]->getSpecies();
}

/**
 * @details Fetches the first plant in this row which is mature.
 * @returns A Mature plant or nullptr if one cannot be found.
 */

Plant *PlantRow::givePlant()
{
    for (size_t i = 0; i < plants.size(); i++)
    {
        if (plants[i]->canSale())
        {
            Plant* p = plants[i];
            plants.erase(plants.begin() + i);  // Remove from container without deleting
            return p;
        }
    }

    return nullptr;
}

/**
 * @brief Creates an Iterator for the `plants' vector.
 * @returns `new VectorIterator<Plant *>(plants)`
 */

Iterator<Plant *> *PlantRow::createIterator()
{
    return new VectorIterator<Plant *>(plants);
}

/**
 * @brief Calls `examine(con) on each plant in the row.
 * @param con The condition for the examine method.
 */

void PlantRow::examine(bool con)
{
    for (Plant *p : plants)
    {
        p->examine(con);
    }
}

/**
 * @brief Calls grow on each plant in the row.
 */

void PlantRow::grow()
{
    // Use index-based loop to handle plants being removed during iteration
    for (size_t i = 0; i < plants.size(); )
    {
        Plant* p = plants[i];
        size_t sizeBefore = plants.size();
        p->grow();
        // If plant was removed (e.g., died), don't increment i
        if (plants.size() < sizeBefore) {
            // Plant was removed, i now points to next plant
            continue;
        }
        // Plant still exists, move to next
        i++;
    }
}

/**
 * @details Conctructor for the PlantArea class. Calls the base class, `Aggregate`, constructor.
 * @param capacity The maximum holding capacity of the whole 2D array.
 */

PlantArea::PlantArea(int capacity) : Aggregate<PlantRow *>()
{
    this->capacity = capacity;
    plantRows.clear();
    count = 0;
}

/**
 * @details Destructor for the PlantArea class. Deletes each row in the `plantRows` vector.
 */

PlantArea::~PlantArea()
{
    for (PlantRow *p : plantRows)
    {
        delete p;
    }

    plantRows.clear();
}

/**
 * @details Creates an Iterator for the `plantRows` vector.
 * @returns `new VectorIterator<PlantRow *>(plantRows)`
 */

Iterator<PlantRow *> *PlantArea::createIterator()
{
    return new VectorIterator<PlantRow *>(plantRows);
}

/**
 * @details Method to add a plant to the 2D array. This method begins by validating the given plant. Then, a row for this plant type is searched for. If found, `p->addPlant(toAdd)` is called, otherwise a new row is created for this new plant type and the plant is added there.
 * @returns This method returns true if the plant was successfully added to the 2D array and false otherwise.
 * @param toAdd The plant you wish to add to the 2D array.
 */

bool PlantArea::addPlant(Plant *toAdd)
{
    // validation
    if (toAdd == nullptr || count + 1 > capacity)
        return false;

    ++count;
    // checking if a row for this plant type already exists. If so, adds the plant.
    for (PlantRow *p : plantRows)
    {
        if (p->typePlant() == toAdd->getSpecies())
        {
            p->addPlant(toAdd);
            return true;
        }
    }

    // adding new row, then adding the plant.
    PlantRow *temp = new PlantRow();
    temp->addPlant(toAdd);
    plantRows.push_back(temp);
    return true;
}

/**
 * @brief Method to remove a plant.
 * @returns This method returns true if the plant was successfully removed, and false otherwise.
 * @param toRemove The plant you wish to remove.
 */

bool PlantArea::removePlant(Plant *toRemove)
{
    if (count == 0 || toRemove == nullptr)
        return false;

    for (PlantRow *pr : plantRows)
    {
        if (pr->typePlant() == toRemove->getSpecies())
        {
            if (pr->removePlant(toRemove))
            {
                --count;
                return true;
            }
        }
    }

    return false;
}

/**
 * @brief Redirects this method call to the appropriate row.
 * @returns The first mature plant of a specific type or nullptr if one cannot be found.
 * @param plantType The species of the plant you wish to find a mature plant of.
 */

Plant *PlantArea::givePlant(std::string plantType)
{
    for (PlantRow *pr : plantRows)
    {
        if (pr->typePlant() == plantType)
        {
            Plant* plant = pr->givePlant();
            if (plant != nullptr) {
                --count;  // Decrement count when giving away a plant
            }
            return plant;
        }
    }

    return nullptr;
}

/**
 * @brief Gets the count variable
 * @returns `count`.
 */

int PlantArea::getCount()
{
    return count;
}

/**
 * @brief Gets the capacity variable.
 * @returns `capacity`
 */

int PlantArea::getCapacity()
{
    return capacity;
}

/**
 * @details Finds the appropriate row and fetches its total plants.
 * @param plant The plant species you wish to get the total of.
 * @returns -1 if the plant does not have a corresponding row. Otherise, the size of that rows `plants` array via `pr->getNumPlants()`.
 */

int PlantArea::getRowTotal(Plant *plant)
{
    for (PlantRow *pr : plantRows)
    {
        if (pr->typePlant() == plant->getSpecies())
        {
            return pr->getNumPlants();
        }
    }

    return -1;
}

/**
 * @details Examines all plants in the 2D array.
 * @param con The condition variable required.
 */

void PlantArea::examine(bool con)
{
    for (PlantRow *pr : plantRows)
    {
        pr->examine(con);
    }
}

/**
 * @details Calls grow on all plants in the 2D array.
 */

void PlantArea::grow()
{
    // Use index-based loop to handle vector reallocation during iteration
    for (size_t i = 0; i < plantRows.size(); i++)
    {
        plantRows[i]->grow();
    }
}

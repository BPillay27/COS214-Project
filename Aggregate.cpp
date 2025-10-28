#include "Plant.h"
#include "Iterator.h"
#include "VectorIterator.h"
#include <cstddef>
#include <algorithm>
#include "Aggregate.h"

PlantRow::PlantRow() : Aggregate<Plant *>()
{
    plants.clear();
}

PlantRow::~PlantRow()
{
    for (Plant *p : plants)
    {
        delete p;
    }

    plants.clear();
}

int PlantRow::getNumPlants()
{
    return static_cast<int>(plants.size());
}

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

std::string PlantRow::typePlant()
{
    return (plants.empty()) ? "" : plants[0]->getSpecies();
}

Plant *PlantRow::givePlant()
{
    for (Plant *p : plants)
    {
        if (p->canSale())
            return p;
    }

    return nullptr;
}

Iterator<Plant *> *PlantRow::createIterator()
{
    return new VectorIterator<Plant *>(plants);
}

void PlantRow::examine(bool con)
{
    for (Plant *p : plants)
    {
        p->examine(con);
    }
}

void PlantRow::grow()
{
    for (Plant *p : plants)
    {
        p->grow();
    }
}

PlantArea::PlantArea(int capacity) : Aggregate<PlantRow *>()
{
    this->capacity = capacity;
    plantRows.clear();
    count = 0;
}

PlantArea::~PlantArea()
{
    for (PlantRow *p : plantRows)
    {
        delete p;
    }

    plantRows.clear();
}

Iterator<PlantRow *> *PlantArea::createIterator()
{
    return new VectorIterator<PlantRow *>(plantRows);
}

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

Plant *PlantArea::givePlant(std::string plantType)
{
    for (PlantRow *pr : plantRows)
    {
        if (pr->typePlant() == plantType)
        {
            return pr->givePlant();
        }
    }

    return nullptr;
}

int PlantArea::getCount()
{
    return count;
}

int PlantArea::getCapacity()
{
    return capacity;
}

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

void PlantArea::examine(bool con)
{
    for (PlantRow *pr : plantRows)
    {
        pr->examinePlant(con);
    }
}

void PlantArea::grow()
{
    for (PlantRow *pr : plantRows)
    {
        pr->growPlant();
    }
}

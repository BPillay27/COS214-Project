#ifndef AGGREGATE_H
#define AGGREGATE_H

#include <vector>
#include <string>
#include <algorithm>

class Plant;
class PlantRow;
template <typename T>
class Iterator;

template <typename T>
class Aggregate
{
public:
    Aggregate() = default;
    virtual ~Aggregate() = default;
    virtual bool addPlant(Plant *toAdd) = 0;
    virtual Iterator<T> *createIterator() = 0;
};

class PlantArea : public Aggregate<PlantRow*>
{
    public:
    Iterator<PlantRow*>* createIterator() override;
    bool addPlant(Plant* toAdd) override;
    bool removePlant(Plant* toRemove);
    PlantArea(int capacity);
    ~PlantArea() override;
    Plant* givePlant(std::string plantType);
    int getCount();
    int getCapacity();
    int getRowTotal(Plant *plant);

    private:
    int capacity;
    std::vector<PlantRow*> plantRows;
    int count;
};

class PlantRow : public Aggregate<Plant *>
{
public:
    PlantRow();
    ~PlantRow() override;
    int getNumPlants();
    bool addPlant(Plant *toAdd) override;
    bool removePlant(Plant *toRemove);
    std::string typePlant();
    Plant *givePlant();
    Iterator<Plant *> *createIterator() override;

private:
    std::vector<Plant *> plants;
};

#endif

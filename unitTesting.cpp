#include "Iterator.h"
#include "Aggregate.h"
#include "VectorIterator.h"
#include "Plant.h"

bool testAggregate()
{
    bool ok = true;

    PlantArea *area = new PlantArea(5);

    Plant *rose = new Rose();
    Plant *dand = new Dandelion();
    Plant *apple = new AppleTree();

    if (!area->addPlant(rose))
        ok = false;
    if (!area->addPlant(dand))
        ok = false;
    if (!area->addPlant(apple))
        ok = false;

    if (area->getCount() != 3)
        ok = false;

    // Grow twice so AppleTree can mature too
    area->grow();
    area->grow();

    if (area->givePlant("Rose") == nullptr)
        ok = false;
    if (area->givePlant("Dandelion") == nullptr)
        ok = false;
    if (area->givePlant("Apple tree") == nullptr)
        ok = false;

    delete area; // This should delete rows and owned Plant*'s

    return ok;
}

int main()
{
    testAggregate();
}
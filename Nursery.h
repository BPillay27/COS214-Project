#ifndef NURSERY_H
#define NURSERY_H

#include "Plant.h"
#include <vector>

class Nursery {
private:
    std::vector<Plant*> plants;
    int capacity;

public:
    Nursery(int capacity);
    bool addPlant(Plant* plant);
    void removePlant(Plant* plant);
    bool space();
};

#endif
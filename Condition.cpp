#include "Condition.h"

Condition::Condition(Plant* plant) : cPlant(plant) {

}

Condition::~Condition() {

}

void Condition::adjustGrowth(int amount) {
    cPlant->addGrowth(amount);
}

void Condition::adjustWater(int amount) {
    cPlant->addWater(amount);
}

void Condition::adjustNutrition(int amount) {
    cPlant->addNutrition(amount);
}

// Healthy class
Healthy::Healthy(Plant* plant) : Condition(plant) {

}

Healthy::~Healthy() {

}

void Healthy::examine() {
    //If plant is healthy, no adjustments needed.

    //go to dehydrated state if water level is low
    if (toWater()) {
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    //go to malnurished state if nutrition level is low
    else if (toFertilise()) {
        cPlant->setCondition(new Malnurished(cPlant));
    }
    //go to overgrown state if growth level is high
    else if (toPRune()) {
        cPlant->setCondition(new OverGrown(cPlant));
    }
}

// Dehydrated class
Dehydrated::Dehydrated(Plant* plant) : Condition(plant) {

}

Dehydrated::~Dehydrated() {

}

void Dehydrated::examine() {
    //if the water levels are restored, go back to healthy
    if (!toWater()) {
        cPlant->setCondition(new Healthy(cPlant));    
    }
    //if the plant is also malnurished, go to DehydratedMalnurished state
    else if (toFertilise()) {
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    //if the plant is also overgrown, go to DehydratedOverGrown state
    else if (toPRune()) {
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
}

// DehydratedOverGrown class
DehydratedOverGrown::DehydratedOverGrown(Plant* plant) : Condition(plant) {

}

DehydratedOverGrown::~DehydratedOverGrown() {

}

void DehydratedOverGrown::examine() {
    //if water levels are restored, go to OverGrown state
    if (!toWater()) {
        cPlant->setCondition(new OverGrown(cPlant));
    }
    //if overgrowth is fixed, go to Dehydrated state
    else if (!toPRune()) {
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    //if plant also malnutrished, go to DehydratedMalnurishedOverGrown state
    else if (toFertilise()) {
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }
}

// DehydratedMalnurished class
DehydratedMalnurished::DehydratedMalnurished(Plant* plant) : Condition(plant) {

}

DehydratedMalnurished::~DehydratedMalnurished() {

}

void DehydratedMalnurished::examine() {

    //if all restored, go to Healthy state
    if (!toWater() && !toFertilise()) {
        cPlant->setCondition(new Healthy(cPlant));
    }
    //if plane water levels are restored, go to Malnurished state
    if (!toWater()) {
        cPlant->setCondition(new Malnurished(cPlant));
    }
    //if nutrition levels are restored, go to Dehydrated state
    else if (!toFertilise()) {
        cPlant->setCondition(new Dehydrated(cPlant));
    }
    //if plant also overgrown, go to DehydratedMalnurishedOverGrown state
    else if (toPRune()) {
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }

    
}

// DehydratedMalnurishedOverGrown class
DehydratedMalnurishedOverGrown::DehydratedMalnurishedOverGrown(Plant* plant) : Condition(plant) {

}

DehydratedMalnurishedOverGrown::~DehydratedMalnurishedOverGrown() {

}

void DehydratedMalnurishedOverGrown::examine() {
    //if the plant water levels are restored, go to MalnurishedOverGrown state
    if (!toWater()) {
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    //if nutrition levels are restored, go to DehydratedOverGrown state
    else if (!toFertilise()) {
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }
    //if overgrowth is fixed, go to DehydratedMalnurished state
    else if (!toPRune()) {
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }

    //if all restored, go to Healthy state
    else if (!toWater() && !toFertilise() && !toPRune()) {
        cPlant->setCondition(new Healthy(cPlant));
    }
}

//Malnurished class
Malnurished::Malnurished(Plant* plant) : Condition(plant) {

}

Malnurished::~Malnurished() {

}

void Malnurished::examine() {
    //if the nutrition levels are restored, go back to healthy
    if (!toFertilise()) {
        cPlant->setCondition(new Healthy(cPlant));    
    }
    //if the plant is also dehydrated, go to DehydratedMalnurished state
    else if (toWater()) {
        cPlant->setCondition(new DehydratedMalnurished(cPlant));
    }
    //if the plant is also overgrown, go to MalnurishedOverGrown state
    else if (toPRune()) {
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
}

//Malnurished OverGrown class
MalnurishedOverGrown::MalnurishedOverGrown(Plant* plant) : Condition(plant) {

}

MalnurishedOverGrown::~MalnurishedOverGrown() {

}

void MalnurishedOverGrown::examine() {
    //if overgrowth is fixed, go to Malnurished state
    if (!toPRune()) {
        cPlant->setCondition(new Malnurished(cPlant));
    }
    //if nutrition levels are restored, go to OverGrown state
    else if (!toFertilise()) {
        cPlant->setCondition(new OverGrown(cPlant));
    }
    //if plant also dehydrated, go to DehydratedMalnurishedOverGrown state
    else if (toWater()) {
        cPlant->setCondition(new DehydratedMalnurishedOverGrown(cPlant));
    }

    //if plant is fertilised and pruned, go to Healthy state
    else if (!toFertilise() && !toPRune()) {
        cPlant->setCondition(new Healthy(cPlant));
    }
}

// OverGrown class
OverGrown::OverGrown(Plant* plant) : Condition(plant) {

}

OverGrown::~OverGrown() {

}

void OverGrown::examine() {
    //if overgrowth is fixed, go back to healthy
    if (!toPRune()) {
        cPlant->setCondition(new Healthy(cPlant));
    }
    //if plant also malnourished, go to MalnurishedOverGrown state
    else if (toFertilise()) {
        cPlant->setCondition(new MalnurishedOverGrown(cPlant));
    }
    //if plant also dehydrated, go to DehydratedOverGrown state
    else if (toWater()) {
        cPlant->setCondition(new DehydratedOverGrown(cPlant));
    }

}

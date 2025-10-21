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
    // Plant is healthy, no adjustments needed.
}

// Dehydrated class
Dehydrated::Dehydrated(Plant* plant) : Condition(plant) {

}

Dehydrated::~Dehydrated() {

}

void Dehydrated::examine() {
    // Plant is dehydrated, adjust water levels.
    adjustWater(10);
}

// DehydratedOverGrown class
DehydratedOverGrown::DehydratedOverGrown(Plant* plant) : Condition(plant) {

}

DehydratedOverGrown::~DehydratedOverGrown() {

}

void DehydratedOverGrown::examine() {
    // Plant is dehydrated and overgrown, adjust water and nutrition levels.
    adjustWater(10);
    adjustNutrition(-5);
}

// DehydratedMalnurished class
DehydratedMalnurished::DehydratedMalnurished(Plant* plant) : Condition(plant) {

}

DehydratedMalnurished::~DehydratedMalnurished() {

}

void DehydratedMalnurished::examine() {
    // Plant is dehydrated and malnourished, adjust water and nutrition levels.
    adjustWater(10);
    adjustNutrition(-10);
}

// DehydratedMalnurishedOverGrown class
DehydratedMalnurishedOverGrown::DehydratedMalnurishedOverGrown(Plant* plant) : Condition(plant) {

}

DehydratedMalnurishedOverGrown::~DehydratedMalnurishedOverGrown() {

}

void DehydratedMalnurishedOverGrown::examine() {
    // Plant is dehydrated, malnourished, and overgrown, adjust water, nutrition, and growth levels.
    adjustWater(10);
    adjustNutrition(-10);
    adjustGrowth(-5);
}

//Malnurished class
Malnurished::Malnurished(Plant* plant) : Condition(plant) {

}

Malnurished::~Malnurished() {

}

void Malnurished::examine() {
    // Plant is malnourished, adjust nutrition levels.
    adjustNutrition(-10);
}

//Malnurished OverGrown class
MalnurishedOverGrown::MalnurishedOverGrown(Plant* plant) : Condition(plant) {

}

MalnurishedOverGrown::~MalnurishedOverGrown() {

}

void MalnurishedOverGrown::examine() {
    // Plant is malnourished and overgrown, adjust nutrition and growth levels.
    adjustNutrition(-10);
    adjustGrowth(-5);
}

// OverGrown class
OverGrown::OverGrown(Plant* plant) : Condition(plant) {

}

OverGrown::~OverGrown() {

}

void OverGrown::examine() {
    // Plant is overgrown, adjust growth levels.
    adjustGrowth(-5);
}

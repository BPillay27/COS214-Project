#include "Plant.h"

Plant::Plant(std::string name, int growth, int water, int nutrition, int lifeCycle[4], int price) {
    this->species = name;
    this->growth[0] = growth;
    this->growth[1] = 100; // Max growth
    this->waterLevel[0] = water;
    this->waterLevel[1] = 100; // Max water
    this->soilNutrition[0] = nutrition;
    this->soilNutrition[1] = 100; // Max nutrition
    for (int i = 0; i < 4; ++i) {
        this->lifeIntervals[i] = lifeCycle[i];
    }
    this->lifeTime = 0;
    this->gardener = nullptr;
    this->condition = nullptr;
    this->maturity = nullptr;
    this->careStrategy = nullptr;
}

Plant::~Plant() {}

void Plant::water() {
    this->waterLevel[0] += 10;
    if (this->waterLevel[0] > this->waterLevel[1]) {
        this->waterLevel[0] = this->waterLevel[1];
    }
}

void Plant::prune() {
    this->growth[0] -= 5;
    if (this->growth[0] < 0) {
        this->growth[0] = 0;
    }
}

void Plant::fertilise() {
    this->soilNutrition[0] += 15;
    if (this->soilNutrition[0] > this->soilNutrition[1]) {
        this->soilNutrition[0] = this->soilNutrition[1];
    }
}

std::string Plant::getSpecies() {
    return this->species;
}

int Plant::getWaterLevel() const {
    return this->waterLevel[0];
}

int Plant::getGrowth() const {
    return this->growth[0];
}

int Plant::getSoilNutrition() const {
    return this->soilNutrition[0];
}

// Other method implementations (can be left empty for now)
void Plant::setCondition(Condition* condition) {}
void Plant::setLifeStage(Maturity* life) {}
void Plant::grow() {}
bool Plant::addGrowth(int amount) { return false; }
bool Plant::addWater(int amount) { return false; }
bool Plant::addNutrition(int amount) { return false; }
bool Plant::canSale() { return false; }
std::string Plant::getDetails() { return ""; }
void Plant::notify(std::string request) {}
int Plant::pruneMax() { return 0; }
int Plant::waterMax() { return 0; }
int Plant::fertiliseMax() { return 0; }
bool Plant::toPrune() { return false; }
bool Plant::toWater() { return false; }
bool Plant::toFertilise() { return false; }
void Plant::setGardener(Gardener* gardener) {}
int* Plant::getLifeIntervals() { return nullptr; }
Plant* Plant::getPlant() { return this; }
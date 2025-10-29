#include "Plant.h"

/**
 * @todo Implement the methods of the Plant class and its derived classes.
 */
/**
 * @file Plant.cpp
 * @brief Constructor for the Plant class.
 * @param name The species name of the plant.
 * @param growth The maximum growth level of the plant.
 * @param water The minimum water level of the plant.
 * @param nutrition The minimum soil nutrition level of the plant.
 * @param lifeCycle An array representing the life cycle intervals of the plant.
 */
Plant::Plant(string name,int growth,int water,int nutrition, int lifeCycle[4], int price):OrderComponent(price) {
    species = name;
    this->growth[0] =0;
    this->growth[1] = growth;
    this->waterLevel[0] = water;
    this->waterLevel[1] = water;
    this->soilNutrition[0] = nutrition;
    this->soilNutrition[1] = nutrition;
    for (int i = 0; i < 4; i++) {
        lifeIntervals[i] = lifeCycle[i];
    }
    lifeTime = 0;
}

/**
 * @brief Simulates the growth of the plant and aging process.
 */
void Plant::grow() {
    maturity->grow();
}

/**
 *@brief Sets the condition state for the plant.
 *@param condition Pointer to the new Condition state.
*/
void Plant::setCondition(Condition* condition){
    if(condition==nullptr){
        return;
    }

    if(this->condition!=nullptr){
        Condition* holder=this->condition;
        this->condition=nullptr;
        delete holder;
    }
    this->condition=condition;
}

/**
 * @brief Sets the maturity state for the plant.
 * @param life Pointer to the new Maturity state.
 */
void Plant::setLifeStage(Maturity* life){    
    if(life==nullptr){
        return;
    }

    if(this->maturity!=nullptr){
        Maturity* holder=this->maturity;
        this->maturity=nullptr;
        delete holder;
    }
    this->maturity=life;
}

/**
 * @brief virtual Destructor for the Plant class.
 */
Plant::~Plant() {
    gardener = nullptr;
    if(careStrategy!=nullptr){
        careStrategy=nullptr;
    }
    if(condition!=nullptr){
        delete condition;
    }
    condition = nullptr;
    if(maturity!=nullptr){
        delete maturity;
    }
    maturity = nullptr;

}

/**
 * @brief Adds growth to the plant.
 * @param amount The amount of growth to add. can be negative.
 * @return True if growth was added successfully, false otherwise.
 */

bool Plant::addGrowth(int amount) {
    this->growth[0] += amount;
    return true;
}

/**
 * @brief Adds water to the plant.
 * @param amount The amount of water to add. can be negative.
 * @return True if water was added successfully, false otherwise.
 */

bool Plant::addWater(int amount) {
    this->waterLevel[0] += amount;
    return true;
}

/**
 * @brief Adds nutrition to the plant.
 * @param amount The amount of nutrition to add. can be negative.
 * @return True if nutrition was added successfully, false otherwise.
 */

bool Plant::addNutrition(int amount) {
    this->soilNutrition[0] += amount;
    return true;
}

/**
 * @brief Checks if the plant can be sold. So is it mature.
 * @return True if the plant can be sold, false otherwise.
 */

bool Plant::canSale() {
    if(maturity==nullptr){
        return false;
    }
    return maturity->canSale();
}

/**
 * 
 * @brief Gets the species name of the plant.
 * @return The species name as a string.
 * 
 */

string Plant::getSpecies() {
    return species;
}

/**
 * @brief Gets detailed information about the plant.
 * @return A string containing the plant's details.
 */

string Plant::getDetails() {
    string details = "Species: " + species + "\n";
    details +="Average Life span: " + to_string(lifeIntervals[4]) + " days\n";
    details +="Price: R" + to_string(price) + "\n";
    return details;
}

/**
 * @brief Notifies the plant's observer, the gardener of a request.
 * @param request The request message.
 */

void Plant::notify(string request) {
    if(gardener==nullptr){
        return;
    }
    gardener->update(request);
}

/**
 * @brief Gets the maximum amount the plant can be pruned.
 * @return The maximum prune amount.
 */

int Plant::pruneMax() {
    return this->growth[1];
}

/**
 * @brief Gets the maximum amount of water the plant can receive.
 * @return The maximum water amount.
 */

int Plant::waterMax() {
   return this->waterLevel[1];
}

/**
 * @brief Gets the maximum amount of fertiliser the plant can receive.
 * @return The maximum fertiliser amount.
 */

int Plant::fertiliseMax() {
    return this->soilNutrition[1];    
}

/**
 * @brief Prunes the plant. By calling the plant's strategy prune() method.
 */

void Plant::prune() {
    if(careStrategy==nullptr){
        return;
    }
    careStrategy->prune(this);
}

/**
 * @brief Waters the plant. By calling the plant's strategy water() method.
 */

void Plant::water() {
    if(careStrategy==nullptr){
        return;
    }
    careStrategy->water(this);
}

/**
 * @brief Fertilises the plant. By calling the plant's strategy fertilise() method.
 */

void Plant::fertilise() {
    if(careStrategy==nullptr){
        return;
    }
    careStrategy->fertilise(this);
}

/**
 * @brief Determines if the plant needs pruning.
 * @return True if the plant needs pruning, false otherwise.
 */
bool Plant::toPrune() {
    if (growth[0] >growth[1]) {
        return true;
    }
    return false;
}

/**
 * @brief Determines if the plant needs watering.
 * @return True if the plant needs watering, false otherwise.
 */
bool Plant::toWater() {
    if (waterLevel[0] < waterLevel[1]) {
        return true;
    }
    return false;
}

/**
 * @brief Determines if the plant needs fertilising.
 * @return True if the plant needs fertilising, false otherwise.
 */
bool Plant::toFertilise() {
    if (soilNutrition[0] < soilNutrition[1]) {
        return true;
    }
    return false;
}
/**
 * @brief Sets the gardener observer for the plant.
 * @param gardener Pointer to the Gardener object.
 */
void Plant::setGardener(Gardener* gardener) {
    this->gardener = gardener;
}

/**
 * @brief Gets the life intervals of the plant.
 * @return An array of integers representing the life intervals.
 */
int[4] Plant::getLifeIntervals() {
    return lifeIntervals;
}

/**
 * @brief Gets the current lifetime of the plant.
 * @return The current lifetime in days/intervals.
 */
int Plant::getLifeTime() {
    return lifeTime;
}

/**
 * @brief Allows for the knowledge the OrderComponent is a Plant by being the same address as the one that ha the request.
 * @param index The index of the child component.
 * @return this pointer.
 */

OrderComponent* Plant::getChild(int index) {
    return this;
}

/**
 * @brief Constructor for the Rose class.
 * Initializes a Rose plant with specific attributes.
 * @todo Add specific attributes for Rose. 
 */

Rose::Rose() : Plant("Rose", 20, 30, 20, new int[4]{5, 10, 20, 45}, 50) {

}

/**
 * @brief Destructor for the Rose class.
 */
Rose::~Rose() {

}

/**
 * @brief Constructor for the Dandelion class.
 * Initializes a Dandelion plant with specific attributes.
 * @todo Add specific attributes for Dandelion.
 */
Dandelion::Dandelion() : Plant("Dandelion", 15, 50, 60, new int[4]{5, 15, 25, 35}, 20) {    
    
}

/**
 * @brief Destructor for the Dandelion class.
 */

Dandelion::~Dandelion() {

}

/**
 * @brief Constructor for the AppleTree class.
 * Initializes an AppleTree plant with specific attributes.
 * @todo Add specific attributes for AppleTree.
 */
AppleTree::AppleTree() : Plant("Apple tree", 60, 40, 50, new int[4]{15, 30, 45, 80},120) {
    
}

/**
 * @brief Destructor for the AppleTree class.
 */

AppleTree::~AppleTree() {   

}
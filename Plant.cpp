#include "Plant.h"

/**
 * @todo Implement the methods of the Plant class and its derived classes.
 */
/**
 * @brief Constructor for the Plant class.
 * @param name The species name of the plant.
 * @param growth The maximum growth level of the plant.
 * @param water The minimum water level of the plant.
 * @param nutrition The minimum soil nutrition level of the plant.
 * @param lifeCycle An array representing the life cycle intervals of the plant.
 */
Plant::Plant(string name,int growth,int water,int nutrition, int lifeCycle[4]) {

}

/**
 * @brief Simulates the growth of the plant and aging process.
 */
void Plant::grow() {

}

/**
 *@brief Sets the condition state for the plant.
 *@param condition Pointer to the new Condition state.
*/
void Plant::setCondition(Condition* condition){

}

/**
 * @brief Sets the maturity state for the plant.
 * @param life Pointer to the new Maturity state.
 */
void Plant::setLifeStage(Maturity* life){    

}

/**
 * @brief virtual Destructor for the Plant class.
 */
Plant::~Plant() {

}

bool Plant::addGrowth(int amount) {
    
}

bool Plant::addWater(int amount) {
    
}

bool Plant::addNutrition(int amount) {
    
}

bool Plant::canSale() {
    
}

string Plant::getSpecies() {
    
}

string Plant::getDetails() {
    
}

void Plant::notify(string request) {
    
}

int Plant::pruneMax() {
    
}

int Plant::waterMax() {
    
}

int Plant::fertiliseMax() {
    
}

void Plant::prune() {
    
}

void Plant::water() {
    
}

void Plant::fertilise() {
    
}

/**
 * @brief Constructor for the Rose class.
 * Initializes a Rose plant with specific attributes.
 * @todo Add specific attributes for Rose. 
 */

Rose::Rose() : Plant("Rose", 40, 50, 50, new int[4]{10, 20, 30, 40}) {

}

Rose::~Rose() {

}

/**
 * @brief Constructor for the Dandelion class.
 * Initializes a Dandelion plant with specific attributes.
 * @todo Add specific attributes for Dandelion.
 */
Dandelion::Dandelion() : Plant("Dandelion", 30, 40, 40, new int[4]{5, 15, 25, 35}) {    
    
}

Dandelion::~Dandelion() {

}

/**
 * @brief Constructor for the AppleTree class.
 * Initializes an AppleTree plant with specific attributes.
 * @todo Add specific attributes for AppleTree.
 */
AppleTree::AppleTree() : Plant("AppleTree", 50, 60, 60, new int[4]{15, 30, 45, 60}) {
    
}
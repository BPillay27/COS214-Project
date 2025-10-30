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
    maturity->grow();
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

/**
 * @brief Adds growth to the plant.
 * @param amount The amount of growth to add. can be negative.
 * @return True if growth was added successfully, false otherwise.
 */

bool Plant::addGrowth(int amount) {
    
}

/**
 * @brief Adds water to the plant.
 * @param amount The amount of water to add. can be negative.
 * @return True if water was added successfully, false otherwise.
 */

bool Plant::addWater(int amount) {
    
}

/**
 * @brief Adds nutrition to the plant.
 * @param amount The amount of nutrition to add. can be negative.
 * @return True if nutrition was added successfully, false otherwise.
 */

bool Plant::addNutrition(int amount) {
    
}

/**
 * @brief Checks if the plant can be sold. So is it mature.
 * @return True if the plant can be sold, false otherwise.
 */

bool Plant::canSale() {
    
}

/**
 * 
 * @brief Gets the species name of the plant.
 * @return The species name as a string.
 * 
 */

string Plant::getSpecies() {
    
}

/**
 * @brief Gets detailed information about the plant.
 * @return A string containing the plant's details.
 */

string Plant::getDetails() {
    
}

/**
 * @brief Notifies the plant's observer, the gardener of a request.
 * @param request The request message.
 */

void Plant::notify(string request) {
    
}

/**
 * @brief Gets the maximum amount the plant can be pruned.
 * @return The maximum prune amount.
 */

int Plant::pruneMax() {
    
}

/**
 * @brief Gets the maximum amount of water the plant can receive.
 * @return The maximum water amount.
 */

int Plant::waterMax() {
   
}

/**
 * @brief Gets the maximum amount of fertiliser the plant can receive.
 * @return The maximum fertiliser amount.
 */

int Plant::fertiliseMax() {
    
}

/**
 * @brief Prunes the plant. By calling the plant's strategy prune() method.
 */

void Plant::prune() {
    
}

/**
 * @brief Waters the plant. By calling the plant's strategy water() method.
 */

void Plant::water() {
    
}

/**
 * @brief Fertilises the plant. By calling the plant's strategy fertilise() method.
 */

void Plant::fertilise() {
    
}

/**
 * @brief Constructor for the Rose class.
 * Initializes a Rose plant with specific attributes.
 * @todo Add specific attributes for Rose. 
 */

Rose::Rose() : Plant("Rose", 40, 50, 50, new int[4]{10, 20, 30, 40}) {

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
Dandelion::Dandelion() : Plant("Dandelion", 30, 40, 40, new int[4]{5, 15, 25, 35}) {    
    
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
AppleTree::AppleTree() : Plant("AppleTree", 50, 60, 60, new int[4]{15, 30, 45, 60}) {
    
}

/**
 * @brief Destructor for the AppleTree class.
 */

AppleTree::~AppleTree() {   

}
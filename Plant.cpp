#include "Plant.h"
#include "Inventory.h"

/**
 * @file Plant.cpp
 * @brief Constructor for the Plant class.
 * @param name The species name of the plant.
 * @param growth The maximum growth level of the plant.
 * @param water The minimum water level of the plant.
 * @param nutrition The minimum soil nutrition level of the plant.
 * @param lifeCycle An array representing the life cycle intervals of the plant.
 */
Plant::Plant(string name,int growth,int water,int nutrition, int lifeCycle[3], int price):OrderComponent(price), Subject() {
    species = name;
    this->growth[0] =0;
    this->growth[1] = growth;
    this->waterLevel[0] = water;
    this->waterLevel[1] = water;
    this->soilNutrition[0] = nutrition;
    this->soilNutrition[1] = nutrition;
    for (int i = 0; i < 3; i++) {
        lifeIntervals[i] = lifeCycle[i];
    }
    lifeTime = 0;
    this->gardener = nullptr;
    this->condition = new Healthy(this);
    this->maturity = new Seed(this);
    this->careStrategy = nullptr;
    delete[] lifeCycle;
}

/**
 * @brief Simulates the growth of the plant and aging process.
 */
void Plant::grow() 
{
    lifeTime++;
    if (maturity != nullptr) {
        //Micheal is a bad branch manager
        maturity->grow(); 
    }
}

/**
*@brief runs examine from the condition
*@param j the boolean for the condition param
*/

void Plant::examine(bool j){

    this->condition->examine(j);
}

/**
 *@brief Sets the condition state for the plant.
 *@param condition Pointer to the new Condition state.
*/
void Plant::setCondition(Condition* condition)
{
    if(condition==nullptr)
    {
        return;
    }

    if(this->condition!=nullptr)
    {
        delete this->condition;
        this->condition=nullptr;
    }
    this->condition=condition;
}

/**
 * @brief Sets the maturity state for the plant.
 * @param life Pointer to the new Maturity state.
 */
void Plant::setLifeStage(Maturity* life)
{    
    if(life==nullptr)
    {
        return;
    }

    if(this->maturity!=nullptr)
    {
        delete this->maturity;
        this->maturity=nullptr;
    }
    this->maturity=life;
}

/**
 * @brief virtual Destructor for the Plant class.
 */
Plant::~Plant() {
    gardener = nullptr;
    if(careStrategy!=nullptr){
        delete careStrategy;
        careStrategy=nullptr;
    }
    if(condition!=nullptr)
    {
        delete condition;
        condition = nullptr;
    }
    if(maturity!=nullptr)
    {
        delete maturity;
        maturity = nullptr;
    }
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
    if(maturity==nullptr)
    {
        return false;
    }
    return (lifeTime >= lifeIntervals[2]);
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
    details +="Average Life span: " + to_string(lifeIntervals[3]) + " days\n";
    details +="Price: R" + to_string(price) + "\n";
    return details;
}

/**
 * @brief Notifies the gardener about the request 
 * @param request the request to handle
 */

void Plant::notify(Requests* request){
    gardener->handle(request);
    return;
}

/**
 * @brief Makes the requests for the notify(Request* request)
 * @param request Tells us what request to make
 */

void Plant::notify(string request) {
    /*
    Help me
    */
   if(gardener!=nullptr){
        if(request=="prune"){
            Requests* req=new Prune(this);
            notify(req);
            return;
        }else if(request=="water"){
            Requests* req=new Water(this);
            notify(req);
            return;
        }else if(request=="fertilise"){
            Requests* req=new Fertilise(this);
            notify(req);
            return;
        }else if(request=="dead"){
            Inventory::instance().removeFromNursery(this);
            return;
        }
   }
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
bool Plant::isResourcesDepleted() {
    return (waterLevel[0] <= 0 || soilNutrition[0] <= 0);
}
/**
 * @brief Sets the gardener observer for the plant.
 * @param gardener Pointer to the Gardener object.
 */
void Plant::setGardener(Gardener* gardener) {
    this->gardener = gardener;
}

void Plant::setCare(GreenHouseCare* strategy){
    if(strategy==nullptr)
    {
        return;
    }

    if(this->careStrategy!=nullptr)
    {
        delete this->careStrategy;
        this->careStrategy=nullptr;
    }
    this->careStrategy=strategy;
    return;
}

/**
 * @brief Gets the life intervals of the plant.
 * @return A pointer to an array of integers representing the life intervals.
 */
int* Plant::getLifeIntervals() {
    return lifeIntervals;
}

/**
 * @brief Increments the current lifetime of the plant and returns it to show aging.
 * @return The current lifetime in days/intervals.
 */
int Plant::getLifeTime() {
    ++(this->lifeTime);
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
 * @brief Allows for the knowledge the OrderComponent is a Plant by being the same address as the one that had the request.
 * @return this pointer.
 */
Plant* Plant::getPlant() {
    return this;
}

/**
*@brief Deals with the adding of a OrderComponent
*/

void Plant::add(OrderComponent* toAdd){ }

/**
*@brief Deals with the remove of OrderComponent
*@return Will always return nullptr because it cannot remove anything
*/
OrderComponent* Plant::remove(OrderComponent* toRemove) 
{
    return nullptr; //tras my dis ok
}

/**
*@brief Get the water level of the plant
*@return int of the water level
*/
int Plant::getWaterLevel() const {
    return this->waterLevel[0];
}

/**
*@brief Gives the growth of the plant
*@return int of the plant's growth
*/

int Plant::getGrowth() const {
    return this->growth[0];
}

/**
*@brief Get the soil nutrition of the plant
*@return int of the soil nutrition of the plant
*/

int Plant::getSoilNutrition() const {
    return this->soilNutrition[0];
}

/**
*@brief Removes the plant from the inventory of nursery because it got sold
*@return void
*/

void Plant::success(){
    Inventory::instance().removeFromNursery(this);
    return;
}

/**
 * @brief Constructor for the Rose class.
 * Initializes a Rose plant with specific attributes.
 */

Rose::Rose() : Plant("Rose", 20, 15, 20, new int[3]{5, 10, 20}, 50) {

}

/**
 * @brief Destructor for the Rose class.
 */
Rose::~Rose() {

}

/**
 * @brief Constructor for the Dandelion class.
 * Initializes a Dandelion plant with specific attributes.
 */
Dandelion::Dandelion() : Plant("Dandelion", 15, 25, 30, new int[3]{5, 15, 25}, 20) {    
    
}

/**
 * @brief Destructor for the Dandelion class.
 */

Dandelion::~Dandelion() {

}

/**
 * @brief Constructor for the AppleTree class.
 * Initializes an AppleTree plant with specific attributes.
 */
AppleTree::AppleTree() : Plant("Apple tree", 60, 20, 35, new int[3]{15, 30, 45},120) {
    
}

/**
 * @brief Destructor for the AppleTree class.
 */

AppleTree::~AppleTree() {   

}

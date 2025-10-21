#include "Order.h"
#include "Command.h"

/**
 * @details Constructor for the AddToOrder class. Calls the base cosntructor and sets the parameters to the appropriate member variables.
 * @param order The `Order` you wish to add an item to.
 * @param toAdd The item you wish to add to `order`.
 */

AddToOrder::AddToOrder(Order *order, OrderComponent *toAdd) : Command()
{
    this->order = order;
    this->toAdd = toAdd;
}

/**
 * @details Executes the AddToOrder Command. This calls `order->AddToOrder(toAdd)`.
 */

void AddToOrder::execute()
{
    order->AddToOrder(toAdd);
}

/**
 * @details Constructor for the RemoveFromOrder class. Calls the base cosntructor and sets the parameters to the appropriate member variables.
 * @param order The `Order` you wish to remove an item from.
 * @param toRemove The item you wish to remove from `order`.
 */

RemoveFromOrder::RemoveFromOrder(Order *order, OrderComponent *toRemove) : Command()
{
    this->order = order;
    this->toRemove = toRemove;
}

/**
 * @details Execute method for the RemoveFromOrder Command. Calls `order->RemoveFromOrder(toRemove)`.
 */
void RemoveFromOrder::execute()
{
    order->RemoveFromOrder(toRemove);
}

/**
 * @brief Destructor for the `AddToOrder` Command. Does not free any dynamically allocated memory.
 */

AddToOrder::~AddToOrder()
{
}

/**
 * @brief Destructor for the `RemoveFromOrder` Command. Does not free any dynamically allocated memory.
 */

RemoveFromOrder::~RemoveFromOrder()
{
}

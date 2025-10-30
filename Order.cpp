#include "Order.h"
#include "Arrangement.h"
#include "OrderComponent.h"
#include "OrderState.h"

/**
 * @details Constructor for the `Order` class. Sets id to the parameter and initialises state to VerifyOrder.
 * @param id The identifier for the `Order`.
 */

Order::Order(std::string id)
{
    this->id = id;
    state = new VerifyOrder(this);
    items = new Arrangement(0);
}

/**
 * @details Destructor for the Order class. Frees memory for the state and items.
 */

Order::~Order()
{
    // TODO : Complete Implementation
    // Unclear who is responsible for deleting items yet.
    if (state != nullptr)
    {
        delete state;
        state = nullptr;
    }

    if (items != nullptr)
    {
        delete items;
        items = nullptr;
    }
}

/**
 * @details Implementation of the AddToOrder functionality called by the `AddToOrder` Command.
 * @param item The item to add to the `Order`.
 */

void Order::AddToOrder(OrderComponent *item)
{
    items->add(item);
}

/**
 * @details Implementation of the RemoveFromOrder functionality called by the `RemoveFromOrder` Command.
 * @param item The item to remove from `Order`.
 */

void Order::RemoveFromOrder(OrderComponent *item)
{
    items->remove(item);
}

/**
 * @brief Method for state transitions.
 * @param state The state you wish to transition to.
 */

void Order::setState(OrderState *state)
{
    if (this->state == state)
        return;

    if (this->state != nullptr)
        delete this->state;
    this->state = state;
}

/**
 * @brief Getter method for the `state` variable.
 */

OrderState *Order::getState()
{
    return state;
}

/**
 * @details This method begins the payment process. Sets the state to `VerifyOrder` and calls `state->handle()`.
 */

void Order::processPayment()
{
    OrderState *temp = new VerifyOrder(this);
    setState(temp);
    state->handle();
}

/**
 * @brief Getter method for the `items` variable.
 */

OrderComponent *Order::getItems()
{
    return items;
}

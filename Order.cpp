#include "Order.h"
#include "OrderState.h"

Order::Order(std::string id)
{
    this->id = id;
}

Order::~Order()
{
    // TODO : Complete Implementation
    // Unclear who is responsible for deleting items yet.
    if (state != nullptr)
    {
        delete state;
        state = nullptr;
    }
}

void Order::AddToOrder(OrderComponent *item)
{
    // TODO : Implement
    // OrderComponent not implemented yet...
}

void Order::RemoveFromOrder(OrderComponent *item)
{
    // TODO : Implement
    // OrderComponent not implemented yet...
}

void Order::setState(OrderState *state)
{
    if (this->state == state)
        return;

    if (this->state != nullptr)
        delete this->state;
    this->state = state;
}

OrderState *Order::getState()
{
    return state;
}

void Order::processPayment()
{
    OrderState *temp = new VerifyOrder();
    setState(temp);
    state->handle(this);
}

OrderComponent *Order::getItems()
{
    return items;
}
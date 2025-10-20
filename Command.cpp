#include "Order.h"
#include "Command.h"

AddToOrder::AddToOrder(Order *order) : Command()
{
    this->order = order;
}

void AddToOrder::execute(OrderComponent *item)
{
    order->AddToOrder(item);
}

RemoveFromOrder::RemoveFromOrder(Order *order) : Command()
{
    this->order = order;
}

void RemoveFromOrder::execute(OrderComponent *item)
{
    order->RemoveFromOrder(item);
}

AddToOrder::~AddToOrder()
{
}

RemoveFromOrder::~RemoveFromOrder()
{
}

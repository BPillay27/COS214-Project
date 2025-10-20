#include "OrderState.h"
#include "Order.h"
#include <iostream>

AcceptPayment::AcceptPayment() : OrderState()
{
}

void AcceptPayment::handle(Order *order)
{
    std::cout << "Payment successfully received.\n";
    order->setState(nullptr);
}

DeclinePayment::DeclinePayment() : OrderState()
{
}

void DeclinePayment::handle(Order *order)
{
    std::cout << "Payment declined. Please try again.\n";
    // This method could set the state back to processing order, but since we agreed sequential programming this would cause a infinite loop of states?
    order->setState(nullptr);
}

ProcessingPayment::ProcessingPayment() : OrderState()
{
}

void ProcessingPayment::handle(Order *order)
{
    std::cout << "Processing payment...\n";
    int x = rand();

    if (x % 2 == 0)
    {
        AcceptPayment *temp = new AcceptPayment();
        order->setState(temp);
    }
    else
    {
        DeclinePayment *temp = new DeclinePayment();
        order->setState(temp);
    }
}

VerifyOrder::VerifyOrder() : OrderState()
{
}

void VerifyOrder::handle(Order *order)
{
    std::cout << "Verifying order...\n";
    if (order->getItems() == nullptr)
    {
        std::cout << "The order is empty.\n";
        order->setState(nullptr);
    }
    else
    {
        ProcessingPayment *temp = new ProcessingPayment();
        order->setState(temp);
    }
}

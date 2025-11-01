#include "OrderState.h"
//#include "Order.h"
#include <iostream>
#include <cstdlib>
#include <ctime>


/**
 * @details Constructor for the OrderState Abstract class. Sets this `order` to `order`.
 * @param order The `Order` which this `OrderState` belongs to.
 */

OrderState::OrderState(Order *order)
{
    this->order = order;
}

/**
 * @details Destructor for the `OrderState` class. Does nothing since an `OrderState` should not delete its own `Order`.
 * @note `OrderState` and its subclasses do not delete `order`.
 */

OrderState::~OrderState()
{
}

/**
 * @details Constructor for the `AcceptPayment` subclass. Calls the constructor of its base class, `OrderState`. Passes `order` to the `OrderState` constructor.
 * @param order The `Order` this state belongs to. This is passed to `OrderState`.
 */

AcceptPayment::AcceptPayment(Order *order) : OrderState(order)
{
}

/**
 * @details Destructor for the `AcceptPayment` subclass. Does nothing,
 */

AcceptPayment::~AcceptPayment()
{
}

/**
 * @details This is the state handling method for `AcceptPayment`. Prints a message to console and sets `order->state` to `nullptr`.
 */

void AcceptPayment::handle()
{
    std::cout << "Payment successfully received.\n";
    //Must remove the plants from the Nursey
    if(this->order == nullptr){
        return;
    }
    if( this->order->items != nullptr){
        this->order->items->success();
    }else{
        return;
    }
    delete this->order->items;
    this->order->setState(nullptr);
}

/**
 * @details Constructor for the `DeclinePayment` subclass. Calls the constructor of its base class, `OrderState`. Passes `order` to the `OrderState` constructor.
 * @param order The `Order` this state belongs to. This is passed to `OrderState`.
 */

DeclinePayment::DeclinePayment(Order *order) : OrderState(order)
{
}

/**
 * @details Destructor for the `DeclinePayment` subclass. Does nothing,
 */

DeclinePayment::~DeclinePayment()
{
}

/**
 * @details Handler for a failed payment. Prints a message to console and set `order->state` to `nullptr`.
 */

void DeclinePayment::handle()
{
    std::cout << "Payment declined. Please try again.\n";
    // This method could set the state back to processing order, but since we agreed sequential programming this would cause a infinite loop of states?
    OrderState* temp = new ProcessingPayment(order);
    order->setState(temp);
}

/**
 * @details Constructor for the `ProcessingPayment subclass. Calls the constructor of its base class, `OrderState`. Passes `order` to the `OrderState` constructor.
 * @param order The `Order` this state belongs to. This is passed to `OrderState`.
 */

ProcessingPayment::ProcessingPayment(Order *order) : OrderState(order)
{
}

/**
 * @details Destructor for the `ProcessingPayment` subclass. Does nothing,
 */

ProcessingPayment::~ProcessingPayment()
{
}

/**
 * @details Handler for processing a payment. If the payment is successful, instantiates an `AcceptState` object and sets `order->state` to the object.
 */

void ProcessingPayment::handle()
{
    std::cout << "Processing payment...\n";
    int x = rand();

    if (x % 2 == 0)
    {
        AcceptPayment *temp = new AcceptPayment(order);
        order->setState(temp);
    }
    else
    {
        DeclinePayment *temp = new DeclinePayment(order);
        order->setState(temp);
    }
}

/**
 * @details Constructor for the `VerifyOrder` subclass. Calls the constructor of its base class, `OrderState`. Passes `order` to the `OrderState` constructor.
 * @param order The `Order` this state belongs to. This is passed to `OrderState`.
 */

VerifyOrder::VerifyOrder(Order *order) : OrderState(order)
{
}

/**
 * @details Destructor for the `VerifyOrder` subclass. Does nothing.
 */

VerifyOrder::~VerifyOrder()
{
}

/**
 * @details Handler for the `VerifyOrder` state. If the `Order` is empty, calls `order->setState(nullptr)` to end the state handling. Otherwise, creates `ProcessingPayment` and sets `order->state` to the `ProcessingPayment` instance.
 */

void VerifyOrder::handle()
{
    std::cout << "Verifying order...\n";
    if (order->getItems() == nullptr)
    {
        std::cout << "The order is empty.\n";
        order->setState(nullptr);
    }
    else
    {
        ProcessingPayment *temp = new ProcessingPayment(order);
        order->setState(temp);
    }
}



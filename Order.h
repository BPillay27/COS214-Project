#ifndef ORDER_H
#define ORDER_H

#include <string>

/**
 * @defgroup Context
 * @ingroup PayState
 * @brief Context participant of the State pattern.
 */

/**
 * @defgroup Receiver
 * @ingroup Order_Command
 * @brief Reveiver participant of the Command pattern.
 */

/**
 * @file Order.h
 * @ingroup PayState Order_Command
 * @brief The Order aggregate which is the Context of the State pattern and the Receiver of the Command pattern.
 */


class OrderState;
class OrderComponent;

/**
 * @class Order
 * @ingroup Context Order_Command
 * @details The Context of the State pattern and Receiver of the Command pattern.
 */
class Order
{
    public:
    Order(std::string id); ///< Constructor.
    ~Order(); ///< Destructor.
    void AddToOrder(OrderComponent* item); ///< Add item.
    void RemoveFromOrder(OrderComponent* item); ///< Remove item
    void setState(OrderState* state); ///< Change state.
    OrderState* getState(); ///< Get `state`.
    void processPayment(); ///< Starts payment process.
    OrderComponent* getItems(); ///< Get `items`.
    
    private:
    OrderComponent* items; ///< The items in the order.
    OrderState* state; ///< The current state of the payment process.
    std::string id; ///< Identifier for the order.
};

#endif
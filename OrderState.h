#ifndef ORDERSTATE_H
#define ORDERSTATE_H
#include "Order.h"
#include "OrderComponent.h"
class Order;

/**
 * @file OrderState.h
 * @defgroup PayState
 * @brief Group of classes that make up the State Pattern for payments.
 * @author Practicklers
 * @date 2025-10-21
 */

/**
 * @defgroup State
 * @ingroup PayState
 * @brief State participants of the State design pattern.
 */

/**
 * @defgroup ConcreteStates
 * @ingroup PayState
 * @brief Concrete implementations of the States.
 */

/**
 * @class OrderState
 * @brief Abstract base class for the States.
 * @ingroup State
 */

class OrderState
{
public:
    OrderState(Order *order); ///< Constructor
    virtual ~OrderState(); ///< Destructor.
    virtual void handle() = 0; ///< Handler.

protected:
    Order *order; ///< Pointer `Order` this state belongs to.
};

/**
 * @class AcceptPayment
 * @ingroup ConcreteStates
 * @brief State for successful payment.
 */
class AcceptPayment : public OrderState
{
public:
    AcceptPayment(Order *order); ///< Constructor.
    ~AcceptPayment(); ///< Destructor.
    void handle(); ///< Handle successful payment.
};

/**
 * @class DeclinePayment
 * @brief State to handle a failed payment.
 * @ingroup ConcreteStates
 */

class DeclinePayment : public OrderState
{
public:
    DeclinePayment(Order *order); ///< Constructor.
    ~DeclinePayment(); ///< Destructor.
    void handle(); ///< Handle declined payment.
};

/**
 * @class ProcessingPayment
 * @ingroup ConcreteStates
 * @brief State for awaiting payment result.
 */

class ProcessingPayment : public OrderState
{
public:
    ProcessingPayment(Order *order); ///< Constructor.
    ~ProcessingPayment(); ///< Destructor.
    void handle(); ///< Handle processing payment
};

/**
 * @class VerifyOrder
 * @brief State to verify if the `order` is valid.
 * @ingroup ConcreteStates
 */

class VerifyOrder : public OrderState
{
public:
    VerifyOrder(Order *order); ///< Constructor.
    ~VerifyOrder(); ///< Destructor.
    void handle(); ///< Handle order verification.
};

#endif
#ifndef COMMAND_H
#define COMMAND_H

class Order;
class OrderComponent;

/**
 * @file Command.h
 * @defgroup Order_Command
 * @brief Group of classes that participate in the Order Command.
 * @author Practicklers
 * @date 2025-10-21
 */

/**
 * @defgroup Commands
 * @ingroup Order_Command
 * @brief Abstract base classes of the Command Pattern.
 */

/**
 * @defgroup ConcreteCommands
 * @ingroup Order_Command
 * @brief Concrete implementations of Commands.
 */

/**
 * @class Command
 * @ingroup Commands
 * @brief The Abstract base class of the pattern.
 */

class Command
{
public:
    Command() = default; ///< Default constructor.
    virtual ~Command() = default; ///< Default destructor.
    virtual void execute() = 0; ///< Executes command.
};

/**
 * @class AddToOrder
 * @ingroup ConcreteCommands
 * @brief Concrete Command to add an item to `Order`.
 */

class AddToOrder : public Command
{
public:
    AddToOrder(Order *order, OrderComponent* toAdd); ///< Constructor.
    ~AddToOrder(); ///< Destructor.
    void execute(); ///< Execute add to order.

private:
    Order *order; ///< Order this command affects.
    OrderComponent* toAdd; ///< Item this command adds.
};

/**
 * @class RemoveFromOrder
 * @ingroup ConcreteCommands
 * @brief ConctreteCommand to remove an item from `Order`.
 */

class RemoveFromOrder : public Command
{
public:
    RemoveFromOrder(Order *order, OrderComponent* toRemove); ///< Constructor.
    ~RemoveFromOrder(); ///< Destructor.
    void execute(); ///< Executes remove from order.

private:
    Order *order; ///< `Order` this command affects.
    OrderComponent* toRemove; ///< Item this command removes.
};

#endif
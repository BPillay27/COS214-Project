#ifndef COMMAND_H
#define COMMAND_H

class Order;
class OrderComponent;

class Command
{
public:
    Command() = default;
    virtual ~Command() = default;
    virtual void execute() = 0;
};

class AddToOrder : public Command
{
public:
    AddToOrder(Order *order);
    ~AddToOrder();
    void execute(OrderComponent* item);

private:
    Order *order;
};

class RemoveFromOrder : public Command
{
public:
    RemoveFromOrder(Order *order);
    ~RemoveFromOrder();
    void execute(OrderComponent* item);

private:
    Order *order;
};

#endif
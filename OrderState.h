#ifndef ORDERSTATE_H
#define ORDERSTATE_H

class Order;

class OrderState
{
public:
    OrderState() = default;
    virtual ~OrderState() = default;
    virtual void handle(Order* order) = 0;
};

class AcceptPayment : public OrderState
{
public:
    AcceptPayment();
    ~AcceptPayment() = default;
    void handle(Order* order);
};

class DeclinePayment : public OrderState
{
public:
    DeclinePayment();
    ~DeclinePayment() = default;
    void handle(Order* order);
};

class ProcessingPayment : public OrderState
{
public:
    ProcessingPayment();
    ~ProcessingPayment() = default;
    void handle(Order* order);
};

class VerifyOrder : public OrderState
{
public:
    VerifyOrder();
    ~VerifyOrder() = default;
    void handle(Order* order);
};

#endif
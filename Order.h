#ifndef ORDER_H
#define ORDER_H

#include <string>

class OrderState;
class OrderComponent;

class Order
{
    public:
    Order(std::string id);
    ~Order();
    void AddToOrder(OrderComponent* item);
    void RemoveFromOrder(OrderComponent* item);
    void setState(OrderState* state);
    OrderState* getState();
    void processPayment();
    OrderComponent* getItems();
    
    private:
    OrderComponent* items;
    OrderState* state;
    std::string id;
};

#endif
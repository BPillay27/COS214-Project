#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <queue>
#include "Command.h"
#include "Order.h"
#include "Namer.h"
using namespace std;

class Customer {

    private:
    string name;
    Order* order;
    queue<Command*> buffer;

    public:
    Customer(string customerName);
    virtual ~Customer();
    void nextRow();
    void pay();
    void addItem(OrderComponent* item); // not sure about this 
    void removeItem(OrderComponent* item); //not sure about this 
    void prevRow();
    string getName();
};

// Concrete Products
class Civillian : public Customer {
    public:
    Civillian(string name);
    ~Civillian();
};

class Commercial : public Customer {
    public:
    Commercial(string name);
    ~Commercial();
};

#endif
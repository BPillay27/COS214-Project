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
    void pay();
    void cancelTransaction();
    void addItem(OrderComponent* item);
    void removeItem(OrderComponent* item);
    void checkout();
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
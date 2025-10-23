#include "Customer.h"

// Base Customer class implementation
Customer::Customer(string customerName)
{
    name = customerName;
    order = nullptr;
}

Customer::~Customer()
{

}

string Customer::getName()
{
    return name;
}

void Customer::nextRow()
{
    //nav to next row
}

void Customer::pay()
{
    //payment logic
}

void Customer::addItem(OrderComponent* item)
{
    //implement adding item to order or is it done in order?
}

void Customer::removeItem(OrderComponent* item)
{
    //implement removing item from order or is it done in order?
}

void Customer::prevRow()
{
    //nav to previous row
}

//Civillian (Concrete Product)
Civillian::Civillian(string name) : Customer(name)
{

}

Civillian::~Civillian()
{

}

//Commercial (Concrete Product)
Commercial::Commercial(string name) : Customer(name)
{

}

Commercial::~Commercial()
{

}
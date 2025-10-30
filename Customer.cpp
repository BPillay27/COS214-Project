#include "Customer.h"

//base Customer class implementation
Customer::Customer(string customerName)
{
    name = customerName;
    order = new Order(customerName); //id will be customer name
}

Customer::~Customer()
{
    //clean up any remaining commands in the buffer
    while(!buffer.empty())
    {
        Command* command = buffer.front();
        buffer.pop();
        delete command;
    }
    if(order != nullptr)
    {
        delete order;
    }
}

string Customer::getName()
{
    return name;
}

void Customer::pay()
{
    //payment logic
    checkout();
    order->processPayment();
}

void Customer::cancelTransaction() //might need to move some of this implementation as the customer wont actually remove the items.
{
    //clear all commands in the queue if not executed
    while(!buffer.empty())
    {
        Command* command = buffer.front();
        buffer.pop();
        delete command;
    }
    //fetch the items to remove them all
    OrderComponent* currentItems = order->getItems();
    if(currentItems != nullptr)
    {
        //remove all items
        order->RemoveFromOrder(currentItems);
    }
}

void Customer::addItem(OrderComponent* item)
{
    //create the AddToOrder command and add it to the Q
    if(order != nullptr && item != nullptr)
    {
        AddToOrder* addCommand = new AddToOrder(order, item);
        buffer.push(addCommand);
    }
}

void Customer::removeItem(OrderComponent* item)
{
    //create the RemoveFromOrder command and add it to the Q
    if(order != nullptr && item != nullptr)
    {
        RemoveFromOrder* removeCommand = new RemoveFromOrder(order, item);
        buffer.push(removeCommand);
    }
}

void Customer::checkout()
{
    //execute all the buffer commands 
    while(!buffer.empty())
    {
        Command* command = buffer.front();
        buffer.pop();
        command->execute();
        delete command; //clean up command
    }
}

//Civillian (ConcreteProduct)
Civillian::Civillian(string name) : Customer(name)
{
    //default
}

Civillian::~Civillian()
{
    //default
}

//Commercial (ConcreteProduct)
Commercial::Commercial(string name) : Customer(name)
{
    //default
}

Commercial::~Commercial()
{
    //default
}
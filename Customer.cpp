#include "Customer.h"

// Base Customer class implementation
Customer::Customer(string customerName)
{
    name = customerName;
    // Create a new order for this customer with a unique ID based on their name
    order = new Order(customerName + "_order");
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
    // Create AddToOrder command and add it to the queue
    if(order != nullptr && item != nullptr)
    {
        AddToOrder* addCommand = new AddToOrder(order, item);
        buffer.push(addCommand);
    }
}

void Customer::removeItem(OrderComponent* item)
{
    // Create RemoveFromOrder command and add it to the queue
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
        delete command; // Clean up the command after execution
    }
}

//Civillian (Concrete Product)
Civillian::Civillian(string name) : Customer(name)
{
    //default
}

Civillian::~Civillian()
{
    //default
}

//Commercial (Concrete Product)
Commercial::Commercial(string name) : Customer(name)
{
    //default
}

Commercial::~Commercial()
{
    //default
}
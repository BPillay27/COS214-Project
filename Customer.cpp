#include "Customer.h"

/**
 * @details Constructor for the base Customer class
 * Initializes the customer with a name and creates a new Order object with the customer name as the order ID
 * @param customerName The name of the customer
 */
Customer::Customer(string customerName)
{
    name = customerName;
    order = new Order(customerName); //id will be customer name
}

/**
 * @details Destructor for the Customer class
 * Cleans up all remaining commands in the buffer and deletes the order object
 */
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

/**
 * @details Getter method for the customer's name
 * @return The name of the customer
 */
string Customer::getName()
{
    return name;
}

void Customer::see()
{
    if(order != nullptr)
    {
        checkout();
        std::cout << order->see() << std::endl;
    }
}

/**
 * @details Processes payment for the order
 */
void Customer::pay()
{
    //payment logic
    checkout();
    order->processPayment();
    
}

/**
 * @details Cancels the current transaction
 */
void Customer::cancelTransaction()
{
    //clear all commands in the queue if not executed
    while(!buffer.empty())
    {
        Command* command = buffer.front();
        command->Item->cancelOrder(); //cancel the addition
        if(command->Item->getPlant() != nullptr){
            //Do not delete bare plants;
        }else{
            delete command->Item;
        }
        
        buffer.pop();
        delete command;
    }
    //cancel the order using OrderComponent's cancelOrder
    OrderComponent* currentItems = order->getItems();
    if(currentItems != nullptr)
    {
        //use cancelOrder instead of removing items
        currentItems->cancelOrder();
    }
    delete order;
    order = new Order(getName());
}

/**
 * @details Adds an item to the order by creating an AddToOrder command and adding it to the command buffer
 * @param item The OrderComponent to add to the order
 */
void Customer::addItem(OrderComponent* item)
{
    //create the AddToOrder command and add it to the Q
    if(order != nullptr && item != nullptr)
    {
        AddToOrder* addCommand = new AddToOrder(order, item);
        buffer.push(addCommand);
    }
}

/**
 * @details Removes an item from the order by creating a RemoveFromOrder command and adding it to the command buffer
 * @param item The OrderComponent to remove from the order
 */
void Customer::removeItem(OrderComponent* item)
{
    //create the RemoveFromOrder command and add it to the Q
    if(order != nullptr && item != nullptr)
    {
        RemoveFromOrder* removeCommand = new RemoveFromOrder(order, item);
        buffer.push(removeCommand);
    }
}

/**
 * @details Executes all commands in the buffer queue in FIFO order
 * Each command is executed and then deleted after execution
 */
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

/**
 * @details Constructor for the Civillian class. Calls the base Customer constructor
 * @param name The name of the civilian customer
 */
Civillian::Civillian(string name) : Customer(name)
{
    //default
}

/**
 * @details Destructor for the Civillian class
 */
Civillian::~Civillian()
{
    //default
}

/**
 * @details Constructor for the Commercial class. Calls the base Customer constructor
 * @param name The name of the commercial customer
 */
Commercial::Commercial(string name) : Customer(name)
{
    //default
}

/**
 * @details Destructor for the Commercial class
 */
Commercial::~Commercial()
{
    //default
}
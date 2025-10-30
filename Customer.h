/**
 * @file Customer.h
 * @defgroup CustomerFactory
 * @brief Customer Factory Method pattern
 * @author Arran Lamond
 * @date October 2025
 */

/**
 * @class Customer
 * @ingroup CustomerFactory
 * @brief Abstract base class representing a customer in the system
 * @author Arran Lamond
 * @date October 2025
 */

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <queue>
#include "Command.h"
#include "Order.h"
#include "OrderComponent.h"
#include "Namer.h"
using namespace std;

class Customer {

    private:
    string name; ///< The name of the customer
    Order* order; ///< The order associated with this customer
    queue<Command*> buffer; ///< Command buffer for queued order modifications

    public:
    /**
     * @brief Constructor for Customer
     * @param customerName The name of the customer
     */
    Customer(string customerName);
    
    /**
     * @brief Virtual destructor for Customer
     */
    virtual ~Customer();
    
    /**
     * @brief Process payment for the current order
     */
    void pay();
    
    /**
     * @brief Cancel the current transaction
     */
    void cancelTransaction();
    
    /**
     * @brief Add an item to the order buffer
     * @param item The OrderComponent to add
     */
    void addItem(OrderComponent* item);
    
    /**
     * @brief Remove an item from the order buffer
     * @param item The OrderComponent to remove
     */
    void removeItem(OrderComponent* item);
    
    /**
     * @brief Execute all buffered commands
     */
    void checkout();
    
    /**
     * @brief Get the customer's name
     * @return The name of the customer
     */
    string getName();
};

/**
 * @class Civillian
 * @ingroup CustomerFactory
 * @brief ConcreteProduct representing a civilian customer
 * @author Arran Lamond
 * @date October 2025
 */
class Civillian : public Customer {
    public:
    /**
     * @brief Constructor for Civillian customer
     * @param name The name of the civilian customer
     */
    Civillian(string name);
    
    /**
     * @brief Destructor for Civillian customer
     */
    ~Civillian();
};

/**
 * @class Commercial
 * @ingroup CustomerFactory
 * @brief ConcreteProduct representing a commercial customer
 * @author Arran Lamond
 * @date October 2025
 */
class Commercial : public Customer {
    public:
    /**
     * @brief Constructor for Commercial customer
     * @param name The name of the commercial customer
     */
    Commercial(string name);
    
    /**
     * @brief Destructor for Commercial customer
     */
    ~Commercial();
};

#endif
/**
 * @file Namer.h
 * @ingroup CustomerFactory
 * @brief Factory Method pattern Creator classes for Customer creation
 * @author Arran Lamond
 * @date October 2025
 */

#ifndef NAMER_H
#define NAMER_H

#include <string>
using namespace std;

//forward declaration of customer
class Customer;

/**
 * @class Namer
 * @ingroup CustomerFactory
 * @brief Abstract Creator class in the Factory Method pattern for creating Customer objects
 * @details This class defines the factory method interface for creating Customer objects
 * The actual instantiation is delegated to concrete subclasses (CivillianNamer, CommercialNamer)
 * @author Arran Lamond
 * @date October 2025
 */
class Namer {
    protected:
    /**
     * @brief Factory method to be implemented by concrete creators
     * @details Pure virtual function that concrete subclasses override to create specific Customer types
     * @param name The name to assign to the created Customer
     * @return Pointer to the newly created Customer object
     */
    virtual Customer* CustomerNamer(string name) = 0;

    public:
    /**
     * @brief Default constructor for Namer
     */
    Namer();
    
    /**
     * @brief Virtual destructor for Namer
     */
    virtual ~Namer();
    
    /**
     * @brief Public interface for creating a Customer
     * @details Calls the factory method CustomerNamer() to create the appropriate Customer type
     * @param name The name to assign to the created Customer
     * @return Pointer to the newly created Customer object
     */
    Customer* createCustomer(string name);
};

/**
 * @class CivillianNamer
 * @ingroup CustomerFactory
 * @brief Concrete Creator that creates Civillian Customer objects
 * @details Implements the factory method to instantiate Civillian customers
 * @author Arran Lamond
 * @date October 2025
 */
class CivillianNamer : public Namer {
    protected:
    /**
     * @brief Factory method implementation for creating Civillian customers
     * @param name The name to assign to the Civillian customer
     * @return Pointer to the newly created Civillian object
     */
    Customer* CustomerNamer(string name);
    
    public:
    /**
     * @brief Constructor for CivillianNamer
     */
    CivillianNamer();
    
    /**
     * @brief Destructor for CivillianNamer
     */
    ~CivillianNamer();
};

/**
 * @class CommercialNamer
 * @ingroup CustomerFactory
 * @brief Concrete Creator that creates Commercial Customer objects
 * @details Implements the factory method to instantiate Commercial customers
 * @author Arran Lamond
 * @date October 2025
 */
class CommercialNamer : public Namer {
    protected:
    /**
     * @brief Factory method implementation for creating Commercial customers
     * @param name The name to assign to the Commercial customer
     * @return Pointer to the newly created Commercial object
     */
    Customer* CustomerNamer(string name);
    
    public:
    /**
     * @brief Constructor for CommercialNamer
     */
    CommercialNamer();
    
    /**
     * @brief Destructor for CommercialNamer
     */
    ~CommercialNamer();
};
#endif

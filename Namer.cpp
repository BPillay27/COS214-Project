#include "Namer.h"
#include "Customer.h"

/**
 * @details Constructor for the Namer class
 */
Namer::Namer()
{
    //default constructor
}

/**
 * @details Destructor for the Namer class
 */
Namer::~Namer()
{
    //default destructor - Namer does not own Customer objects
}

/**
 * @details Creates a customer by calling the factory method CustomerNamer()
 * This method delegates the actual creation to the concrete subclass implementation.
 * The caller is responsible for managing the lifetime of the returned Customer object
 * @param name The name to assign to the created customer
 * @return Pointer to the newly created Customer object
 */
Customer* Namer::createCustomer(string name)
{
    return CustomerNamer(name);
}

/**
 * @details Constructor for CivillianNamer
 * Calls the base Namer constructor
 */
//CivillianNamer (ConcreteCreator)
CivillianNamer::CivillianNamer() : Namer()
{
    //default
}

/**
 * @details Destructor for CivillianNamer
 */
CivillianNamer::~CivillianNamer()
{
    //default
}

/**
 * @details Factory method implementation that creates a Civillian customer
 * @param name The name to assign to the Civillian customer
 * @return Pointer to the newly created Civillian object
 */
Customer* CivillianNamer::CustomerNamer(string name)
{
    //instantiate the concrete products with their names
    return new Civillian(name);
}

/**
 * @details Constructor for CommercialNamer
 * Calls the base Namer constructor
 */
//CommercialNamer (ConcreteCreator)
CommercialNamer::CommercialNamer() : Namer()
{
    //default
}

/**
 * @details Destructor for CommercialNamer
 */
CommercialNamer::~CommercialNamer()
{
    //default
}

/**
 * @details Factory method implementation that creates a Commercial customer
 * @param name The name to assign to the Commercial customer
 * @return Pointer to the newly created Commercial object
 */
Customer* CommercialNamer::CustomerNamer(string name)
{
    //instantiate the concrete products with their names
    return new Commercial(name);
}
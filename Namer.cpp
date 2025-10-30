#include "Namer.h"
#include "Customer.h"

Namer::Namer()
{
    customer = nullptr;
}

Namer::~Namer()
{
    //destructor
    if(customer != NULL)
    {
        delete customer;
    }
}

Customer* Namer::createCustomer(string name)
{
    customer = CustomerNamer(name);
    return customer;
}

//CivillianNamer (ConcreteCreator)
CivillianNamer::CivillianNamer() : Namer()
{
    //default
}

CivillianNamer::~CivillianNamer()
{
    //default
}

Customer* CivillianNamer::CustomerNamer(string name)
{
    //instantiate the concrete products with their names
    return new Civillian(name);
}

//CommercialNamer (ConcreteCreator)
CommercialNamer::CommercialNamer() : Namer()
{
    //default
}

CommercialNamer::~CommercialNamer()
{
    //default
}

Customer* CommercialNamer::CustomerNamer(string name)
{
    //instantiate the concrete products with their names
    return new Commercial(name);
}
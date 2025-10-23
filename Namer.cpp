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

//CivillianNamer (Concrete Creator)
CivillianNamer::CivillianNamer() : Namer()
{

}

CivillianNamer::~CivillianNamer()
{

}

Customer* CivillianNamer::CustomerNamer(string name)
{
    
}

//CommercialNamer (Concrete Creator)
CommercialNamer::CommercialNamer() : Namer()
{

}

CommercialNamer::~CommercialNamer()
{

}

Customer* CommercialNamer::CustomerNamer(string name)
{

}
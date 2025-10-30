#ifndef NAMER_H
#define NAMER_H

#include <string>
using namespace std;

//forward declaration of customer
class Customer;

class Namer {
    private:
    Customer* customer;
    
    protected:
    //factory method is protected
    virtual Customer* CustomerNamer(string name) = 0;

    public:
    Namer();
    virtual ~Namer();
    Customer* createCustomer(string name); //interface for creating customer
};

class CivillianNamer : public Namer {
    protected:
    Customer* CustomerNamer(string name);
    
    public:
    CivillianNamer();
    ~CivillianNamer();
};

class CommercialNamer : public Namer {
    protected:
    Customer* CustomerNamer(string name);
    
    public:
    CommercialNamer();
    ~CommercialNamer();
};
#endif

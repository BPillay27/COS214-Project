#ifndef ORDER_COMPONENT_H
#define ORDER_COMPONENT_H

#include <string>
using namespace std;
#include <iostream>
#include "Plant.h"

class OrderComponent 
{
public:
    OrderComponent(int price);
    int getPrice();
    void add(OrderComponent* toAdd);
    OrderComponent* remove(OrderComponent* toRemove); //This part is more for Arrangement
    OrderComponent* getChild(int index);
    ~OrderComponent();
private:
    int price;
};

class PlantDecorator : public OrderComponent 
{
protected:
    OrderComponent* component;
public:
    PlantDecorator(int price);
    virtual OrderComponent* add(OrderComponent* toAdd);
    int getPrice();
};

class DecorPot : public PlantDecorator 
{
public:
    DecorPot();
    OrderComponent* addTo(OrderComponent* toAdd);
};

class Wrapping : public PlantDecorator
{
public:
    Wrapping();
};
#endif
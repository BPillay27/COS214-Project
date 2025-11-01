#ifndef ORDER_COMPONENT_H
#define ORDER_COMPONENT_H

#include <string>
using namespace std;
#include <iostream>

class Plant;
class OrderComponent 
{
public:
    OrderComponent(int price);
    virtual int getPrice();
    virtual void add(OrderComponent* toAdd);
    virtual OrderComponent* remove(OrderComponent* toRemove); //This part is more for Arrangement
    virtual OrderComponent* getChild(int index);
    virtual Plant* getPlant(); 
    virtual ~OrderComponent();
    virtual void cancelOrder();
    virtual void success();
protected:
    int price;
};

class PlantDecorator : public OrderComponent 
{
protected:
    OrderComponent* component;
public:
    PlantDecorator(OrderComponent* component);
    int getPrice() override;
    virtual ~PlantDecorator();
    virtual void cancelOrder();
    virtual void success();
};

class DecorPot : public PlantDecorator 
{
private:
    int potPrice;
public:
    DecorPot(OrderComponent* component);
    int getPrice();
};

class Wrapping : public PlantDecorator
{
private:
    int wrappingPrice;
public:
    Wrapping(OrderComponent* component);
    int getPrice() override;
};
#endif

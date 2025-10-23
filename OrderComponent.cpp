#include "OrderComponent.h"

OrderComponent::OrderComponent(int price) : price(price) {}

int OrderComponent::getPrice() 
{
    return price;
}

void OrderComponent::add(OrderComponent* toAdd) 
{

}

OrderComponent* OrderComponent::remove(OrderComponent* toRemove) 
{
    return nullptr;
}

OrderComponent* OrderComponent::getChild(int index) 
{
    return nullptr;
}

OrderComponent::~OrderComponent() 
{

}

PlantDecorator::PlantDecorator(int price) : OrderComponent(price), component(nullptr) {}

OrderComponent* PlantDecorator::add(OrderComponent* toAdd) 
{
    //TODO: PlantDecorator actual logic lolol
    if (toAdd) 
    {
        toAdd->add(toAdd);
        return toAdd;
    }
    return nullptr;
}

int PlantDecorator::getPrice() 
{       
    if (component) 
    {
        return component->getPrice();
    }
    return 0;
}

DecorPot::DecorPot() : PlantDecorator(component->getPrice()) {}

OrderComponent* DecorPot::addTo(OrderComponent* toAdd)
{
    // TODO: DecorPot actual logic lolol
    if (toAdd) 
    {
        toAdd->add(toAdd);
        return toAdd;
    }
}

Wrapping::Wrapping() : PlantDecorator(component->getPrice()) {}
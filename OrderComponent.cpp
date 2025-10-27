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

Plant* OrderComponent::getPlant() 
{
    return nullptr; //for now dunno how to return, 'itself' 
}

OrderComponent::~OrderComponent() 
{

}

PlantDecorator::PlantDecorator(OrderComponent* component) : OrderComponent(component->getPrice()), component(component) {}

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

PlantDecorator::~PlantDecorator() 
{
    
}

DecorPot::DecorPot() : PlantDecorator(component->getPrice()) 
{

}

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
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

PlantDecorator::PlantDecorator(OrderComponent* component) : OrderComponent(0), component(component) 
{
    
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
    //don't delete component here as it might be used somewhere else
}

DecorPot::DecorPot(OrderComponent* component) : PlantDecorator(component), potPrice(25) 
{
    // arr ar ar ar ar arr arr arr arrr arrrrr
    //dont pee on the floor, use the commodore
    //mb, leave open
}

int DecorPot::getPrice() 
{
    return PlantDecorator::getPrice() + potPrice;
}

Wrapping::Wrapping(OrderComponent* component) : PlantDecorator(component), wrappingPrice(15) 
{

}

int Wrapping::getPrice() 
{
    return PlantDecorator::getPrice() + wrappingPrice;
}
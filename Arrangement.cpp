#include "Arrangement.h"

int Arrangement::getPrice() 
{
    int sum = 0;
    for (int i = 0; i <(int) arrangement.size(); i++) 
    {
        sum += arrangement[i]->getPrice();
    }
    return sum;
}

void Arrangement::add(OrderComponent* toAdd) 
{
    if (!toAdd)
    {
        cout << "The component that is trying to be added is null. (Arrangement.cpp line 12)";
        return;
    }
    arrangement.push_back(toAdd);
}

OrderComponent* Arrangement::remove(OrderComponent* toRemove) 
{
    if (!toRemove) 
    {
        cout << "The component that is trying to be removed is null. (Arrangement.cpp line 20)";
        return nullptr;
    }
    for (int i = 0; i < (int)arrangement.size(); i++) 
    {
        if (arrangement[i] == toRemove) //idk if == is meant to be overloaded lel.
        {
            arrangement.erase(arrangement.begin() + i);
            return toRemove;
        }
    }
    cout << "The component that is trying to be removed was not found. (Arrangement.cpp line 29)";
    return nullptr;
}

OrderComponent* Arrangement::getChild(int index) 
{
    if (index < 0 || index >= (int)arrangement.size()) 
    {
        cout << "What are you trying to reach fo? (Arrangement.cpp line 27)";
        return nullptr;
    }
    return arrangement[index];
}

Arrangement::~Arrangement() 
{
    for (OrderComponent* component : arrangement) 
    {
        delete component;
    }
}

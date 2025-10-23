#include "Arrangement.h"

int Arrangement::getPrice() 
{
    int sum = 0;
    for (int i = 0; i < arrangement.size(); i++) 
    {
        sum += arrangement[i]->getPrice();
    }
    return sum;
}

void Arrangement::add(OrderComponent* toAdd) 
{
    arrangement.push_back(toAdd);
}

OrderComponent* Arrangement::remove(OrderComponent* toRemove) 
{
    if (!toRemove) 
    {
        cout << "The component that is trying to be removed is null. (Arrangement.cpp line 20)";
        return nullptr;
    }
}

OrderComponent* Arrangement::getChild(int index) 
{
    if (index < 0 || index >= arrangement.size()) 
    {
        cout << "What are you trying to reach fo? (Arrangement.cpp line 27)";
        return nullptr;
    }
    return arrangement[index];
}
#ifndef PLANT_ARRANGEMENT_H
#define PLANT_ARRANGEMENT_H

#include "OrderComponent.h"
#include <vector>
using namespace std;
#include <iostream>

class Arrangement : public OrderComponent 
{
private:
    std::vector<OrderComponent*> arrangement;
public:
    Arrangement(int price) : OrderComponent(price) {};
    ~Arrangement();
    Arrangement(const Arrangement& other);
    int getPrice();
    void add(OrderComponent* toAdd);
    OrderComponent* remove(OrderComponent* toRemove);
    OrderComponent* getChild(int index);
    void cancelOrder(){
        for(auto component : arrangement){
            if(component->getPlant() != nullptr){
                component=nullptr;
            }else{
                component->cancelOrder();
            }
        }
    }
    void success(){
        for(auto component : arrangement){
            if(component== nullptr){
                continue;
            }else{
                component->cancelOrder();
            }
        }
    }

    string getDescription();
};

#endif
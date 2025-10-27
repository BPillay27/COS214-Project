#ifndef COMPONENTITERATOR_H
#define COMPONENTITERATOR_H

class OrderComponent;
#include "Iterator.h"
#include <vector>
#include <cstddef>

class ComponentIterator : public Iterator<OrderComponent*>
{
    public:
    ComponentIterator(OrderComponent* root);
    ~ComponentIterator();
    void first();
    void next();
    bool isDone();
    OrderComponent* currentItem();

    private:
    std::vector<OrderComponent*> vec;
    std::size_t index;
};

#endif
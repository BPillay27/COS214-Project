#include "OrderComponent.h"
#include "ComponentIterator.h"
#include <queue>

ComponentIterator::ComponentIterator(OrderComponent *root)
{
    this->index = 0;

    if (root == nullptr)
        return;
    
    std::queue<OrderComponent*> 
}

ComponentIterator::~ComponentIterator()
{
}

void ComponentIterator::first()
{
}

void ComponentIterator::next()
{
}

bool ComponentIterator::isDone()
{
}

OrderComponent *ComponentIterator::currentItem()
{
}
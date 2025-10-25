#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

template <typename T>
class Iterator
{
public:
    Iterator() = default;
    virtual ~Iterator() = default;
    virtual void first() = 0;
    virtual void next() = 0;
    virtual bool isDone() = 0;
    virtual T currentItem() = 0;
};

#endif
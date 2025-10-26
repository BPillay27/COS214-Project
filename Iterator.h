#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

template <typename T>
class Iterator
{
public:
    virtual T back() = 0;
    virtual T currentItem() = 0;
    virtual T first() = 0;
    virtual bool isDone() = 0;
    virtual T next() = 0;
    virtual T remove() = 0;
    Iterator() = default;
    virtual ~Iterator() = default;
};

#endif
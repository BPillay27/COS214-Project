#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H

#include "Iterator.h"
#include <vector>

template <typename T>
class VectorIterator : public Iterator<T>
{
public:
    T next() override
    {
        if (!isDone())
        {
            index++;
        }
        return currentItem();
    }

    T back() override
    {
        if (index > 0)
        {
            index--;
        }
        return currentItem();
    }

    bool isDone() override
    {
        return index >= static_cast<int>(data.size());
    }

    T first() override
    {
        index = 0;
        return currentItem();
    }

    T currentItem() override
    {
        return isDone() ? T{} : data[index];
    }

    T remove() override
    {
        if (isDone())
            return T{};

        T removed = data[index];
        data.erase(data.begin() + index);

        if (index >= static_cast<int>(data.size()) && index > 0)
            index--;

        return removed;
    }

    explicit VectorIterator(std::vector<T> &vec) : data(vec), index(0) {}

    ~VectorIterator() override = default;

private:
    int index;
    std::vector<T> &data;
};

#endif
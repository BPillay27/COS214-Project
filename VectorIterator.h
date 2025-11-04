#ifndef VECTORITERATOR_H
#define VECTORITERATOR_H

#include "Iterator.h"
#include <vector>

/**
 * @defgroup ConcreteIterators
 * @ingroup IteratorPattern
 * @brief Concrete implementations of the Iterator class.
 */

/**
 * @class VectorIterator
 * @ingroup ConcreteIterators
 * @details Concrete implementation of the Iterator class for Vector aggregates of any type.
 * @tparam T Template return type.
 */
template <typename T>
class VectorIterator : public Iterator<T>
{
public:
    /**
     * @details Checks if the iteration is not done and increments the index is so. Then, returns `currentItem()`.
     * @returns The next item in the Aggregate.
     */
    T next() override
    {
        if (!isDone())
        {
            index++;
        }
        return currentItem();
    }

    /**
     * @details Checks if the index is greater than 0 and decrements the index if so. Then, returns `currentItem()`.
     * @returns The previous item in the Aggregate, if the current item is not the first.
     */

    T back() override
    {
        if (index > 0)
        {
            index--;
        }
        return currentItem();
    }

    /**
     * @brief Determines if the iteration is done.
     * @returns This method returns true if the index is greater than or equal to the size of the aggregate, and false otherwise.
     */
    
    bool isDone() override
    {
        return index >= static_cast<int>(data.size());
    }

    /**
     * @details Sets index to 0 and returns `currentItem()`.
     * @returns The first item of the Aggregate.
     */

    T first() override
    {
        index = 0;
        return currentItem();
    }

    /**
     * @brief Returns the current item `index` refers to.
     * @returns Returns `data[index]` if the iteration is not done or a default T object if not.
     */

    T currentItem() override
    {
        return isDone() ? T{} : data[index];
    }

    /**
     * @brief Removes the current item in the Aggregate and returns it.
     * @returns The item which was removed from the Aggregate.
     */

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

    /**
     * @brief The constructor for the VectorIterator class.
     * @param vec The Vector Aggregate this Iterator will iterate through.
     */
    explicit VectorIterator(std::vector<T> &vec) : data(vec), index(0) {}

    /**
     * @brief Destructor for the VectorIterator class.
     * @note Does not free any memory from the Aggregate.
     */
    ~VectorIterator() override = default;

private:
    int index; ///< The index for the current item.
    std::vector<T> &data; ///< The Vector Aggregate.
};

#endif
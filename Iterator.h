#ifndef ITERATOR_H
#define ITERATOR_H

#include <vector>

/**
 * @defgroup IteratorPattern
 * @author Practicklers
 * @brief Collection of classes which particpate in the Iterator design pattern.
 * @date 2025-10-25
 */

/**
 * @defgroup Iterator
 * @ingroup IteratorPattern
 * @brief Abstract interface for a ConcreteIterator.
 */

/**
 * @class Iterator
 * @ingroup Iterator
 * @brief Abstract Iterator interface.
 * @tparam T Type of elements returned by the Iterator.
 */

template <typename T>
class Iterator
{
public:
    virtual T back() = 0; ///< Pure virtual method to go back.
    virtual T currentItem() = 0; ///< Pure virtual method to return current item.
    virtual T first() = 0; ///< Pure virtual method to go back to the start of Aggregate.
    virtual bool isDone() = 0; ///< Pure vitual method. Determines if you've reached the end of the Aggregate.
    virtual T next() = 0; ///< Pure virtual method. Moves to the next item and returns it.
    virtual T remove() = 0; ///< Pure virtual method. Removes current item from the Aggregate and returns it.
    Iterator() = default; ///< Default constructor
    virtual ~Iterator() = default; ///< Default, virtual destructor.
};

#endif
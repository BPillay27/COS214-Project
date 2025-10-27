#include "Iterator.h"
#include "VectorIterator.h"
#include <string>
#include <vector>
#include <iostream>

void testIteratorAndVector()
{
    std::vector<std::string> string_data;

    for (int i = 0; i < 10; i++)
    {
        std::string id = std::to_string(i);
        string_data.push_back("String " + id);
    }
    VectorIterator<std::string> *stringVector = new VectorIterator<std::string>(string_data);

    int i = 0;
    while (!stringVector->isDone())
    {
        std::string id = std::to_string(i);
        if (stringVector->currentItem() == ("String " + id))
        {
            std::cout << "Test " + id + " successful...\n";
        }
        stringVector->next();
        ++i;
    }

    stringVector->first();
    stringVector->remove();
    stringVector->first();

    i = 0;
    std::cout << "\n";
    while (!stringVector->isDone())
    {
        std::string id = std::to_string(i + 1);
        if (stringVector->currentItem() == ("String " + id))
        {
            std::cout << "Test " + id + " successful...\n";
        }
        stringVector->next();
        ++i;
    }

    stringVector->back();
    stringVector->back();
    std::cout << "Value after back is called : " + stringVector->currentItem() << std::endl;

    delete stringVector;
}

void testAggregates()
{
    // To be continued...
}

int main()
{
    testIteratorAndVector();
}



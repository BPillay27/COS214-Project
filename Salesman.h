#ifndef SALESMAN_H
#define SALESMAN_H

#include <string>
#include "Employee.h"

using namespace std;

class Salesman : public Employee {
    public:
    Salesman();
    void handle(Request* task);
    void HireSalesman(string name);
    void updateQueue();
};

#endif
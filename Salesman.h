#ifndef SALESMAN_H
#define SALESMAN_H

#include <string>

#include "Employee.h"

using namespace std;

class Salesman{
    Salesman();
    void handle(Request* task);
    void HireSalesman(string name);
    void update(Request* request);
};

#endif
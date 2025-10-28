#ifndef GARDENER_H
#define GARDENER_H

#include <string>
#include "Employee.h"

using namespace std;

class Gardener : public Employee {
    public:
    Gardener();
    void handle(Request* task);
    void HireGardener(string name);
    void update(Request* request);
};

#endif
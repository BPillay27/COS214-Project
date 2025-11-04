#ifndef TOPIARY_H
#define TOPIARY_H

#include "GreenHouseCare.h"

class Topiary : public GreenHouseCare {
public:
    void water(Plant* plant) override;
    void prune(Plant* plant) override;
    void fertilise(Plant* plant) override;
};

#endif // TOPIARY_H
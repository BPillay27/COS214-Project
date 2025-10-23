#ifndef NORMAL_H
#define NORMAL_H

#include "GreenHouseCare.h"

class Normal : public GreenHouseCare {
public:
    void water(Plant* plant) override;
    void prune(Plant* plant) override;
    void fertilise(Plant* plant) override;
};

#endif // NORMAL_H
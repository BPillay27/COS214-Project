#ifndef ESPALIER_H
#define ESPALIER_H

#include "GreenHouseCare.h"

class Espalier : public GreenHouseCare {
public:
    void water(Plant* plant) override;
    void prune(Plant* plant) override;
    void fertilise(Plant* plant) override;
};

#endif // ESPALIER_H
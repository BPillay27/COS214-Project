#ifndef BONSAI_H
#define BONSAI_H

#include "GreenHouseCare.h"

class Bonsai : public GreenHouseCare {
public:
    void water(Plant* plant) override;
    void prune(Plant* plant) override;
    void fertilise(Plant* plant) override;
};

#endif // BONSAI_H
#ifndef KOKEDAMA_H
#define KOKEDAMA_H

#include "GreenHouseCare.h"

class Kokedama : public GreenHouseCare {
public:
    void water(Plant* plant) override;
    void prune(Plant* plant) override;
    void fertilise(Plant* plant) override;
};

#endif // KOKEDAMA_H
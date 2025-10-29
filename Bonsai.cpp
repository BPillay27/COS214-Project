#include "Bonsai.h"
#include "Plant.h"
void Bonsai::water(Plant* plant) {
    plant->water();
}

void Bonsai::prune(Plant* plant) {
    plant->prune();
}

void Bonsai::fertilise(Plant* plant) {
    plant->fertilise();
}
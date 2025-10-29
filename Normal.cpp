#include "Normal.h"
#include "Plant.h"
void Normal::water(Plant* plant) {
    plant->water();
}

void Normal::prune(Plant* plant) {
    plant->prune();
}

void Normal::fertilise(Plant* plant) {
    plant->fertilise();
}
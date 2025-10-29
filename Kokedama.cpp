#include "Kokedama.h"
#include "Plant.h"
void Kokedama::water(Plant* plant) {
    plant->water();
}

void Kokedama::prune(Plant* plant) {
    plant->prune();
}

void Kokedama::fertilise(Plant* plant) {
    plant->fertilise();
}
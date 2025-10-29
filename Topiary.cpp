#include "Topiary.h"
#include "Plant.h" 
void Topiary::water(Plant* plant) {
    plant->water();
}

void Topiary::prune(Plant* plant) {
    plant->prune();
}

void Topiary::fertilise(Plant* plant) {
    plant->fertilise();
}
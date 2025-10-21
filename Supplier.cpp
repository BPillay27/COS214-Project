#include "Supplier.h"



Plant * RoseSupplier::Resupply(int growth,int water,int nutrition, int lifeCycle[4]) {
    Plant * plantickle = new Plant("Rose", growth, water, nutrition, 0);
    return plantickle;
}

Plant * AppleSupplier::Resupply(int growth,int water,int nutrition, int lifeCycle[4]) {
    Plant * plantickle = new Plant("Apple", growth, water, nutrition, 0);
    return plantickle;
}

Plant * DandelionSupplier::Resupply(int growth,int water,int nutrition, int lifeCycle[4]) {
    Plant * plantickle = new Plant("Dandelion", growth, water, nutrition, 0);
    return plantickle;
}

#include <iostream>
#include "Plant.h"
#include "Bonsai.h"
#include "Topiary.h"
#include "Espalier.h"
#include "Kokedama.h"
#include "Normal.h"

// A simple assertion function for testing
void assertEquals(int expected, int actual, const std::string& testName) {
    if (expected == actual) {
        std::cout << "[PASSED] " << testName << std::endl;
    } else {
        std::cout << "[FAILED] " << testName << " - Expected " << expected << ", but got " << actual << std::endl;
    }
}

void testBonsaiStrategy() {
    int lifeCycle[4] = {1, 2, 3, 4};
    Plant plant("Test Plant", 50, 50, 50, lifeCycle, 10);
    Bonsai bonsai;

    bonsai.water(&plant);
    assertEquals(60, plant.getWaterLevel(), "Bonsai water()");

    bonsai.prune(&plant);
    assertEquals(45, plant.getGrowth(), "Bonsai prune()");

    bonsai.fertilise(&plant);
    assertEquals(65, plant.getSoilNutrition(), "Bonsai fertilise()");
}

void testTopiaryStrategy() {
    int lifeCycle[4] = {1, 2, 3, 4};
    Plant plant("Test Plant", 50, 50, 50, lifeCycle, 10);
    Topiary topiary;

    topiary.water(&plant);
    assertEquals(60, plant.getWaterLevel(), "Topiary water()");

    topiary.prune(&plant);
    assertEquals(45, plant.getGrowth(), "Topiary prune()");

    topiary.fertilise(&plant);
    assertEquals(65, plant.getSoilNutrition(), "Topiary fertilise()");
}

void testEspalierStrategy() {
    int lifeCycle[4] = {1, 2, 3, 4};
    Plant plant("Test Plant", 50, 50, 50, lifeCycle, 10);
    Espalier espalier;

    espalier.water(&plant);
    assertEquals(60, plant.getWaterLevel(), "Espalier water()");

    espalier.prune(&plant);
    assertEquals(45, plant.getGrowth(), "Espalier prune()");

    espalier.fertilise(&plant);
    assertEquals(65, plant.getSoilNutrition(), "Espalier fertilise()");
}

void testKokedamaStrategy() {
    int lifeCycle[4] = {1, 2, 3, 4};
    Plant plant("Test Plant", 50, 50, 50, lifeCycle, 10);
    Kokedama kokedama;

    kokedama.water(&plant);
    assertEquals(60, plant.getWaterLevel(), "Kokedama water()");

    kokedama.prune(&plant);
    assertEquals(45, plant.getGrowth(), "Kokedama prune()");

    kokedama.fertilise(&plant);
    assertEquals(65, plant.getSoilNutrition(), "Kokedama fertilise()");
}

void testNormalStrategy() {
    int lifeCycle[4] = {1, 2, 3, 4};
    Plant plant("Test Plant", 50, 50, 50, lifeCycle, 10);
    Normal normal;

    normal.water(&plant);
    assertEquals(60, plant.getWaterLevel(), "Normal water()");

    normal.prune(&plant);
    assertEquals(45, plant.getGrowth(), "Normal prune()");

    normal.fertilise(&plant);
    assertEquals(65, plant.getSoilNutrition(), "Normal fertilise()");
}

int main() {
    std::cout << "Running Strategy Pattern Unit Tests..." << std::endl;

    testBonsaiStrategy();
    testTopiaryStrategy();
    testEspalierStrategy();
    testKokedamaStrategy();
    testNormalStrategy();

    return 0;
}
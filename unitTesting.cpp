#include "Iterator.h"
#include "Aggregate.h"
#include "VectorIterator.h"
#include "Plant.h"

int testPlantAreaPlantRow()
{
    int failures = 0;
    std::cout << "=== PlantArea / PlantRow basic test ===\n";

    PlantArea area(5);

    // Capacity & initial count
    if (area.getCapacity() != 5)
    {
        std::cout << "FAIL: capacity\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: capacity\n";
    }
    if (area.getCount() != 0)
    {
        std::cout << "FAIL: initial count\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: initial count\n";
    }

    // Prepare plants
    MockPlant *r1 = new MockPlant("Rose");    // age 0
    MockPlant *r2 = new MockPlant("Rose", 1); // mature
    MockPlant *l1 = new MockPlant("Lily");    // different species

    // Add first plant
    if (!area.addPlant(r1))
    {
        std::cout << "FAIL: add first Rose\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: add first Rose\n";
    }
    if (area.getCount() != 1)
    {
        std::cout << "FAIL: count after first add\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: count after first add\n";
    }

    // Row total for Rose should be 1
    if (area.getRowTotal(r1) != 1)
    {
        std::cout << "FAIL: row total Rose = 1\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: row total Rose = 1\n";
    }

    // Add second Rose (same row)
    if (!area.addPlant(r2))
    {
        std::cout << "FAIL: add second Rose\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: add second Rose\n";
    }
    if (area.getCount() != 2)
    {
        std::cout << "FAIL: count after second add\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: count after second add\n";
    }
    if (area.getRowTotal(r2) != 2)
    {
        std::cout << "FAIL: row total Rose = 2\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: row total Rose = 2\n";
    }

    // Add Lily (new row)
    if (!area.addPlant(l1))
    {
        std::cout << "FAIL: add Lily\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: add Lily\n";
    }
    if (area.getCount() != 3)
    {
        std::cout << "FAIL: count after third add\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: count after third add\n";
    }
    if (area.getRowTotal(l1) != 1)
    {
        std::cout << "FAIL: row total Lily = 1\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: row total Lily = 1\n";
    }

    // givePlant by type (Rose should be mature—r2)
    {
        Plant *got = area.givePlant("Rose");
        if (got == nullptr)
        {
            std::cout << "FAIL: givePlant('Rose') non-null\n";
            ++failures;
        }
        else
        {
            std::cout << "PASS: givePlant('Rose') non-null\n";
        }

        if (got && !static_cast<MockPlant *>(got)->canSale())
        {
            std::cout << "FAIL: returned Rose not mature\n";
            ++failures;
        }
        else
        {
            std::cout << "PASS: returned Rose mature\n";
        }
    }

    // Removal: remove r2
    if (!area.removePlant(r2))
    {
        std::cout << "FAIL: remove r2\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: remove r2\n";
    }
    if (area.getCount() != 2)
    {
        std::cout << "FAIL: count after removal\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: count after removal\n";
    }
    if (area.getRowTotal(r1) != 1)
    {
        std::cout << "FAIL: Rose total = 1 after removal\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: Rose total = 1 after removal\n";
    }

    // Negative cases
    if (area.addPlant(nullptr))
    {
        std::cout << "FAIL: accepted nullptr add\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: rejected nullptr add\n";
    }
    if (area.removePlant(nullptr))
    {
        std::cout << "FAIL: accepted nullptr remove\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: rejected nullptr remove\n";
    }

    // Capacity boundary
    MockPlant *r3 = new MockPlant("Rose");
    MockPlant *r4 = new MockPlant("Rose");
    if (!area.addPlant(r3))
    {
        std::cout << "FAIL: add r3\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: add r3\n";
    }
    if (!area.addPlant(r4))
    {
        std::cout << "FAIL: add r4\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: add r4\n";
    }
    if (area.getCount() != 4)
    {
        std::cout << "FAIL: count should be 4\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: count is 4\n";
    }

    MockPlant *r5 = new MockPlant("Rose");
    if (area.addPlant(r5))
    {
        std::cout << "FAIL: add beyond capacity accepted\n";
        ++failures;
    }
    else
    {
        std::cout << "PASS: add beyond capacity rejected\n";
    }
    delete r5; // not adopted

    // Examine and grow
    area.examine(true);
    area.grow();

    // After grow, Rose and Lily should have a mature plant available
    {
        Plant *gr = area.givePlant("Rose");
        if (!(gr && static_cast<MockPlant *>(gr)->canSale()))
        {
            std::cout << "FAIL: Rose has mature plant after grow\n";
            ++failures;
        }
        else
        {
            std::cout << "PASS: Rose has mature plant after grow\n";
        }

        Plant *gl = area.givePlant("Lily");
        if (!(gl && static_cast<MockPlant *>(gl)->canSale()))
        {
            std::cout << "FAIL: Lily has mature plant after grow\n";
            ++failures;
        }
        else
        {
            std::cout << "PASS: Lily has mature plant after grow\n";
        }
    }

    std::cout << "=== Done. Failures: " << failures << " ===\n";
    return failures;
}

int main()
{
    testPlantAreaPlantRow();
}
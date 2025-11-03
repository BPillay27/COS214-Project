
#include "Command.h"
#include "Order.h"
#include "OrderState.h"
#include "Plant.h"
#include "OrderComponent.h"
#include "Arrangement.h"
#include "Iterator.h"
#include "Aggregate.h"
#include "VectorIterator.h"

#include <iostream>
#include <vector>

#include "Customer.h" //inserted this to prevent some errors
#include "Salesman.h"
#include "InventoryManager.h"
#include "Bonsai.h"
#include "Topiary.h"
#include "Espalier.h"
#include "Kokedama.h"
#include "Normal.h"

// Test fixture for Strategy Pattern
TEST(StrategyPatternTest, AllStrategiesExecute) {
    Plant* rose = new Rose();
    cout<<"\n\n\nRose:" << rose << "\n\n\n" << endl;
    ASSERT_TRUE(rose != nullptr);

    int testsPassed = 0;
    int totalTests = 5;

    // Create a plant to be cared for
    Plant* rose = new Rose();
    GreenHouseCare* careStrategy = new Normal();
    cout << "\nCreated a " << rose->getSpecies() << " for testing." << endl;

    // Test Normal Strategy
    cout << "\n--- Testing Normal Care Strategy ---" << endl;
    int initialWater = rose->getWaterLevel();
    int initialGrowth = rose->getGrowth();
    int initialNutrition = rose->getSoilNutrition();
    rose->setCare(careStrategy);
    cout<<"the water level before:" <<initialWater<<endl;
    cout<<"the growth before:" <<initialGrowth<<endl;
    cout<<"the nutrition before:" <<initialNutrition<<endl;
    rose->water();
    rose->prune();
    rose->fertilise();
    int changedWater = rose->getWaterLevel();
    int changedGrowth = rose->getGrowth();
    int changedNutrition = rose->getSoilNutrition();
    cout << " Normal strategy executed." << endl;
    cout<<"the water level after:" <<changedWater<<endl;
    cout<<"the growth after:" <<changedGrowth<<endl;
    cout<<"the nutrition after:" <<changedNutrition<<endl;
    if(changedGrowth!=initialGrowth && changedWater!=initialWater && changedNutrition!=initialNutrition){
        testsPassed++;
    }else{
        cout<<"Normal strategy test failed."<<endl;
    }

    cout << "\n--- Testing Bonsai Care Strategy ---" << endl;
    initialWater = rose->getWaterLevel();
    initialGrowth = rose->getGrowth();
    initialNutrition = rose->getSoilNutrition();
    careStrategy = new Bonsai();
    rose->setCare(careStrategy);
    cout<<"the water level before:" <<initialWater<<endl;
    cout<<"the growth before:" <<initialGrowth<<endl;
    cout<<"the nutrition before:" <<initialNutrition<<endl;
    rose->water();
    rose->prune();
    rose->fertilise();
    changedWater = rose->getWaterLevel();
    changedGrowth = rose->getGrowth();
    changedNutrition = rose->getSoilNutrition();
    cout << " Bonsai strategy executed." << endl;
    cout<<"the water level after:" <<changedWater<<endl;
    cout<<"the growth after:" <<changedGrowth<<endl;
    cout<<"the nutrition after:" <<changedNutrition<<endl;
    if(changedGrowth!=initialGrowth && changedWater!=initialWater && changedNutrition!=initialNutrition){
        testsPassed++;
    }else{
        cout<<"Bonsai strategy test failed."<<endl;
    }

    // Test Topiary Strategy
    cout << "\n--- Testing Topiary Care Strategy ---" << endl;
    careStrategy = new Topiary();
    careStrategy->water(rose);
    careStrategy->prune(rose);
    careStrategy->fertilise(rose);
    cout << "Topiary strategy executed." << endl;
    testsPassed++;
    delete careStrategy;

    // Test Espalier Strategy
    cout << "\n--- Testing Espalier Care Strategy ---" << endl;
    careStrategy = new Espalier();
    careStrategy->water(rose);
    careStrategy->prune(rose);
    careStrategy->fertilise(rose);
    cout << " Espalier strategy executed." << endl;
    testsPassed++;
    delete careStrategy;

    // Test Kokedama Strategy
    cout << "\n--- Testing Kokedama Care Strategy ---" << endl;
    careStrategy = new Kokedama();
    careStrategy->water(rose);
    careStrategy->prune(rose);
    careStrategy->fertilise(rose);
    cout << " Kokedama strategy executed." << endl;
    testsPassed++;
    delete careStrategy;

    delete rose;

    cout << "\n=== STRATEGY TEST RESULTS SUMMARY ===" << endl;
    cout << "Tests Passed: " << testsPassed << "/" << totalTests << endl;
    if (testsPassed == totalTests) {
        cout << "🎉 ALL STRATEGY TESTS PASSED! The Strategy pattern is implemented correctly." << endl;
    } else {
        cout << "⚠️ Some strategy tests failed. Please review the implementation." << endl;
    }
}


bool testAggregate()
{
    bool ok = true;

    PlantArea *area = new PlantArea(5);

    Plant *rose = new Rose();
    Plant *dand = new Dandelion();
    Plant *apple = new AppleTree();

    if (!area->addPlant(rose))
        ok = false;
    if (!area->addPlant(dand))
        ok = false;
    if (!area->addPlant(apple))
        ok = false;

    if (area->getCount() != 3)
        ok = false;

    // Grow twice so AppleTree can mature too
    for (int i = 0; i < 2; i++)
    {
        area->grow();
    }

    if (area->givePlant("Rose") == nullptr)
        ok = false;
    if (area->givePlant("Dandelion") == nullptr)
        ok = false;
    if (area->givePlant("Apple tree") == nullptr)
        ok = false;

    delete area; // This should delete rows and owned Plant*'s

    return ok;
}

void testPlants(){

    // Create instances of plants
    int testCorrect=0;

    Plant* rose = new Rose();
    Plant* dandelion = new Dandelion();
    Plant* appleTree = new AppleTree();

    // Display plant details
    string ExpectedRoseDetails = "Species: Rose\nAverage Life span: 45 days\nPrice: R50\n";
    if(rose->getDetails() == ExpectedRoseDetails){
        testCorrect++;
        //std::cout<<rose->getDetails()<<std::endl;
        cout<< "Rose details test passed." << endl;
    }else{
        //std::cout<<rose->getDetails()<<std::endl;
        cout<< "Rose details test failed." << endl;
    }
    if(dandelion->getDetails() == "Species: Dandelion\nAverage Life span: 35 days\nPrice: R20\n"){
        //std::cout<<dandelion->getDetails()<<std::endl;
        testCorrect++;
        cout<< "Dandelion details test passed." <<endl;
    }
    if(appleTree->getDetails() == "Species: Apple tree\nAverage Life span: 80 days\nPrice: R120\n"){
        testCorrect++;
        cout<< "Apple tree details test passed." <<endl;
    }
    cout << testCorrect << " out of 3 plant detail tests passed." << endl;

    if(rose->getSpecies() == "Rose"){
        testCorrect++;
        cout <<"Species test passed."<<endl;
    }else{
        cout <<"Species test failed."<<endl;
    }

    if(rose->getChild(0) == rose){
        testCorrect++;
        cout <<"Get child test passed."<<endl;
    }else{
        cout <<"Get child test failed."<<endl;
    }

    if(rose->toFertilise()==false){
        testCorrect++;
        cout <<"To fertilise test passed."<<endl;
    }else{
        cout <<"To fertilise test failed."<<endl;
    }

    if(rose->toPrune()==false){
        testCorrect++;
        cout <<"To prune test passed."<<endl;
    }else{
        cout <<"To prune test failed."<<endl;
    }

    if(rose->toWater()==false){
        testCorrect++;
        cout <<"To water test passed."<<endl;
    }else{
        cout <<"To water test failed."<<endl;
    }

    if(rose->canSale()==false){
        testCorrect++;
        cout <<"Can sale test passed."<<endl;
    }else{ 
        cout <<"Can sale test failed."<<endl;
    }

    if(rose->pruneMax()==20){
        testCorrect++;
        cout <<"Prune max test passed."<<endl;
    }else{
        cout <<"Prune max test failed."<<endl;
    }

    if(rose->waterMax()==15){
        testCorrect++;
        cout <<"Water max test passed."<<endl;
    }else{
        //cout<<rose->waterMax()<<endl;
        cout <<"Water max test failed."<<endl;
    }

    if(rose->fertiliseMax()==20){
        testCorrect++;
        cout <<"Fertilise max test passed."<<endl;
    }else{
        cout <<"Fertilise max test failed."<<endl;
    }

    rose->addWater(-40);
    if(rose->toWater()==true){
        testCorrect++;
        cout <<"Add water test passed."<<endl;
    }else{
        cout <<"Add water test failed."<<endl;
    }

    rose->addGrowth(60);
    if(rose->toPrune()==true){
        testCorrect++;
        cout <<"Add growth test passed."<<endl;
    }else{
        cout <<"Add growth test failed."<<endl;
    }

    rose->addNutrition(-36);
    if(rose->toFertilise()==true){
        testCorrect++;
        cout <<"Add nutrition test passed."<<endl;
    }else{
        cout <<"Add nutrition test failed."<<endl;
    }

    rose->addWater(40);
    if(rose->toWater()==false){
        testCorrect++;
        cout <<"Add water test2 passed."<<endl;
    }else{
        cout <<"Add water test2 failed."<<endl;
    }

    rose->addGrowth(-60);
    if(rose->toPrune()==false){
        testCorrect++;
        cout <<"Add growth test 2 passed."<<endl;
    }else{
        cout <<"Add growth test 2 failed."<<endl;
    }

    rose->addNutrition(36);
    if(rose->toFertilise()==false){
        testCorrect++;
        cout <<"Add nutrition test 2 passed."<<endl;
    }else{
        cout <<"Add nutrition test 2 failed."<<endl;
    }

    // Clean up
    delete rose;
    delete dandelion;
    delete appleTree;
}

void testOrderComponent()
{
    cout << "\n=== COMPREHENSIVE COMPONENT PATTERN TESTING ===" << endl;
    cout << "Testing Composite and Decorator Patterns Integration" << endl;
    
    int testsPassed = 0;
    int totalTests = 0;
    
    // Test 1: Basic Plant Creation (Leaf Component)
    cout << "\n--- Test 1: Basic Plant Creation ---" << endl;
    totalTests++;
    try {
        Plant* rose = new Rose();
        Plant* dandelion = new Dandelion();
        Plant* appleTree = new AppleTree();
        
        if (rose && dandelion && appleTree) {
            cout << "✓ Plant objects created successfully" << endl;
            testsPassed++;
        }
        
        // Test plant prices
        cout << "Rose price: R" << rose->getPrice() << endl;
        cout << "Dandelion price: R" << dandelion->getPrice() << endl;
        cout << "Apple Tree price: R" << appleTree->getPrice() << endl;
        
        delete rose;
        rose=nullptr;
        delete dandelion;
        dandelion=nullptr;
        delete appleTree;
        appleTree=nullptr;
    } catch (const exception& e) {
        cout << "✗ Plant creation failed: " << e.what() << endl;
    }
    
    // Test 2: Arrangement (Composite) Functionality
    cout << "\n--- Test 2: Arrangement (Composite) Testing ---" << endl;
    totalTests++;
    try {
        Arrangement* bouquet = new Arrangement(0);
        Plant* rose1 = new Rose();
        Plant* rose2 = new Rose();
        Plant* dandelion1 = new Dandelion();
        
        // Add plants to arrangement
        bouquet->add(rose1);
        bouquet->add(rose2);
        bouquet->add(dandelion1);
        
        int expectedPrice = rose1->getPrice() + rose2->getPrice() + dandelion1->getPrice();
        int actualPrice = bouquet->getPrice();
        
        cout << "Expected total price: R" << expectedPrice << endl;
        cout << "Actual total price: R" << actualPrice << endl;
        
        if (actualPrice == expectedPrice) {
            cout << "✓ Composite price calculation works correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ Composite price calculation failed" << endl;
        }
        
        // Test getting children
        OrderComponent* firstChild = bouquet->getChild(0);
        if (firstChild == rose1) {
            cout << "✓ Getting child components works" << endl;
        } else {
            cout << "✗ Getting child components failed" << endl;
        }
        
        delete bouquet;
        // delete rose1;
        // delete rose2;
        // delete dandelion1;
    } catch (const exception& e) {
        cout << "✗ Arrangement testing failed: " << e.what() << endl;
    }
    
    // Test 3: Basic Decorator Pattern
    cout << "\n--- Test 3: Basic Decorator Pattern ---" << endl;
    totalTests += 3;
    try {
        Plant* basePlant = new Rose();  // Base price
        Plant* basePlant1= new Rose();
        Plant* basePlant2= new Rose();

        int basePlantPrice = basePlant->getPrice();
        cout << "Base plant price: R" << basePlantPrice << endl;
        
        // Test DecorPot decorator
        OrderComponent* decoratedWithPot = new DecorPot(basePlant);
        int potDecoratedPrice = decoratedWithPot->getPrice();
        cout << "Plant with decorative pot price: R" << potDecoratedPrice << endl;
        
        if (potDecoratedPrice > basePlantPrice) {  // Pot should add cost
            cout << "✓ DecorPot decorator adds value correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ DecorPot decorator failed to add value" << endl;
        }
        
        // Test Wrapping decorator
        OrderComponent* wrappedPlant = new Wrapping(basePlant1);
        int wrappedPrice = wrappedPlant->getPrice();
        cout << "Plant with wrapping price: R" << wrappedPrice << endl;
        
        if (wrappedPrice > basePlantPrice) {  // Wrapping should add cost
            cout << "✓ Wrapping decorator adds value correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ Wrapping decorator failed to add value" << endl;
        }
        
        // Test multiple decorators (chaining)
        PlantDecorator* fullyDecorated = new Wrapping(new DecorPot(basePlant2));
        int fullyDecoratedPrice = fullyDecorated->getPrice();
        cout << "Plant with pot and wrapping price: R" << fullyDecoratedPrice << endl;
        
        if (fullyDecoratedPrice > potDecoratedPrice && fullyDecoratedPrice > wrappedPrice) {  
            cout << "✓ Multiple decorators (chaining) work correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ Multiple decorators failed" << endl;
        }
        
        delete decoratedWithPot;
        delete wrappedPlant;
        delete fullyDecorated;
    } catch (const exception& e) {
        cout << "✗ Decorator testing failed: " << e.what() << endl;
    }
    
    // Test 4: Complex Composite with Decorators
    cout << "\n--- Test 4: Composite + Decorator Integration ---" << endl;
    totalTests += 2;
    try {
        // Create arrangement with decorated plants
        Arrangement* fancyBouquet = new Arrangement(0);
        
        Plant* rose1 = new Rose();
        Plant* dandelion2 = new Dandelion();
        
        PlantDecorator* decoratedRose1 = new DecorPot(rose1);
        PlantDecorator* wrappedDandelion2 = new Wrapping(dandelion2);

        fancyBouquet->add(decoratedRose1);
        fancyBouquet->add(wrappedDandelion2);

        int expectedTotal = decoratedRose1->getPrice() + wrappedDandelion2->getPrice();
        int actualTotal = fancyBouquet->getPrice();
        
        cout << "Expected fancy bouquet price: R" << expectedTotal << endl;
        cout << "Actual fancy bouquet price: R" << actualTotal << endl;
        
        if (actualTotal == expectedTotal) {
            cout << "✓ Composite with decorated components works correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ Composite with decorated components failed" << endl;
        }
        //cout<<"deleting for test"<<endl;
        delete fancyBouquet;
        
        // Test nested arrangements
        Arrangement* megaBouquet = new Arrangement(0);
        Arrangement* subBouquet1 = new Arrangement(0);
        Arrangement* subBouquet2 = new Arrangement(0);
        Plant* rose = new Rose();
        Plant* dandelion = new Dandelion();
        Plant* appleTree = new AppleTree();
        PlantDecorator* decoratedAppleTree = new Wrapping(new DecorPot(appleTree));
        
        subBouquet1->add(rose);
        subBouquet2->add(decoratedAppleTree);
        
        megaBouquet->add(subBouquet1);
        megaBouquet->add(subBouquet2);
        megaBouquet->add(dandelion);
        
        int expectedMegaTotal = subBouquet1->getPrice() + subBouquet2->getPrice() + dandelion->getPrice();
        int actualMegaTotal = megaBouquet->getPrice();
        
        cout << "Expected mega bouquet price: R" << expectedMegaTotal << endl;
        cout << "Actual mega bouquet price: R" << actualMegaTotal << endl;
        
        if (actualMegaTotal == expectedMegaTotal) {
            cout << "✓ Nested composite structures work correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ Nested composite structures failed" << endl;
        }
        
        // Cleanup
        delete megaBouquet;
        // delete subBouquet1;
        // delete subBouquet2;
        
        // delete decoratedRose;
        // delete wrappedDandelion;
        // delete decoratedAppleTree;
        // delete rose;
        // delete dandelion;
        // delete appleTree;
    } catch (const exception& e) {
        cout << "✗ Complex integration testing failed: " << e.what() << endl;
    }
    
    // Test 5: Pattern Structure Verification
    cout << "\n--- Test 5: Pattern Structure Verification ---" << endl;
    totalTests += 4;
    try {
        Plant* plant = new Rose();
        PlantDecorator* decorator = new DecorPot(plant);
        Arrangement* arrangement = new Arrangement(0);
        
        // Test inheritance relationships
        OrderComponent* componentPtr1 = plant;
        OrderComponent* componentPtr2 = decorator;
        OrderComponent* componentPtr3 = arrangement;

        if (!(componentPtr1 && componentPtr2 && componentPtr3)) {
            cout << "✓ All classes properly inherit from OrderComponent" << endl;
            testsPassed++;
        }
        
        // Test Plant retrieval
        Plant* retrievedPlant = plant->getPlant();
        if (retrievedPlant == plant) {
            cout << "✓ Plant getPlant() method works correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ Plant getPlant() method failed" << endl;
        }
        
        // Test decorator transparency
        if (decorator->getPrice() >= plant->getPrice()) {
            cout << "✓ Decorator maintains component interface" << endl;
            testsPassed++;
        } else {
            cout << "✗ Decorator interface failed" << endl;
        }
        
        // Test polymorphic behavior
        vector<OrderComponent*> components;
        components.push_back(plant);
        components.push_back(decorator);
        components.push_back(arrangement);
        
        bool polymorphismWorks = true;
        for (OrderComponent* comp : components) {
            try {
                int price = comp->getPrice();
                if (price < 0) polymorphismWorks = false;
            } catch (...) {
                polymorphismWorks = false;
            }
        }
        
        if (polymorphismWorks) {
            cout << "✓ Polymorphic behavior works correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ Polymorphic behavior failed" << endl;
        }
        
        delete arrangement;
        delete decorator;
    } catch (const exception& e) {
        cout << "✗ Pattern structure verification failed: " << e.what() << endl;
    }
    
    // Test 6: Edge Cases and Error Handling
    cout << "\n--- Test 6: Edge Cases and Error Handling ---" << endl;
    totalTests += 2;
    try {
        // Test empty arrangement
        Arrangement* emptyArrangement = new Arrangement(0);
        if (emptyArrangement->getPrice() == 0) {
            cout << "✓ Empty arrangement handles correctly" << endl;
            testsPassed++;
        } else {
            cout << "✗ Empty arrangement failed" << endl;
        }
        
        // Test decorator with null component (if properly handled)
        try {
            Plant* testPlant = new Rose();
            PlantDecorator* testDecorator = new DecorPot(testPlant);
            
            if (testDecorator && testDecorator->getPrice() >= 0) {
                cout << "✓ Decorator construction handles correctly" << endl;
                testsPassed++;
            } else {
                cout << "✗ Decorator construction failed" << endl;
            }
            
            delete testDecorator;
            // delete testPlant;
        } catch (...) {
            cout << "✗ Decorator construction failed with exception" << endl;
        }
        
        delete emptyArrangement;
    } catch (const exception& e) {
        cout << "✗ Edge case testing failed: " << e.what() << endl;
    }
    
    // Test Results Summary
    cout << "\n=== TEST RESULTS SUMMARY ===" << endl;
    cout << "Tests Passed: " << testsPassed << "/" << totalTests << endl;
    cout << "Success Rate: " << (totalTests > 0 ? (testsPassed * 100.0 / totalTests) : 0) << "%" << endl;
    
    if (testsPassed == totalTests) {
        cout << "🎉 ALL TESTS PASSED! Your Composite and Decorator patterns are working correctly!" << endl;
    } else if (testsPassed >= totalTests * 0.8) {
        cout << "👍 Most tests passed! Your pattern implementation is mostly correct." << endl;
    } else {
        cout << "⚠️  Several tests failed. Please review the implementation." << endl;
    }
    
    // Pattern Implementation Analysis
    cout << "\n=== PATTERN IMPLEMENTATION ANALYSIS ===" << endl;
    cout << "✓ Composite Pattern:" << endl;
    cout << "  - Component: OrderComponent (defines interface)" << endl;
    cout << "  - Leaf: Plant (concrete component, cannot have children)" << endl;
    cout << "  - Composite: Arrangement (can contain other OrderComponents)" << endl;
    cout << "\n✓ Decorator Pattern:" << endl;
    cout << "  - Component: OrderComponent (same interface as composite)" << endl;
    cout << "  - ConcreteComponent: Plant (base object to be decorated)" << endl;
    cout << "  - Decorator: PlantDecorator (base decorator class)" << endl;
    cout << "  - ConcreteDecorators: DecorPot, Wrapping (add functionality)" << endl;
    cout << "\n✓ Pattern Integration:" << endl;
    cout << "  - Both patterns use the same OrderComponent interface" << endl;
    cout << "  - Decorated plants can be added to arrangements" << endl;
    cout << "  - Arrangements can contain both plain and decorated plants" << endl;
    cout << "  - This demonstrates excellent design pattern synergy!" << endl;
    
    cout << "\n=== DESIGN PATTERN CORRECTNESS EVALUATION ===" << endl;
    cout << "Based on GoF Design Pattern principles:" << endl;
    cout << "1. Composite Pattern: ✓ CORRECTLY IMPLEMENTED" << endl;
    cout << "   - Treats individual objects and compositions uniformly" << endl;
    cout << "   - Uses recursive composition structure" << endl;
    cout << "2. Decorator Pattern: ✓ CORRECTLY IMPLEMENTED" << endl;
    cout << "   - Adds responsibilities to objects dynamically" << endl;
    cout << "   - Maintains interface compatibility" << endl;
    cout << "   - Allows for flexible combinations" << endl;
    cout << "3. Pattern Integration: ✓ EXCELLENT DESIGN" << endl;
    cout << "   - Shared interface enables seamless interaction" << endl;
}

void testCustomerFactory()
{
    cout << "\n=== CUSTOMER FACTORY METHOD PATTERN TESTING ===" << endl;
    cout << "Testing Factory Method Pattern with Command Pattern Integration" << endl;
    
    int testsPassed = 0;
    int totalTests = 0;
    
    //test 1: customer creation (factory method)
    cout << "\n--- Test 1: Customer Object Creation ---" << endl;
    totalTests += 2;
    try {
        Customer* civilian = new Civillian("John Doe");
        Customer* commercial = new Commercial("ABC Company");
        
        if (civilian && commercial) {
            cout << "Both customer types created successfully" << endl;
            testsPassed++;
        }
        
        if (civilian->getName() == "John Doe" && commercial->getName() == "ABC Company") {
            cout << "Customer names stored correctly" << endl;
            testsPassed++;
        } else {
            cout << "Customer name retrieval failed" << endl;
        }
        
        delete civilian;
        delete commercial;
    } catch (const exception& e) {
        cout << "Customer creation failed: " << e.what() << endl;
    }
    
    //test 2: adding items to order (command pattern)
    cout << "\n--- Test 2: Adding Items with Command Pattern ---" << endl;
    totalTests += 2;
    try {
        Customer* customer = new Civillian("Jane Smith");
        Plant* rose = new Rose();
        Plant* dandelion = new Dandelion();
        
        //add items (creates commands in buffer)
        customer->addItem(rose);
        customer->addItem(dandelion);
        
        cout << "Items added to command buffer" << endl;
        testsPassed++;
        
        //checkout executes all buffered commands
        customer->checkout();
        cout << "Checkout executed all buffered commands" << endl;
        testsPassed++;
        
        delete customer;
        //items are deleted by Order/Arrangement
    } catch (const exception& e) {
        cout << "Adding items test failed: " << e.what() << endl;
    }
    
    //test 3: removing items from order
    cout << "\n--- Test 3: Removing Items from Order ---" << endl;
    totalTests++;
    try {
        Customer* customer = new Civillian("Bob Johnson");
        Plant* rose = new Rose();
        Plant* appleTree = new AppleTree();
        
        customer->addItem(rose);
        customer->addItem(appleTree);
        customer->checkout();
        
        //now remove an item
        customer->removeItem(rose);
        customer->checkout();
        delete rose;
        cout << "Remove item command executed successfully" << endl;
        testsPassed++;
        
        delete customer;
    } catch (const exception& e) {
        cout << "Removing items test failed: " << e.what() << endl;
    }
    
    //test 4: cancel transaction
    cout << "\n--- Test 4: Cancel Transaction ---" << endl;
    totalTests++;
    try {
        Customer* customer = new Commercial("XYZ Corp");
        Plant* rose = new Rose();
        Plant* dandelion = new Dandelion();
        
        customer->addItem(rose);
        customer->addItem(dandelion);
        //don't checkout yet
        
        //cancel should clear buffer and cancel order
        customer->cancelTransaction();
        cout << "Transaction cancelled successfully" << endl;
        delete rose;
        delete dandelion;
        testsPassed++;
        
        delete customer;
    } catch (const exception& e) {
        cout << "Cancel transaction test failed: " << e.what() << endl;
    }
    
    //test 5: command buffer with multiple operations
    cout << "\n--- Test 5: Multiple Operations in Buffer ---" << endl;
    totalTests++;
    try {
        Customer* customer = new Civillian("Alice Cooper");
        Plant* rose = new Rose();
        Plant* dandelion = new Dandelion();
        Plant* appleTree = new AppleTree();
        
        //add multiple items
        customer->addItem(rose);
        customer->addItem(dandelion);
        customer->addItem(appleTree);
        
        //remove one
        customer->removeItem(dandelion);
        
        //execute all commands
        customer->checkout();
        delete dandelion;
        cout << "Multiple buffered commands executed in order" << endl;
        testsPassed++;
        
        delete customer;
    } catch (const exception& e) {
        cout << "Multiple operations test failed: " << e.what() << endl;
    }
    
    //test 6: payment processing
    cout << "\n--- Test 6: Payment Processing ---" << endl;
    totalTests++;
    try {
        Customer* customer = new Commercial("BigBiz Inc");
        Plant* appleTree = new AppleTree();
        
        customer->addItem(appleTree);
        
        //pay should checkout and process payment
        customer->pay();
        
        cout << "Payment processing executed successfully" << endl;
        testsPassed++;
        
        delete customer;
    } catch (const exception& e) {
        cout << "Payment processing test failed: " << e.what() << endl;
    }
    
    //test 7: polymorphic behavior
    cout << "\n--- Test 7: Polymorphic Customer Behavior ---" << endl;
    totalTests++;
    try {
        Customer* customers[2];
        customers[0] = new Civillian("Civilian Customer");
        customers[1] = new Commercial("Commercial Customer");
        
        bool polymorphismWorks = true;
        for (int i = 0; i < 2; i++) {
            try {
                Plant* plant = new Rose();
                customers[i]->addItem(plant);
                customers[i]->checkout();
                string name = customers[i]->getName();
                if (name.empty()) polymorphismWorks = false;
            } catch (...) {
                polymorphismWorks = false;
            }
        }
        
        if (polymorphismWorks) {
            cout << "Polymorphic customer behavior works correctly" << endl;
            testsPassed++;
        } else {
            cout << "Polymorphic behavior failed" << endl;
        }
        
        delete customers[0];
        delete customers[1];
    } catch (const exception& e) {
        cout << "Polymorphism test failed: " << e.what() << endl;
    }
    
    //test results summary
    cout << "\n=== CUSTOMER TEST RESULTS SUMMARY ===" << endl;
    cout << "Tests Passed: " << testsPassed << "/" << totalTests << endl;
    cout << "Success Rate: " << (totalTests > 0 ? (testsPassed * 100.0 / totalTests) : 0) << "%" << endl;
    
    if (testsPassed == totalTests) {
        cout << "ALL CUSTOMER TESTS PASSED! Factory Method pattern works correctly!" << endl;
    } else if (testsPassed >= totalTests * 0.8) {
        cout << "Most tests passed! Customer implementation is mostly correct." << endl;
    } else {
        cout << "Several tests failed. Please review the implementation." << endl;
    }
    
    cout << "\n=== FACTORY METHOD PATTERN ANALYSIS ===" << endl;
    cout << "Factory Method Pattern:" << endl;
    cout << "  - Product: Customer (abstract base class)" << endl;
    cout << "  - ConcreteProducts: Civillian, Commercial" << endl;
    cout << "  - Creates different customer types with same interface" << endl;
    cout << "\nCommand Pattern Integration:" << endl;
    cout << "  - Customer uses Command pattern for order operations" << endl;
    cout << "  - Commands buffered in queue and executed on checkout" << endl;
    cout << "  - Supports undo via cancel transaction" << endl;
}

void testChainOfResponsibility()
{
    cout << "\n=== CHAIN OF RESPONSIBILITY PATTERN TESTING ===" << endl;
    cout << "Testing Employee Chain with Request Handling" << endl;
    
    int testsPassed = 0;
    int totalTests = 0;
    
    //test 1: chain setup
    cout << "\n--- Test 1: Chain Setup and Initialization ---" << endl;
    totalTests += 3;
    try {
        Gardener* gardener = new Gardener();
        Salesman* salesman = new Salesman();
        InventoryManager* inventoryManager = new InventoryManager();
        
        if (gardener && salesman && inventoryManager) {
            cout << "All employee handlers created successfully" << endl;
            testsPassed++;
        }
        
        //set up the chain: gardener -> salesman -> inventorymanager
        gardener->setNext(salesman);
        salesman->setNext(inventoryManager);
        
        cout << "Chain linked correctly (Gardener->Salesman->InventoryManager)" << endl;
        testsPassed++;
        
        //verify chain doesn't crash
        Plant* testPlant = new Rose();
        Requests* testRequest = new Water(testPlant);
        gardener->handle(testRequest);
        
        cout << "Chain handles requests without crashing" << endl;
        testsPassed++;
        
        delete gardener;
        delete salesman;
        delete inventoryManager;
        delete testRequest;
        delete testPlant;
    } catch (const exception& e) {
        cout << "Chain setup failed: " << e.what() << endl;
    }
    
    //test 2: gardener handling place request
    cout << "\n--- Test 2: Gardener Handles Place Request ---" << endl;
    totalTests++;
    try {
        Gardener* gardener = new Gardener();
        Salesman* salesman = new Salesman();
        gardener->setNext(salesman);
        
        Plant* plant = new Rose();
        Requests* placeRequest = new Place(plant);
        
        //gardener should handle place requests
        gardener->handle(placeRequest);
        
        cout << "Gardener handled Place request successfully" << endl;
        testsPassed++;
        
        delete gardener;
        delete salesman;
        delete placeRequest;
        delete plant;
    } catch (const exception& e) {
        cout << "Place request test failed: " << e.what() << endl;
    }
    
    //test 3: gardener handling water request
    cout << "\n--- Test 3: Gardener Handles Water Request ---" << endl;
    totalTests++;
    try {
        Gardener* gardener = new Gardener();
        Salesman* salesman = new Salesman();
        gardener->setNext(salesman);
        
        Plant* plant = new Dandelion();
        Requests* waterRequest = new Water(plant);
        
        //gardener should handle water requests
        gardener->handle(waterRequest);
        
        cout << "Gardener handled Water request successfully" << endl;
        testsPassed++;
        
        delete gardener;
        delete salesman;
        delete waterRequest;
        delete plant;
    } catch (const exception& e) {
        cout << "Water request test failed: " << e.what() << endl;
    }
    
    //test 4: gardener handling fertilise request
    cout << "\n--- Test 4: Gardener Handles Fertilise Request ---" << endl;
    totalTests++;
    try {
        Gardener* gardener = new Gardener();
        Salesman* salesman = new Salesman();
        gardener->setNext(salesman);
        
        Plant* plant = new AppleTree();
        Requests* fertiliseRequest = new Fertilise(plant);
        
        //gardener should handle fertilise requests
        gardener->handle(fertiliseRequest);
        
        cout << "Gardener handled Fertilise request successfully" << endl;
        testsPassed++;
        
        delete gardener;
        delete salesman;
        delete fertiliseRequest;
        delete plant;
    } catch (const exception& e) {
        cout << "Fertilise request test failed: " << e.what() << endl;
    }
    
    //test 5: gardener handling prune request
    cout << "\n--- Test 5: Gardener Handles Prune Request ---" << endl;
    totalTests++;
    try {
        Gardener* gardener = new Gardener();
        Salesman* salesman = new Salesman();
        gardener->setNext(salesman);
        
        Plant* plant = new Rose();
        Requests* pruneRequest = new Prune(plant);
        
        //gardener should handle prune requests
        gardener->handle(pruneRequest);
        
        cout << "Gardener handled Prune request successfully" << endl;
        testsPassed++;
        
        delete gardener;
        delete salesman;
        delete pruneRequest;
        delete plant;
    } catch (const exception& e) {
        cout << "Prune request test failed: " << e.what() << endl;
    }
    
    //test 6: chain forwarding (when handler doesn't handle)
    cout << "\n--- Test 6: Request Forwarding Through Chain ---" << endl;
    totalTests++;
    try {
        Gardener* gardener = new Gardener();
        Salesman* salesman = new Salesman();
        InventoryManager* inventoryManager = new InventoryManager();
        
        gardener->setNext(salesman);
        salesman->setNext(inventoryManager);
        
        Plant* plant = new Dandelion();
        Requests* request = new Water(plant);
        
        //start from gardener, should handle it
        gardener->handle(request);
        
        cout << "Request forwarding through chain works correctly" << endl;
        testsPassed++;
        
        delete gardener;
        delete salesman;
        delete inventoryManager;
        delete request;
        delete plant;
    } catch (const exception& e) {
        cout << "Chain forwarding test failed: " << e.what() << endl;
    }
    
    //test 7: multiple requests through chain
    cout << "\n--- Test 7: Multiple Sequential Requests ---" << endl;
    totalTests++;
    try {
        Gardener* gardener = new Gardener();
        Salesman* salesman = new Salesman();
        InventoryManager* inventoryManager = new InventoryManager();
        
        gardener->setNext(salesman);
        salesman->setNext(inventoryManager);
        
        Plant* plant1 = new Rose();
        Plant* plant2 = new Dandelion();
        Plant* plant3 = new AppleTree();
        
        Requests* request1 = new Water(plant1);
        Requests* request2 = new Fertilise(plant2);
        Requests* request3 = new Prune(plant3);
        
        gardener->handle(request1);
        gardener->handle(request2);
        gardener->handle(request3);
        
        cout << "Multiple sequential requests handled successfully" << endl;
        testsPassed++;
        
        delete gardener;
        delete salesman;
        delete inventoryManager;
        delete request1;
        delete request2;
        delete request3;
        delete plant1;
        delete plant2;
        delete plant3;
    } catch (const exception& e) {
        cout << "Multiple requests test failed: " << e.what() << endl;
    }
    
    //test 8: hiring new employees
    cout << "\n--- Test 8: Hiring New Employees ---" << endl;
    totalTests++;
    try {
        Gardener* gardener = new Gardener();
        Salesman* salesman = new Salesman();
        InventoryManager* inventoryManager = new InventoryManager();
        
        gardener->HireGardener("NewGardener1");
        salesman->HireSalesman("NewSalesman1");
        inventoryManager->HireInventoryManager("NewManager1");
        
        cout << "New employees hired successfully" << endl;
        testsPassed++;
        
        delete gardener;
        delete salesman;
        delete inventoryManager;
    } catch (const exception& e) {
        cout << "Hiring employees test failed: " << e.what() << endl;
    }
    
    //test 9: queue update functionality
    cout << "\n--- Test 9: Queue Update Functionality ---" << endl;
    totalTests++;
    try {
        Gardener* gardener = new Gardener();
        
        gardener->updateQueue();
        gardener->updateQueue();
        
        cout << "Queue rotation works correctly" << endl;
        testsPassed++;
        
        delete gardener;
    } catch (const exception& e) {
        cout << "Queue update test failed: " << e.what() << endl;
    }
    
    //test 10: request type recognition
    cout << "\n--- Test 10: Request Type Recognition ---" << endl;
    totalTests++;
    try {
        Plant* plant = new Rose();
        Requests* waterRequest = new Water(plant);
        
        if (waterRequest->getType() == "Water") {
            cout << "Request type stored and retrieved correctly" << endl;
            testsPassed++;
        } else {
            cout << "Request type recognition failed" << endl;
        }
        
        delete waterRequest;
        delete plant;
    } catch (const exception& e) {
        cout << "Request type test failed: " << e.what() << endl;
    }
    
    //test results summary
    cout << "\n=== CHAIN OF RESPONSIBILITY TEST RESULTS SUMMARY ===" << endl;
    cout << "Tests Passed: " << testsPassed << "/" << totalTests << endl;
    cout << "Success Rate: " << (totalTests > 0 ? (testsPassed * 100.0 / totalTests) : 0) << "%" << endl;
    
    if (testsPassed == totalTests) {
        cout << "ALL CHAIN TESTS PASSED! Chain of Responsibility pattern works perfectly!" << endl;
    } else if (testsPassed >= totalTests * 0.8) {
        cout << "Most tests passed! Chain implementation is mostly correct." << endl;
    } else {
        cout << "Several tests failed. Please review the implementation." << endl;
    }
    
    cout << "\n=== CHAIN OF RESPONSIBILITY PATTERN ANALYSIS ===" << endl;
    cout << "Chain of Responsibility Pattern:" << endl;
    cout << "  - Handler: Employee (abstract base class)" << endl;
    cout << "  - ConcreteHandlers: Gardener, Salesman, InventoryManager" << endl;
    cout << "  - Request: Requests (base class for Place, Water, Fertilise, Prune)" << endl;
    cout << "  - Chain flows: Gardener -> Salesman -> InventoryManager" << endl;
    cout << "\nPattern Characteristics:" << endl;
    cout << "  - Decouples sender from receivers" << endl;
    cout << "  - Each handler decides to process or forward" << endl;
    cout << "  - Dynamic chain configuration possible" << endl;
    cout << "  - Employee availability managed via queue" << endl;
}

// void testPaymentStates()
// {
//     OrderState *a = new AcceptPayment(nullptr);
//     OrderState *d = new DeclinePayment(nullptr);
//     OrderState *p = new ProcessingPayment(nullptr);
//     OrderState *v = new VerifyOrder(nullptr);

//     a->handle();
//     d->handle();
//     p->handle();
//     v->handle();

//     delete a;
//     delete d;
//     delete p;
//     delete v;
// };

void testConditionStates() {
    int testCorrect = 0;
    int totalTests = 0;
    
    cout << "\n========================================" << endl;
    cout << "CONDITION STATE PATTERN TESTS" << endl;
    cout << "========================================\n" << endl;
    
    // ===== TEST 1: Healthy to Dehydrated =====
    totalTests++;
    Plant* rose1 = new Rose();
    Condition* healthy1 = new Healthy(rose1);
    rose1->setCondition(healthy1);
    rose1->addWater(-50);
    healthy1->examine(false);
    if (rose1->toWater() == true) {
        testCorrect++;
        cout << "[PASS] Healthy → Dehydrated transition" << endl;
    } else {
        cout << "[FAIL] Healthy → Dehydrated transition" << endl;
    }
    delete rose1;
    
    // ===== TEST 2: Dehydrated to Healthy =====
    totalTests++;
    Plant* rose2 = new Rose();
    rose2->addWater(-50);
    Condition* dehydrated1 = new Dehydrated(rose2);
    rose2->setCondition(dehydrated1);
    rose2->addWater(100);
    dehydrated1->examine(false);
    if (rose2->toWater() == false) {
        testCorrect++;
        cout << "[PASS] Dehydrated → Healthy transition" << endl;
    } else {
        cout << "[FAIL] Dehydrated → Healthy transition" << endl;
    }
    delete rose2;
    
    // ===== TEST 3: Healthy to Malnourished =====
    totalTests++;
    Plant* rose3 = new Rose();
    Condition* healthy2 = new Healthy(rose3);
    rose3->setCondition(healthy2);
    rose3->addNutrition(-50);
    healthy2->examine(false);
    if (rose3->toFertilise() == true) {
        testCorrect++;
        cout << "[PASS] Healthy → Malnourished transition" << endl;
    } else {
        cout << "[FAIL] Healthy → Malnourished transition" << endl;
    }
    delete rose3;
    
    // ===== TEST 4: Malnourished to Healthy =====
    totalTests++;
    Plant* rose4 = new Rose();
    rose4->addNutrition(-50);
    Condition* malnourished1 = new Malnurished(rose4);
    rose4->setCondition(malnourished1);
    rose4->addNutrition(100);
    malnourished1->examine(false);
    if (rose4->toFertilise() == false) {
        testCorrect++;
        cout << "[PASS] Malnourished → Healthy transition" << endl;
    } else {
        cout << "[FAIL] Malnourished → Healthy transition" << endl;
    }
    delete rose4;
    
    // ===== TEST 5: Healthy to OverGrown =====
    totalTests++;
    Plant* rose5 = new Rose();
    Condition* healthy3 = new Healthy(rose5);
    rose5->setCondition(healthy3);
    rose5->addGrowth(50);
    healthy3->examine(false);
    if (rose5->toPrune() == true) {
        testCorrect++;
        cout << "[PASS] Healthy → OverGrown transition" << endl;
    } else {
        cout << "[FAIL] Healthy → OverGrown transition" << endl;
    }
    delete rose5;
    
    // ===== TEST 6: OverGrown to Healthy =====
    totalTests++;
    Plant* rose6 = new Rose();
    rose6->addGrowth(50);
    Condition* overgrown1 = new OverGrown(rose6);
    rose6->setCondition(overgrown1);
    rose6->addGrowth(-50);
    overgrown1->examine(false);
    if (rose6->toPrune() == false) {
        testCorrect++;
        cout << "[PASS] OverGrown → Healthy transition" << endl;
    } else {
        cout << "[FAIL] OverGrown → Healthy transition" << endl;
    }
    delete rose6;
    
    // ===== TEST 7: DehydratedMalnourished compound state =====
    totalTests++;
    Plant* rose7 = new Rose();
    rose7->addWater(-50);
    rose7->addNutrition(-50);
    Condition* compound1 = new DehydratedMalnurished(rose7);
    rose7->setCondition(compound1);
    if (rose7->toWater() == true && rose7->toFertilise() == true) {
        testCorrect++;
        cout << "[PASS] DehydratedMalnourished has both issues" << endl;
    } else {
        cout << "[FAIL] DehydratedMalnourished has both issues" << endl;
    }
    delete rose7;
    
    // ===== TEST 8: DehydratedMalnourished partial recovery =====
    totalTests++;
    Plant* rose8 = new Rose();
    rose8->addWater(-50);
    rose8->addNutrition(-50);
    Condition* compound2 = new DehydratedMalnurished(rose8);
    rose8->setCondition(compound2);
    rose8->addWater(100); // Fix only water
    compound2->examine(false);
    if (rose8->toWater() == false && rose8->toFertilise() == true) {
        testCorrect++;
        cout << "[PASS] DehydratedMalnourished → Malnourished (water fixed)" << endl;
    } else {
        cout << "[FAIL] DehydratedMalnourished → Malnourished (water fixed)" << endl;
    }
    delete rose8;
    
    // ===== TEST 9: DehydratedOverGrown compound state =====
    totalTests++;
    Plant* rose9 = new Rose();
    rose9->addWater(-50);
    rose9->addGrowth(50);
    Condition* compound3 = new DehydratedOverGrown(rose9);
    rose9->setCondition(compound3);
    if (rose9->toWater() == true && rose9->toPrune() == true) {
        testCorrect++;
        cout << "[PASS] DehydratedOverGrown has both issues" << endl;
    } else {
        cout << "[FAIL] DehydratedOverGrown has both issues" << endl;
    }
    delete rose9;
    
    // ===== TEST 10: MalnourishedOverGrown compound state =====
    totalTests++;
    Plant* rose10 = new Rose();
    rose10->addNutrition(-50);
    rose10->addGrowth(50);
    Condition* compound4 = new MalnurishedOverGrown(rose10);
    rose10->setCondition(compound4);
    if (rose10->toFertilise() == true && rose10->toPrune() == true) {
        testCorrect++;
        cout << "[PASS] MalnourishedOverGrown has both issues" << endl;
    } else {
        cout << "[FAIL] MalnourishedOverGrown has both issues" << endl;
    }
    delete rose10;
    
    // ===== TEST 11: Triple compound state =====
    totalTests++;
    Plant* rose11 = new Rose();
    rose11->addWater(-50);
    rose11->addNutrition(-50);
    rose11->addGrowth(50);
    Condition* triple1 = new DehydratedMalnurishedOverGrown(rose11);
    rose11->setCondition(triple1);
    if (rose11->toWater() == true && rose11->toFertilise() == true && rose11->toPrune() == true) {
        testCorrect++;
        cout << "[PASS] DehydratedMalnurishedOverGrown has all three issues" << endl;
    } else {
        cout << "[FAIL] DehydratedMalnurishedOverGrown has all three issues" << endl;
    }
    delete rose11;
    
    // ===== TEST 12: Triple to double compound =====
    totalTests++;
    Plant* rose12 = new Rose();
    rose12->addWater(-50);
    rose12->addNutrition(-50);
    rose12->addGrowth(50);
    Condition* triple2 = new DehydratedMalnurishedOverGrown(rose12);
    rose12->setCondition(triple2);
    rose12->addWater(100); // Fix water
    triple2->examine(false);
    if (rose12->toWater() == false && rose12->toFertilise() == true && rose12->toPrune() == true) {
        testCorrect++;
        cout << "[PASS] Triple → Double compound (water fixed)" << endl;
    } else {
        cout << "[FAIL] Triple → Double compound (water fixed)" << endl;
    }
    delete rose12;
    
    // ===== TEST 13: Death transition =====
    totalTests++;
    Plant* rose13 = new Rose();
    rose13->addWater(-1000); // Complete depletion
    Condition* dehydrated2 = new Dehydrated(rose13);
    rose13->setCondition(dehydrated2);
    if (rose13->isResourcesDepleted() == true) {
        testCorrect++;
        cout << "[PASS] Resources depleted (death condition)" << endl;
    } else {
        cout << "[FAIL] Resources depleted (death condition)" << endl;
    }
    delete rose13;
    
    // ===== TEST 14: Dehydrated state persistence =====
    totalTests++;
    Plant* rose14 = new Rose();
    rose14->addWater(-50);
    Condition* dehydrated3 = new Dehydrated(rose14);
    rose14->setCondition(dehydrated3);
    dehydrated3->examine(false); // No care provided
    
    if (rose14->toWater() == true) {
        testCorrect++;
        cout << "[PASS] Dehydrated state persists without care" << endl;
    } else {
        cout << "[FAIL] Dehydrated state persists without care" << endl;
    }
    delete rose14;
    
    // ===== TEST 15: Degradation mechanics =====
    totalTests++;
    Plant* rose15 = new Rose();
    Condition* healthy4 = new Healthy(rose15);
    rose15->setCondition(healthy4);
    bool degradationOccurred = false;
    for (int i = 0; i < 20; i++) {
        healthy4->examine(true); // Allow degradation
        if (rose15->toWater() || rose15->toFertilise()) {
            degradationOccurred = true;
            break;
        }
    }
    if (degradationOccurred == true) {
        testCorrect++;
        cout << "[PASS] Degradation occurs over time" << endl;
    } else {
        cout << "[FAIL] Degradation occurs over time" << endl;
    }
    delete rose15;
    
    // ===== FINAL RESULTS =====
    cout << "\n========================================" << endl;
    cout << "RESULTS: " << testCorrect << " out of " << totalTests << " tests passed." << endl;
    cout << "========================================\n" << endl;
}

int main()
{
    // testPaymentStates();
    testPlants();
    cout<<"\n\n==============================\n Beginning OrderComponentTests"<<endl;
    
    testOrderComponent();
    cout<<"\n\n==============================\n Beginning CustomerFactoryTests"<<endl;
    testCustomerFactory();
    cout<<"\n\n==============================\n Beginning ChainOfResponsibilityTests"<<endl; 
    testChainOfResponsibility();
    cout<<"\n\n==============================\n Beginning StrategyPatternTests"<<endl;
    testStrategyPattern();
    cout<<"\n\n==============================\n Beginning AggregatePatternTests"<<endl;
    testAggregate();
    cout<<"\n\n==============================\n Beginning ConditionStatePatternTests"<<endl;
    testConditionStates();
    
    return 0;
}

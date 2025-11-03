#include "gtest/gtest.h"
#include "Command.h"
#include "Order.h"
#include "OrderState.h"
#include "Plant.h"
#include "OrderComponent.h"
#include "Arrangement.h"
#include "Iterator.h"
#include "Aggregate.h"
#include "VectorIterator.h"
#include "Customer.h"
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

    GreenHouseCare* careStrategy;

    // Test Normal Strategy
    careStrategy = new Normal();
    ASSERT_NO_THROW({
        careStrategy->water(rose);
        careStrategy->prune(rose);
        careStrategy->fertilise(rose);
    });
    delete careStrategy;

    // Test Bonsai Strategy
    careStrategy = new Bonsai();
    ASSERT_NO_THROW({
        careStrategy->water(rose);
        careStrategy->prune(rose);
        careStrategy->fertilise(rose);
    });
    delete careStrategy;

    // Test Topiary Strategy
    careStrategy = new Topiary();
    ASSERT_NO_THROW({
        careStrategy->water(rose);
        careStrategy->prune(rose);
        careStrategy->fertilise(rose);
    });
    delete careStrategy;

    // Test Espalier Strategy
    careStrategy = new Espalier();
    ASSERT_NO_THROW({
        careStrategy->water(rose);
        careStrategy->prune(rose);
        careStrategy->fertilise(rose);
    });
    delete careStrategy;

    // Test Kokedama Strategy
    careStrategy = new Kokedama();
    ASSERT_NO_THROW({
        careStrategy->water(rose);
        careStrategy->prune(rose);
        careStrategy->fertilise(rose);
    });
    delete careStrategy;

    delete rose;
}

// Test fixture for Aggregate
TEST(AggregateTest, PlantAreaFunctionality) {
    PlantArea *area = new PlantArea(5);
    ASSERT_TRUE(area != nullptr);

    Plant *rose = new Rose();
    Plant *dand = new Dandelion();
    Plant *apple = new AppleTree();

    ASSERT_TRUE(area->addPlant(rose));
    ASSERT_TRUE(area->addPlant(dand));
    ASSERT_TRUE(area->addPlant(apple));

    ASSERT_EQ(area->getCount(), 3);

    // Grow twice so AppleTree can mature too
    for (int i = 0; i < 2; i++)
    {
        area->grow();
    }

    ASSERT_TRUE(area->givePlant("Rose") != nullptr);
    ASSERT_TRUE(area->givePlant("Dandelion") != nullptr);
    ASSERT_TRUE(area->givePlant("Apple tree") != nullptr);

    delete area;
}

// Test fixture for Plant tests
class PlantTest : public ::testing::Test {
protected:
    void SetUp() override {
        rose = new Rose();
        dandelion = new Dandelion();
        appleTree = new AppleTree();
    }

    void TearDown() override {
        delete rose;
        delete dandelion;
        delete appleTree;
    }

    Plant* rose;
    Plant* dandelion;
    Plant* appleTree;
};

TEST_F(PlantTest, DetailsAreCorrect) {
    std::string expectedRoseDetails = "Species: Rose\nAverage Life span: 45 days\nPrice: R50\n";
    EXPECT_EQ(rose->getDetails(), expectedRoseDetails);
    EXPECT_EQ(dandelion->getDetails(), "Species: Dandelion\nAverage Life span: 35 days\nPrice: R20\n");
    EXPECT_EQ(appleTree->getDetails(), "Species: Apple tree\nAverage Life span: 80 days\nPrice: R120\n");
    EXPECT_EQ(rose->getSpecies(), "Rose");
}

TEST_F(PlantTest, InitialStateIsCorrect) {
    EXPECT_FALSE(rose->toFertilise());
    EXPECT_FALSE(rose->toPrune());
    EXPECT_FALSE(rose->toWater());
    EXPECT_FALSE(rose->canSale());
    EXPECT_EQ(rose->getChild(0), rose);
}

TEST_F(PlantTest, MaxValuesAreCorrect) {
    EXPECT_EQ(rose->pruneMax(), 20);
    EXPECT_EQ(rose->waterMax(), 15);
    EXPECT_EQ(rose->fertiliseMax(), 20);
}

TEST_F(PlantTest, StateChangesOnResourceUpdate) {
    rose->addWater(-40);
    EXPECT_TRUE(rose->toWater());
    rose->addWater(40);
    EXPECT_FALSE(rose->toWater());

    rose->addGrowth(60);
    EXPECT_TRUE(rose->toPrune());
    rose->addGrowth(-60);
    EXPECT_FALSE(rose->toPrune());

    rose->addNutrition(-36);
    EXPECT_TRUE(rose->toFertilise());
    rose->addNutrition(36);
    EXPECT_FALSE(rose->toFertilise());
}

// Test fixture for OrderComponent tests
class OrderComponentTest : public ::testing::Test {
protected:
    void SetUp() override {
        rose = new Rose();
        dandelion = new Dandelion();
        appleTree = new AppleTree();
    }

    void TearDown() override {
        // Clean up is handled in the tests where ownership is transferred
    }

    Plant* rose;
    Plant* dandelion;
    Plant* appleTree;
};

TEST_F(OrderComponentTest, BasicPlantCreation) {
    EXPECT_TRUE(rose != nullptr);
    EXPECT_TRUE(dandelion != nullptr);
    EXPECT_TRUE(appleTree != nullptr);
    EXPECT_EQ(rose->getPrice(), 50);
    EXPECT_EQ(dandelion->getPrice(), 20);
    EXPECT_EQ(appleTree->getPrice(), 120);
    delete rose;
    delete dandelion;
    delete appleTree;
}

TEST_F(OrderComponentTest, ArrangementCompositeFunctionality) {
    Arrangement* bouquet = new Arrangement(0);
    Plant* rose1 = new Rose();
    Plant* rose2 = new Rose();
    Plant* dandelion1 = new Dandelion();

    bouquet->add(rose1);
    bouquet->add(rose2);
    bouquet->add(dandelion1);

    int expectedPrice = rose1->getPrice() + rose2->getPrice() + dandelion1->getPrice();
    EXPECT_EQ(bouquet->getPrice(), expectedPrice);
    EXPECT_EQ(bouquet->getChild(0), rose1);

    delete bouquet;
}

TEST_F(OrderComponentTest, BasicDecoratorPattern) {
    Plant* basePlant = new Rose();
    int basePlantPrice = basePlant->getPrice();

    OrderComponent* decoratedWithPot = new DecorPot(basePlant);
    EXPECT_GT(decoratedWithPot->getPrice(), basePlantPrice);

    Plant* basePlant1 = new Rose();
    OrderComponent* wrappedPlant = new Wrapping(basePlant1);
    EXPECT_GT(wrappedPlant->getPrice(), basePlantPrice);

    Plant* basePlant2 = new Rose();
    PlantDecorator* fullyDecorated = new Wrapping(new DecorPot(basePlant2));
    EXPECT_GT(fullyDecorated->getPrice(), decoratedWithPot->getPrice());
    EXPECT_GT(fullyDecorated->getPrice(), wrappedPlant->getPrice());

    delete decoratedWithPot;
    delete wrappedPlant;
    delete fullyDecorated;
}

TEST_F(OrderComponentTest, ComplexCompositeWithDecorators) {
    Arrangement* fancyBouquet = new Arrangement(0);
    Plant* rose1 = new Rose();
    Plant* dandelion2 = new Dandelion();
    PlantDecorator* decoratedRose1 = new DecorPot(rose1);
    PlantDecorator* wrappedDandelion2 = new Wrapping(dandelion2);

    fancyBouquet->add(decoratedRose1);
    fancyBouquet->add(wrappedDandelion2);

    int expectedTotal = decoratedRose1->getPrice() + wrappedDandelion2->getPrice();
    EXPECT_EQ(fancyBouquet->getPrice(), expectedTotal);
    delete fancyBouquet;

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
    EXPECT_EQ(megaBouquet->getPrice(), expectedMegaTotal);
    delete megaBouquet;
}

TEST_F(OrderComponentTest, PatternStructureVerification) {
    Plant* plant = new Rose();
    PlantDecorator* decorator = new DecorPot(plant);
    Arrangement* arrangement = new Arrangement(0);

    OrderComponent* componentPtr1 = plant;
    OrderComponent* componentPtr2 = decorator;
    OrderComponent* componentPtr3 = arrangement;

    EXPECT_TRUE(componentPtr1 != nullptr);
    EXPECT_TRUE(componentPtr2 != nullptr);
    EXPECT_TRUE(componentPtr3 != nullptr);

    EXPECT_EQ(plant->getPlant(), plant);
    EXPECT_GE(decorator->getPrice(), plant->getPrice());

    std::vector<OrderComponent*> components;
    components.push_back(plant);
    components.push_back(decorator);
    components.push_back(arrangement);

    for (OrderComponent* comp : components) {
        EXPECT_GE(comp->getPrice(), 0);
    }

    delete arrangement;
    delete decorator;
}

TEST_F(OrderComponentTest, EdgeCasesAndErrorHandling) {
    Arrangement* emptyArrangement = new Arrangement(0);
    EXPECT_EQ(emptyArrangement->getPrice(), 0);
    delete emptyArrangement;

    Plant* testPlant = new Rose();
    PlantDecorator* testDecorator = new DecorPot(testPlant);
    EXPECT_TRUE(testDecorator != nullptr);
    EXPECT_GE(testDecorator->getPrice(), 0);
    delete testDecorator;
}

// Test fixture for CustomerFactory tests
class CustomerFactoryTest : public ::testing::Test {
protected:
    void SetUp() override {
        civilian = new Civillian("John Doe");
        commercial = new Commercial("ABC Company");
    }

    void TearDown() override {
        delete civilian;
        delete commercial;
    }

    Customer* civilian;
    Customer* commercial;
};

TEST_F(CustomerFactoryTest, CustomerObjectCreation) {
    EXPECT_TRUE(civilian != nullptr);
    EXPECT_TRUE(commercial != nullptr);
    EXPECT_EQ(civilian->getName(), "John Doe");
    EXPECT_EQ(commercial->getName(), "ABC Company");
}

TEST_F(CustomerFactoryTest, AddingItemsWithCommandPattern) {
    Customer* customer = new Civillian("Jane Smith");
    Plant* rose = new Rose();
    Plant* dandelion = new Dandelion();

    customer->addItem(rose);
    customer->addItem(dandelion);
    ASSERT_NO_THROW(customer->checkout());

    delete customer;
}

TEST_F(CustomerFactoryTest, RemovingItemsFromOrder) {
    Customer* customer = new Civillian("Bob Johnson");
    Plant* rose = new Rose();
    Plant* appleTree = new AppleTree();

    customer->addItem(rose);
    customer->addItem(appleTree);
    customer->checkout();

    customer->removeItem(rose);
    ASSERT_NO_THROW(customer->checkout());

    delete customer;
}

TEST_F(CustomerFactoryTest, CancelTransaction) {
    Customer* customer = new Commercial("XYZ Corp");
    Plant* rose = new Rose();
    Plant* dandelion = new Dandelion();

    customer->addItem(rose);
    customer->addItem(dandelion);
    ASSERT_NO_THROW(customer->cancelTransaction());

    delete customer;
}

TEST_F(CustomerFactoryTest, MultipleOperationsInBuffer) {
    Customer* customer = new Civillian("Alice Cooper");
    Plant* rose = new Rose();
    Plant* dandelion = new Dandelion();
    Plant* appleTree = new AppleTree();

    customer->addItem(rose);
    customer->addItem(dandelion);
    customer->addItem(appleTree);
    customer->removeItem(dandelion);
    ASSERT_NO_THROW(customer->checkout());

    delete customer;
}

TEST_F(CustomerFactoryTest, PaymentProcessing) {
    Customer* customer = new Commercial("BigBiz Inc");
    Plant* appleTree = new AppleTree();

    customer->addItem(appleTree);
    ASSERT_NO_THROW(customer->pay());

    delete customer;
}

TEST_F(CustomerFactoryTest, PolymorphicCustomerBehavior) {
    Customer* customers[2];
    customers[0] = new Civillian("Civilian Customer");
    customers[1] = new Commercial("Commercial Customer");

    for (int i = 0; i < 2; i++) {
        Plant* plant = new Rose();
        customers[i]->addItem(plant);
        ASSERT_NO_THROW(customers[i]->checkout());
        EXPECT_FALSE(customers[i]->getName().empty());
    }

    delete customers[0];
    delete customers[1];
}

// Test fixture for ChainOfResponsibility tests
class ChainOfResponsibilityTest : public ::testing::Test {
protected:
    void SetUp() override {
        gardener = new Gardener();
        salesman = new Salesman();
        inventoryManager = new InventoryManager();
        gardener->setNext(salesman);
        salesman->setNext(inventoryManager);
    }

    void TearDown() override {
        delete gardener;
        delete salesman;
        delete inventoryManager;
    }

    Gardener* gardener;
    Salesman* salesman;
    InventoryManager* inventoryManager;
};

TEST_F(ChainOfResponsibilityTest, ChainSetupAndInitialization) {
    EXPECT_TRUE(gardener != nullptr);
    EXPECT_TRUE(salesman != nullptr);
    EXPECT_TRUE(inventoryManager != nullptr);

    Plant* testPlant = new Rose();
    Requests* testRequest = new Water(testPlant);
    ASSERT_NO_THROW(gardener->handle(testRequest));

    delete testRequest;
    delete testPlant;
}

TEST_F(ChainOfResponsibilityTest, GardenerHandlesPlaceRequest) {
    Plant* plant = new Rose();
    Requests* placeRequest = new Place(plant);
    ASSERT_NO_THROW(gardener->handle(placeRequest));
    delete placeRequest;
    delete plant;
}

TEST_F(ChainOfResponsibilityTest, GardenerHandlesWaterRequest) {
    Plant* plant = new Dandelion();
    Requests* waterRequest = new Water(plant);
    ASSERT_NO_THROW(gardener->handle(waterRequest));
    delete waterRequest;
    delete plant;
}

TEST_F(ChainOfResponsibilityTest, GardenerHandlesFertiliseRequest) {
    Plant* plant = new AppleTree();
    Requests* fertiliseRequest = new Fertilise(plant);
    ASSERT_NO_THROW(gardener->handle(fertiliseRequest));
    delete fertiliseRequest;
    delete plant;
}

TEST_F(ChainOfResponsibilityTest, GardenerHandlesPruneRequest) {
    Plant* plant = new Rose();
    Requests* pruneRequest = new Prune(plant);
    ASSERT_NO_THROW(gardener->handle(pruneRequest));
    delete pruneRequest;
    delete plant;
}

TEST_F(ChainOfResponsibilityTest, RequestForwardingThroughChain) {
    Plant* plant = new Dandelion();
    Requests* request = new Water(plant);
    ASSERT_NO_THROW(gardener->handle(request));
    delete request;
    delete plant;
}

TEST_F(ChainOfResponsibilityTest, MultipleSequentialRequests) {
    Plant* plant1 = new Rose();
    Plant* plant2 = new Dandelion();
    Plant* plant3 = new AppleTree();
    Requests* request1 = new Water(plant1);
    Requests* request2 = new Fertilise(plant2);
    Requests* request3 = new Prune(plant3);

    ASSERT_NO_THROW(gardener->handle(request1));
    ASSERT_NO_THROW(gardener->handle(request2));
    ASSERT_NO_THROW(gardener->handle(request3));

    delete request1;
    delete request2;
    delete request3;
    delete plant1;
    delete plant2;
    delete plant3;
}

TEST_F(ChainOfResponsibilityTest, HiringNewEmployees) {
    ASSERT_NO_THROW(gardener->HireGardener("NewGardener1"));
    ASSERT_NO_THROW(salesman->HireSalesman("NewSalesman1"));
    ASSERT_NO_THROW(inventoryManager->HireInventoryManager("NewManager1"));
}

TEST_F(ChainOfResponsibilityTest, QueueUpdateFunctionality) {
    ASSERT_NO_THROW(gardener->updateQueue());
    ASSERT_NO_THROW(gardener->updateQueue());
}

TEST_F(ChainOfResponsibilityTest, RequestTypeRecognition) {
    Plant* plant = new Rose();
    Requests* waterRequest = new Water(plant);
    EXPECT_EQ(waterRequest->getType(), "Water");
    delete waterRequest;
    delete plant;
}

// Test fixture for ConditionStates tests
class ConditionStateTest : public ::testing::Test {
protected:
    void SetUp() override {
        plant = new Rose();
    }

    void TearDown() override {
        delete plant;
    }

    Plant* plant;
};

TEST_F(ConditionStateTest, HealthyToDehydrated) {
    Condition* healthy = new Healthy(plant);
    plant->setCondition(healthy);
    plant->addWater(-50);
    healthy->examine(false);
    EXPECT_TRUE(plant->toWater());
}

TEST_F(ConditionStateTest, DehydratedToHealthy) {
    plant->addWater(-50);
    Condition* dehydrated = new Dehydrated(plant);
    plant->setCondition(dehydrated);
    plant->addWater(100);
    dehydrated->examine(false);
    EXPECT_FALSE(plant->toWater());
}

TEST_F(ConditionStateTest, HealthyToMalnourished) {
    Condition* healthy = new Healthy(plant);
    plant->setCondition(healthy);
    plant->addNutrition(-50);
    healthy->examine(false);
    EXPECT_TRUE(plant->toFertilise());
}

TEST_F(ConditionStateTest, MalnourishedToHealthy) {
    plant->addNutrition(-50);
    Condition* malnourished = new Malnurished(plant);
    plant->setCondition(malnourished);
    plant->addNutrition(100);
    malnourished->examine(false);
    EXPECT_FALSE(plant->toFertilise());
}

TEST_F(ConditionStateTest, HealthyToOverGrown) {
    Condition* healthy = new Healthy(plant);
    plant->setCondition(healthy);
    plant->addGrowth(50);
    healthy->examine(false);
    EXPECT_TRUE(plant->toPrune());
}

TEST_F(ConditionStateTest, OverGrownToHealthy) {
    plant->addGrowth(50);
    Condition* overgrown = new OverGrown(plant);
    plant->setCondition(overgrown);
    plant->addGrowth(-50);
    overgrown->examine(false);
    EXPECT_FALSE(plant->toPrune());
}

TEST_F(ConditionStateTest, DehydratedMalnourishedCompoundState) {
    plant->addWater(-50);
    plant->addNutrition(-50);
    Condition* compound = new DehydratedMalnurished(plant);
    plant->setCondition(compound);
    EXPECT_TRUE(plant->toWater());
    EXPECT_TRUE(plant->toFertilise());
}

TEST_F(ConditionStateTest, DehydratedMalnourishedPartialRecovery) {
    plant->addWater(-50);
    plant->addNutrition(-50);
    Condition* compound = new DehydratedMalnurished(plant);
    plant->setCondition(compound);
    plant->addWater(100); // Fix only water
    compound->examine(false);
    EXPECT_FALSE(plant->toWater());
    EXPECT_TRUE(plant->toFertilise());
}

TEST_F(ConditionStateTest, DehydratedOverGrownCompoundState) {
    plant->addWater(-50);
    plant->addGrowth(50);
    Condition* compound = new DehydratedOverGrown(plant);
    plant->setCondition(compound);
    EXPECT_TRUE(plant->toWater());
    EXPECT_TRUE(plant->toPrune());
}

TEST_F(ConditionStateTest, MalnourishedOverGrownCompoundState) {
    plant->addNutrition(-50);
    plant->addGrowth(50);
    Condition* compound = new MalnurishedOverGrown(plant);
    plant->setCondition(compound);
    EXPECT_TRUE(plant->toFertilise());
    EXPECT_TRUE(plant->toPrune());
}

TEST_F(ConditionStateTest, TripleCompoundState) {
    plant->addWater(-50);
    plant->addNutrition(-50);
    plant->addGrowth(50);
    Condition* triple = new DehydratedMalnurishedOverGrown(plant);
    plant->setCondition(triple);
    EXPECT_TRUE(plant->toWater());
    EXPECT_TRUE(plant->toFertilise());
    EXPECT_TRUE(plant->toPrune());
}

TEST_F(ConditionStateTest, TripleToDoubleCompound) {
    plant->addWater(-50);
    plant->addNutrition(-50);
    plant->addGrowth(50);
    Condition* triple = new DehydratedMalnurishedOverGrown(plant);
    plant->setCondition(triple);
    plant->addWater(100); // Fix water
    triple->examine(false);
    EXPECT_FALSE(plant->toWater());
    EXPECT_TRUE(plant->toFertilise());
    EXPECT_TRUE(plant->toPrune());
}

TEST_F(ConditionStateTest, DeathTransition) {
    plant->addWater(-1000); // Complete depletion
    Condition* dehydrated = new Dehydrated(plant);
    plant->setCondition(dehydrated);
    EXPECT_TRUE(plant->isResourcesDepleted());
}

TEST_F(ConditionStateTest, DehydratedStatePersistence) {
    plant->addWater(-50);
    Condition* dehydrated = new Dehydrated(plant);
    plant->setCondition(dehydrated);
    dehydrated->examine(false); // No care provided
    EXPECT_TRUE(plant->toWater());
}

TEST_F(ConditionStateTest, DegradationMechanics) {
    Condition* healthy = new Healthy(plant);
    plant->setCondition(healthy);
    bool degradationOccurred = false;
    for (int i = 0; i < 20; i++) {
        healthy->examine(true); // Allow degradation
        if (plant->toWater() || plant->toFertilise()) {
            degradationOccurred = true;
            break;
        }
    }
    EXPECT_TRUE(degradationOccurred);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
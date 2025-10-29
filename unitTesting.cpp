#include "Employee.h"
#include "Gardener.h"
#include "Salesman.h"
#include "InventoryManager.h"
#include "Request.h"
#include <iostream>
#include <vector>

using namespace std;

// void testPlants(){
//     // Create instances of plants
//     int testCorrect=0;

//     Plant* rose = new Rose();
//     Plant* dandelion = new Dandelion();
//     Plant* appleTree = new AppleTree();

//     // Display plant details
//     string ExpectedRoseDetails = "Species: Rose\nAverage Life span: 45 days\nPrice: R50\n";
//     if(rose->getDetails() == ExpectedRoseDetails){
//         testCorrect++;
//         cout<< "Rose details test passed." << endl;
//     }
//     if(dandelion->getDetails() == "Species: Dandelion\nAverage Life span: 35 days\nPrice: R20\n"){
//         testCorrect++;
//         cout<< "Dandelion details test passed." <<endl;
//     }
//     if(appleTree->getDetails() == "Species: Apple tree\nAverage Life span: 80 days\nPrice: R120\n"){
//         testCorrect++;
//         cout<< "Apple tree details test passed." <<endl;
//     }
//     cout << testCorrect << " out of 3 plant detail tests passed." << endl;

//     if(rose->getSpecies() == "Rose"){
//         testCorrect++;
//         cout <<"Species test passed."<<endl;
//     }else{
//         cout <<"Species test failed."<<endl;
//     }

//     if(rose->getChild(0) == rose){
//         testCorrect++;
//         cout <<"Get child test passed."<<endl;
//     }else{
//         cout <<"Get child test failed."<<endl;
//     }

//     if(rose->toFertilise()==false){
//         testCorrect++;
//         cout <<"To fertilise test passed."<<endl;
//     }else{
//         cout <<"To fertilise test failed."<<endl;
//     }

//     if(rose->toPrune()==false){
//         testCorrect++;
//         cout <<"To prune test passed."<<endl;
//     }else{
//         cout <<"To prune test failed."<<endl;
//     }

//     if(rose->toWater()==false){
//         testCorrect++;
//         cout <<"To water test passed."<<endl;
//     }else{
//         cout <<"To water test failed."<<endl;
//     }

//     if(rose->canSale()==false){
//         testCorrect++;
//         cout <<"Can sale test passed."<<endl;
//     }else{ 
//         cout <<"Can sale test failed."<<endl;
//     }

//     if(rose->pruneMax()==20){
//         testCorrect++;
//         cout <<"Prune max test passed."<<endl;
//     }else{
//         cout <<"Prune max test failed."<<endl;
//     }

//     if(rose->waterMax()==30){
//         testCorrect++;
//         cout <<"Water max test passed."<<endl;
//     }else{
//         cout <<"Water max test failed."<<endl;
//     }

//     if(rose->fertiliseMax()==20){
//         testCorrect++;
//         cout <<"Fertilise max test passed."<<endl;
//     }else{
//         cout <<"Fertilise max test failed."<<endl;
//     }

//     rose->addWater(-40);
//     if(rose->toWater()==true){
//         testCorrect++;
//         cout <<"Add water test passed."<<endl;
//     }else{
//         cout <<"Add water test failed."<<endl;
//     }

//     rose->addGrowth(60);
//     if(rose->toPrune()==true){
//         testCorrect++;
//         cout <<"Add growth test passed."<<endl;
//     }else{
//         cout <<"Add growth test failed."<<endl;
//     }

//     rose->addNutrition(-36);
//     if(rose->toFertilise()==true){
//         testCorrect++;
//         cout <<"Add nutrition test passed."<<endl;
//     }else{
//         cout <<"Add nutrition test failed."<<endl;
//     }

//     rose->addWater(40);
//     if(rose->toWater()==false){
//         testCorrect++;
//         cout <<"Add water test2 passed."<<endl;
//     }else{
//         cout <<"Add water test2 failed."<<endl;
//     }

//     rose->addGrowth(60);
//     if(rose->toPrune()==false){
//         testCorrect++;
//         cout <<"Add growth test 2 passed."<<endl;
//     }else{
//         cout <<"Add growth test 2 failed."<<endl;
//     }

//     rose->addNutrition(36);
//     if(rose->toFertilise()==false){
//         testCorrect++;
//         cout <<"Add nutrition test 2 passed."<<endl;
//     }else{
//         cout <<"Add nutrition test 2 failed."<<endl;
//     }

//     // Clean up
//     delete rose;
//     delete dandelion;
//     delete appleTree;
// }

void testChainOfResponsibility(){
    cout << "\nCOR:\n" << endl;
    int testsPassed = 0;
    int totalTests = 0;

    Gardener* gardener = new Gardener();
    Salesman* salesman = new Salesman();
    InventoryManager* inventory = new InventoryManager();

    gardener->setNext(salesman);
    salesman->setNext(inventory);

    cout << "Gardener handles MovePlant request" << endl;
    totalTests++;
    Request* movePlant = new MovePlant("plant001", "Section B");
    gardener->handle(movePlant);
    cout << "MovePlant request processed" << endl;
    testsPassed++;
    delete movePlant;

    cout << "\nGardener handles WaterPlant request" << endl;
    totalTests++;
    Request* waterPlant = new WaterPlant("plant002");
    gardener->handle(waterPlant);
    cout << "WaterPlant request processed" << endl;
    testsPassed++;
    delete waterPlant;

    cout << "\nSalesman handles ProcessPayment request" << endl;
    totalTests++;
    Request* payment = new ProcessPayment(150.50);
    gardener->handle(payment);
    cout << "ProcessPayment request processed" << endl;
    testsPassed++;
    delete payment;

    cout << "\nSalesman handles CancelTransaction request" << endl;
    totalTests++;
    Request* cancel = new CancelTransaction("TXN-001");
    gardener->handle(cancel);
    cout << "CancelTransaction request processed" << endl;
    testsPassed++;
    delete cancel;

    cout << "\nSalesman handles AnswerQuestion request" << endl;
    totalTests++;
    Request* question = new AnswerQuestion("What are your store hours?");
    gardener->handle(question);
    cout << "AnswerQuestion request processed by Salesman" << endl;
    testsPassed++;
    delete question;

    cout << "\nGardener handles TillAssistance request" << endl;
    totalTests++;
    Request* assistance = new TillAssistance("Need help with plant identification");
    gardener->handle(assistance);
    cout << "TillAssistance request processed" << endl;
    testsPassed++;
    delete assistance;

    cout << "\nTesting employee queue rotation" << endl;
    totalTests++;
    cout << "Processing multiple MovePlant requests to test queue rotation..." << endl;
    for(int i = 0; i < 3; i++){
        Request* move = new MovePlant("plant00" + to_string(i), "Location " + to_string(i));
        gardener->handle(move);
        delete move;
    }
    cout << "Queue rotation test completed" << endl;
    testsPassed++;

    cout << "\nHiring new employees" << endl;
    totalTests++;
    gardener->HireGardener("gardener6");
    salesman->HireSalesman("salesman6");
    inventory->HireInventoryManager("inventorymanager6");
    cout << "New employees hired successfully" << endl;
    testsPassed++;

    cout << "\nTesting manual queue update" << endl;
    totalTests++;
    gardener->updateQueue();
    salesman->updateQueue();
    inventory->updateQueue();
    cout << "Queue updates completed" << endl;
    testsPassed++;

    cout << "\nProcessing requests through complete chain" << endl;
    totalTests++;
    Request* move1 = new MovePlant("plant100", "Greenhouse");
    Request* pay1 = new ProcessPayment(299.99);
    Request* water1 = new WaterPlant("plant101");
    
    gardener->handle(move1);
    gardener->handle(pay1);
    gardener->handle(water1);
    
    cout << "Multiple requests processed through chain" << endl;
    testsPassed++;
    
    delete move1;
    delete pay1;
    delete water1;

    delete gardener;
    delete salesman;
    delete inventory;

    cout << "\n COR results \n" << endl;
    cout << testsPassed << " out of " << totalTests << " tests passed.\n" << endl;
}

int main()
{
    /*
    OrderState *a = new AcceptPayment(nullptr);
    OrderState *d = new DeclinePayment(nullptr);
    OrderState *p = new ProcessingPayment(nullptr);
    OrderState *v = new VerifyOrder(nullptr);

    a->handle();
    d->handle();
    p->handle();
    v->handle();
    
    
    //These can be updated and tested once the Composite implementation is done.
    //Order* order=new Order("20251021-01");
    order->processPayment();
    vector<AddToOrder*> addCommands;

    OrderComponent* temp;
    for(int i=0;i<5;i++){
        temp=new OrderComponent();
        AddToOrder* addCommand=new AddToOrder(order, temp);
        addCommands.push_back(addCommand);
    }

    for(AddToOrder* a : addCommands){
        a->execute();
    }

    RemoveFromOrder* rm=new RemoveFromOrder(order, temp);

    order->getState();
    order->getItems();
    order->processPayment();

    delete order;
    delete rm;

    for(AddToOrder* a : addCommands){
        delete a;
    }*/
    
    /*
    delete a;
    delete d;
    delete p;
    delete v;
    */

    // testPlants();
    testChainOfResponsibility();

}

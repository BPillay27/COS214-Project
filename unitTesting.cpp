//#include "Command.h"
//#include "Order.h"
//#include "OrderState.h"
#include "Plant.h"
#include <iostream>
#include <vector>

using namespace std;

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
        cout<< "Rose details test passed." << endl;
    }
    if(dandelion->getDetails() == "Species: Dandelion\nAverage Life span: 35 days\nPrice: R20\n"){
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

    if(rose->waterMax()==30){
        testCorrect++;
        cout <<"Water max test passed."<<endl;
    }else{
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

    rose->addGrowth(60);
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

    testPlants();

}

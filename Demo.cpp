
#include "Command.h"
#include "Order.h"
#include "OrderState.h"
#include "Plant.h"
#include "OrderComponent.h"
#include "Arrangement.h"
#include "Iterator.h"
#include "Aggregate.h"
#include "VectorIterator.h"
#include "Inventory.h"

#include <iostream>
#include <vector>

#include "Customer.h" //inserted this to prevent some errors
#include "Salesman.h"
#include "InventoryManager.h"
#include "Gardener.h"
#include "Employee.h"
#include "Bonsai.h"
#include "Topiary.h"
#include "Espalier.h"
#include "Kokedama.h"
#include "Normal.h"

void day(){
    Inventory::instance().getSalesArea()->grow();
    Inventory::instance().getSalesArea()->examine();
}

void customerDemo(){
    Customer* cust=nullptr;
    
    std::cout<<"Welcome to the customer section!"<<std::endl;
    std::string choice;
    Rose* rose=nullptr;
    AppleTree* appletree=nullptr;
    Dandelion* dan=nullptr;
    Arrangement* arrangement=nullptr;
    Wrapping* plastic=nullptr;
    DecorPot* pot=nullptr;

    do{
        //I have to make the order first before I can demo this properly
        cust=new Customer("John Doe");
        arrangement=new Arrangement(15);  // Create new arrangement each iteration
        rose=new Rose();
        appletree=new AppleTree();
        dan=new Dandelion();
        plastic=new Wrapping(rose);
        arrangement->add(plastic);
        arrangement->add(appletree);
        pot=new DecorPot(dan);
        cust->addItem(arrangement);
        cust->addItem(pot);

        std::cout<<"We have a premade order available for you\nYour options are to see the order, pay for it or cancel it."<<std::endl;
        std::cout<<"Type 'see' to see the order, 'pay' to pay for it, 'cancel' to cancel the order or 'exit' to exit the customer demo."<<std::endl;
        std::getline(std::cin, choice);
        if(choice == "see") {
            cust->see();
            std::cout<<"Type 'exit' to exit the customer demo or any key to try again."<<std::endl;
            std::getline(std::cin, choice);
            if(choice == "exit") {
                delete cust;
                break;
            } else {
                delete cust;
                continue;
            }
        } else if(choice == "pay") {
            while(true) {
                cust->pay();
                std::cout<<"Type 'exit' once the payment is successful and any key to continue the process."<<std::endl;
                std::getline(std::cin, choice);
                if(choice == "exit") {
                    break;
                }
            }
            //std::cout<<"The order has been cancelled."<<std::endl;
            std::cout<<"Type 'exit' to exit the customer demo or enter any key to try again."<<std::endl;
            std::getline(std::cin, choice);
            if(choice == "exit") {
                delete cust;
                break;
            }else {
                delete cust;
                continue;
            }
        } else if(choice == "cancel") {
            cust->cancelTransaction();
            std::cout<<"The order has been cancelled."<<std::endl;
            std::cout<<"Type 'exit' to exit the customer demo or any key to try again."<<std::endl;
            std::getline(std::cin, choice);
            if(choice == "exit") {
                delete cust;
                delete rose;
                delete appletree;
                delete dan;
                break;
            } else {
                delete cust;
                continue;
            }
        } else if(choice == "exit") {
            delete cust;
            break;
        } else {
            std::cout<<"That is not a valid option, please try again."<<std::endl;
            delete cust;
        }

    }while(true);
    
    return;
}

void plantDemo(){
    std::cout<<"Welcome to the plant section!"<<std::endl;
    std::string choice;

    do{
        std::cout<<"This section is boring, all the plants do really, is grow and get looked after!"<<std::endl;
        std::cout<<"Type 'exit' to exit the plant demo or 'grow' to make the plant grow.\n'die' to kill some plants and 'care' to see the gardeners take care of the plants."<<std::endl;
        std::getline(std::cin, choice);
        if(choice == "exit") {
            break;
        } else if(choice == "grow") {
            // Call the grow method on the plant
            std::cout<<"The plants will begin to grow now...\n"<<std::endl;
            //std::cout<<Inventory::instance().getSalesArea()<<std::endl;
            Inventory::instance().getSalesArea()->grow();
        }else if(choice == "die") {
            std::cout<<"Some plants will now die...\n"<<std::endl;
            //For demo purposes, we will just remove a plant from the nursery directly
            Nursery* nursery=Inventory::instance().getSalesArea();
            for(int i=0;i<25;i++){
                nursery->grow();
            }
        }else if(choice == "care") {
            std::cout<<"The gardeners will now take care of the plants...\n"<<std::endl;
            Inventory::instance().getSalesArea()->examine();
        } else {
            std::cout<<"That is not a valid option, please try again."<<std::endl;
        }
    }while(true);
}

void GameOn(){
    day();
    day();
    day();
    day();
    day();
    std::cout<<"Welcome to the PracTickler's Nursery!"<<std::endl;
    std::string choice;
    //Inventory::instance().getSalesArea()->pS();
    std::cout<<"How can we assist you today?"<<std::endl;
    std::cout<<"You can browse the nursery with 'browse', and we can recommend if you type 'recommend',\nor 'exit' to leave the our nursery."<<std::endl;
    while(true){
        std::cout<<"So what is your choice?"<<std::endl;
        std::getline(std::cin, choice);
        std::cout<<"Wise choice to pick: "<< choice << std::endl;
        if(choice == "exit") {
            std::cout<<"Thank you for visiting PracTickler's Nursery! Goodbye!"<<std::endl;
            return;
        } else if(choice == "browse") {
            Customer* cust=new Civillian("Batman");
            Nursery* nursery=Inventory::instance().getSalesArea();
            nursery->WalkThrough();
            while(true){
                std::cout<<"Here are the plants currently available in our nursery:\n "<<nursery->printPlants()<<std::endl;
                std::cout<<"You can go to the next row with 'next' and back a row with 'back', or exit with 'exit'."<<std::endl;
                std::cout<<"You can choose a plant by giving the index (starting from 0) or cancel your order with 'cancel'."<<std::endl;
                std::getline(std::cin, choice);
                if(choice == "next") {
                    if(nursery->nextRow()){
                        continue;
                    } else {
                        std::cout<<"You are already at the last row of the nursery."<<std::endl;
                    }
                } else if(choice == "back") {
                    if(nursery->prevRow()){
                        continue;
                    } else {
                        std::cout<<"You are already at the first row of the nursery."<<std::endl;
                    }
                } else if(choice == "exit") {
                    std::cout<<"Exiting the nursery walkthrough."<<std::endl;
                    cust->checkout();
                    cust->pay();
                    if(cust->getOrder()->getState() == nullptr) {
                        delete cust;
                        return;
                    }
                    while(true) {
                        std::cout<<"Press any key until the payment is accepted..."<<std::endl;
                        cust->pay();
                        std::cin.ignore();
                        std::cin.get();
                        if(cust->getOrder()->getState() == nullptr) {
                            std::cout<<"Payment accepted! Thank you for your purchase."<<std::endl;
                            delete cust;
                            return;
                        }
                    }
                }else if(std::all_of(choice.begin(), choice.end(), ::isdigit)) {
                    int index = std::stoi(choice);
                    Plant* selectedPlant = nursery->getPlant(index);
                    if(selectedPlant != nullptr) {
                        std::cout<<"You have selected a "<<selectedPlant->getSpecies()<<"."<<std::endl;
                        std::cout<<"Would you like to know more about the plant or buy it? Type 'info' for more information or 'buy' to add it to your order."<<std::endl;
                        std::getline(std::cin, choice);
                        if(choice == "info") {
                            std::cout<<"Here are the details of the plant:\n"<<selectedPlant->getDetails()<<std::endl;
                        } else if(choice == "buy") {
                            std::cout<<"Would you like to put it in a pot or wrap it as a gift? Type 'pot' for pot, 'wrap' for wrapping or 'none' for no packaging."<<std::endl;
                            while(true){
                                std::getline(std::cin, choice);
                                PlantDecorator* itemToAdd = nullptr;
                                if(choice == "pot") {
                                    itemToAdd = new DecorPot(selectedPlant);
                                    cust->addItem(itemToAdd);

                                    std::cout<<"The plant has been placed in a decorative pot and added to your order."<<std::endl;
                                    break;
                                } else if(choice == "wrap") {
                                    itemToAdd = new Wrapping(selectedPlant);
                                    cust->addItem(itemToAdd);
                                    std::cout<<"The plant has been wrapped as a gift and added to your order."<<std::endl;
                                    break;
                                } else if(choice == "none") {
                                    cust->addItem(selectedPlant);
                                    std::cout<<"The plant has been added to your order."<<std::endl;
                                    break;
                                }else{
                                    std::cout<<"That was not an option wise guy!?!**"<<std::endl;
                                }
                            }
                            
                        } else {
                            std::cout<<"Please choose a valid option."<<std::endl;
                        }
                    } else {
                        std::cout<<"Invalid index selected. Please try again."<<std::endl;
                    }
                } else if(choice == "cancel") {
                    std::cout<<"Your order has been cancelled."<<std::endl;
                    cust->cancelTransaction();
                    //delete cust;
                    continue;
                } else {
                    std::cout<<"That is not a valid option, please try again."<<std::endl;
                }
            }
            
        } else if(choice == "recommend") {
            Nursery* nursery=Inventory::instance().getSalesArea();
            //std::vector<std::string> plants=nursery->recommendations();
            std::cout<<"Based on our current stock, we recommend the following plants:\n";
            std::vector<std::string> plants = nursery->recommendations();
            //std::cout<<" Size of recommendations: "<< plants.size() << std::endl;
            for (auto it = plants.begin(); it != plants.end(); ++it) {
                std::cout << *it << std::endl;
            }
            std::cout<<"You can continue browsing, ask for more recommendations, or exit."<<std::endl;
        } else {
            std::cout<<"That is not a valid option, please try again."<<std::endl;
        }
    }
}

int main()
{
    Inventory::instance();
    Nursery* area=Inventory::instance().getSalesArea();
    //area->grow();
    Plant* rosey=new Rose();
    Plant* appley=new AppleTree();
    Plant* dand=new Dandelion();
    Gardener* gard=new Gardener();
    Salesman* sales=new Salesman();
    InventoryManager* invman=new InventoryManager();
    Inventory::instance().setManager(invman);
    invman->setNext(sales);
    sales->setNext(gard);
    gard->setNext(invman);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    Inventory::instance().supply(rosey);
    Inventory::instance().supply(appley);
    Inventory::instance().supply(dand);
    //Set up the plants in the Nursery.
    
    invman->HireInventoryManager("Alice");
    invman->HireInventoryManager("Mark");
    sales->HireSalesman("Bob");
    sales->HireSalesman("Micheal");
    sales->HireSalesman("Bubbs");
    gard->HireGardener("Charlie");
    gard->HireGardener("Dave");
    gard->HireGardener("Arran");

    if(Inventory::instance().getSalesArea()->space()){
        std::cout << "There is space in the nursery." << std::endl;
    } else {
        std::cout << "The nursery is full." << std::endl;
    }
    std::string input;
    std::cout<<"Welcome to the Nursery Management System!"<<std::endl;
    std::cout<<"Type 'exit' to quit the program."<<std::endl;
    do {
        std::cout << "Type the system you want\nyour options are: \n\t<customer>\n\t<plant>\n\t<game>"<< std::endl;
        std::getline(std::cin, input);
        //std::cout << "Line: " << input << '\n';
        if(input == "customer"|| input=="1" || input=="<customer>"){
            std::cout<<"Customer System Selected."<<std::endl;
            //Demo customer system here
            customerDemo();
        }
        else if(input == "plant"|| input=="2" || input=="<plant>"){
            std::cout<<"Plant System Selected."<<std::endl;
            plantDemo();

        }else if(input == "game"|| input=="3" || input=="<game>"){
            std::cout<<"Game System Selected."<<std::endl;
            //Demo game system here
            GameOn();
        }else if(input != "exit"){
            std::cout<<"That is not a option, please try again."<<std::endl;
        }else{
            std::cout<<"Bye"<<std::endl;
        }
    } while (input != "exit");

    gard->setNext(nullptr);
    delete invman;      
    delete sales;
    delete gard;
    delete rosey;
    delete appley;
    delete dand;
    return 0;
}

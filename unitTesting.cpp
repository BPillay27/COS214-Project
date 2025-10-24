#include "Command.h"
#include "Order.h"
#include "OrderState.h"
#include <iostream>
#include <vector>

int main()
{
    OrderState *a = new AcceptPayment(nullptr);
    OrderState *d = new DeclinePayment(nullptr);
    OrderState *p = new ProcessingPayment(nullptr);
    OrderState *v = new VerifyOrder(nullptr);

    a->handle();
    d->handle();
    p->handle();
    v->handle();

    /*
    //These can be updated and tested once the Composite implementation is done.
    //Order* order=new Order("20251021-01");
    order->processPayment();
    std::vector<AddToOrder*> addCommands;

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
    }
    */
    delete a;
    delete d;
    delete p;
    delete v;
}

#include "nursaryview.h"
#include "ui_nursaryview.h"
#include "Inventory.h"
NursaryView::NursaryView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NursaryView)
{
    ui->setupUi(this);
    init();
}

void NursaryView::passTime()
{
    Inventory & inventory = Inventory::instance();
    inventory.getSalesArea()->advanceTime();
    emit inventoryUpdated("A day has passed in the nursery.");
}

NursaryView::~NursaryView()
{
    delete ui;
}

#include "dashboard.h"
#include "ui_dashboard.h"
//#include "Inventory.h"
Dashboard::Dashboard(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);
    init();
}

Dashboard::~Dashboard()
{
    delete ui;
}

void Dashboard::init()
{
    
}

void Dashboard::on_pushButton_clicked()
{

}


void Dashboard::on_btnPay_clicked()
{

}


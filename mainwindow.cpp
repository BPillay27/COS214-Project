#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "dashboard.h"
#include "nursaryview.h"
#include "simulationview.h"
#include "Inventory.h"
#include "Plant.h"
#include "Employee.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Dashboard* dashboard = new Dashboard();
    dashboard->show();
    
    SimulationView* simulationView = new SimulationView();
    NursaryView* nursaryView = new NursaryView();
    
    connect(nursaryView, &NursaryView::inventoryUpdated,
            simulationView, &SimulationView::updateInventoryDisplay);
    connect(this, &MainWindow::inventoryMessage,
            simulationView, &SimulationView::updateInventoryDisplay);
    connect(simulationView, &SimulationView::nextDay, 
            nursaryView, &NursaryView::passTime);
    connect(this, &MainWindow::employeeMessage,
            simulationView, &SimulationView::updateEmployeeDisplay);
    Employee employee = Employee();
    emit employeeMessage("Employee System Initialized");
    Inventory & inventory = Inventory::instance();
    emit inventoryMessage("Inventory Initialized");
    for (int i = 0; i < 3; ++i) {
        Rose * rose1 = new Rose();
        Rose * rose2 = new Rose();
        Dandelion * dandelion1 = new Dandelion();
        Dandelion * dandelion2 = new Dandelion();
        AppleTree * appleTree1 = new AppleTree();
        AppleTree * appleTree2 = new AppleTree();

        rose1->setCareStrategy(new Kokedama());
        rose2->setCareStrategy(new Espalier());
        dandelion1->setCareStrategy(new Topiary());
        dandelion2->setCareStrategy(new Bonsai());
        appleTree2->setCareStrategy(new Bonsai());
        inventory.supply(rose1);
        inventory.supply(rose2);
        inventory.supply(dandelion1);
        inventory.supply(dandelion2);
        inventory.supply(appleTree1);
        inventory.supply(appleTree2);
    }
    emit inventoryMessage("Initial plant seeds supplied to inventory.");
    emit inventoryMessage(QString::fromStdString(std::to_string(inventory.getStorageCount()) + " plants in storage."));
    inventory.getSalesArea()->examine();
    emit inventoryMessage("Now we wait for them to grow.");


    nursaryView->show();
    simulationView->show();
    
    this->close();
}


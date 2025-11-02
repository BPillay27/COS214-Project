#include "nursaryview.h"
#include "ui_nursaryview.h"
#include "Inventory.h"
#include "Iterator.h"
#include "VectorIterator.h"
#include <QTableWidgetItem>
#include <QHeaderView>
NursaryView::NursaryView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NursaryView)
{
    ui->setupUi(this);
    setupNurseryTable();
    updateNurseryTable();
}

void NursaryView::setupNurseryTable()
{
    ui->tableWidgetNurseryInfo->setColumnCount(6);
    QStringList headers;
    headers << "Plant Name" << "Water Level" << "Fertilise" << "Prune" << "Maturity" << "Condition";
    ui->tableWidgetNurseryInfo->setHorizontalHeaderLabels(headers);
    ui->tableWidgetNurseryInfo->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidgetNurseryInfo->horizontalHeader()->setStretchLastSection(true);
}

void NursaryView::updateNurseryTable()
{
    Inventory & inventory = Inventory::instance();
    Nursery* nursery = inventory.getSalesArea();
    PlantArea* greenhouse = nursery->getGreenHouse();
    
    ui->tableWidgetNurseryInfo->setRowCount(0);
    int currentTableRow = 0;
    
    Iterator<PlantRow*>* rowIterator = greenhouse->createIterator();
    PlantRow* currentRow = rowIterator->first();
    
    while (!rowIterator->isDone()) {
        if (currentRow != nullptr) {
            Iterator<Plant*>* plantIterator = currentRow->createIterator();
            Plant* currentPlant = plantIterator->first();
            
            while (!plantIterator->isDone()) {
                if (currentPlant != nullptr) {
                    bool canSell = currentPlant->canSale();
                    addPlantToTable(currentTableRow, currentPlant, canSell, canSell);
                    currentTableRow++;
                }
                currentPlant = plantIterator->next();
            }
            delete plantIterator;
        }
        currentRow = rowIterator->next();
    }
    delete rowIterator;
}

void NursaryView::passTime()
{
    Inventory & inventory = Inventory::instance();
    
    Nursery* nursery = inventory.getSalesArea();
    PlantArea* greenhouse = nursery->getGreenHouse();
    
    ui->tableWidgetNurseryInfo->setRowCount(0);
    int currentTableRow = 0;
    
    Iterator<PlantRow*>* rowIterator = greenhouse->createIterator();
    
    PlantRow* currentRow = rowIterator->first();
    
    while (!rowIterator->isDone()) {
        if (currentRow != nullptr) {
            std::string rowType = currentRow->typePlant();
            int numPlantsInRow = currentRow->getNumPlants();

            QString rowInfo = QString("Processing row with %1 plants of type: %2")
                             .arg(numPlantsInRow)
                             .arg(QString::fromStdString(rowType));
            emit inventoryUpdated(rowInfo);
            
            Iterator<Plant*>* plantIterator = currentRow->createIterator();
            Plant* currentPlant = plantIterator->first();
        
            while (!plantIterator->isDone()) {
                if (currentPlant != nullptr) {
                    std::string species = currentPlant->getSpecies();
                    std::string details = currentPlant->getDetails();
                    bool canSell = currentPlant->canSale();
    
                    currentPlant->grow();
                    
                    std::string detailsAfter = currentPlant->getDetails();
                    bool canSellAfter = currentPlant->canSale();
                    
                    currentPlant->examine(true);
                    
                    addPlantToTable(currentTableRow, currentPlant, canSell, canSellAfter);
                    currentTableRow++;
                    
                    QString plantInfo = QString("Plant: %1, Was ready for sale: %2, Now ready: %3")
                                       .arg(QString::fromStdString(species))
                                       .arg(canSell ? "Yes" : "No")
                                       .arg(canSellAfter ? "Yes" : "No");
                    
                    emit inventoryUpdated(plantInfo);
                }
                currentPlant = plantIterator->next();
            }
            
            delete plantIterator;
        }
        currentRow = rowIterator->next();
    }
    
    delete rowIterator;
    
    nursery->grow();
    nursery->examine();
    
    int totalPlantsInGreenhouse = greenhouse->getCount();
    int greenhouseCapacity = greenhouse->getCapacity();
    
    QString summary = QString("Day complete! Greenhouse has %1/%2 plants. All plants processed with iterators!")
                     .arg(totalPlantsInGreenhouse)
                     .arg(greenhouseCapacity);
    
    emit inventoryUpdated(summary);
    
    updateNurseryTable();
}

void NursaryView::addPlantToTable(int row, Plant* plant, bool canSellBefore, bool canSellAfter)
{
    ui->tableWidgetNurseryInfo->insertRow(row);
    
    QString species = QString::fromStdString(plant->getSpecies());
    QString details = QString::fromStdString(plant->getDetails());
    QString waterLevel = QString("%1 (Nutrition: %2)")
                        .arg(plant->getWaterLevel())
                        .arg(plant->getSoilNutrition());
    QString fertilise = plant->toFertilise() ? "Needed" : "Good";
    QString prune = plant->toPrune() ? "Needed" : "Good";
    QString maturity = plant->getMaturity() ? QString::fromStdString(plant->getMaturity()->lifeCycle()) : "Unknown";
    QString condition = plant->getCondition() ? QString::fromStdString(plant->getCondition()->getConditionString()) : "Unknown";
    
    ui->tableWidgetNurseryInfo->setItem(row, 0, new QTableWidgetItem(species));
    ui->tableWidgetNurseryInfo->setItem(row, 1, new QTableWidgetItem(waterLevel));
    ui->tableWidgetNurseryInfo->setItem(row, 2, new QTableWidgetItem(fertilise));
    ui->tableWidgetNurseryInfo->setItem(row, 3, new QTableWidgetItem(prune));
    ui->tableWidgetNurseryInfo->setItem(row, 4, new QTableWidgetItem(maturity));
    ui->tableWidgetNurseryInfo->setItem(row, 5, new QTableWidgetItem(condition));
    
    QColor rowColor;
    if (canSellAfter) {
        rowColor = QColor(144, 238, 144); 
    } else {
        rowColor = QColor(255, 255, 224); 
    }
    
    for (int col = 0; col < 6; col++) {
        QTableWidgetItem* item = ui->tableWidgetNurseryInfo->item(row, col);
        item->setBackground(rowColor);
        item->setForeground(QColor(0, 0, 0)); 
    }
}

NursaryView::~NursaryView()
{
    delete ui;
}

#include "simulationview.h"
#include "ui_simulationview.h"

SimulationView::SimulationView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SimulationView)
{
    ui->setupUi(this);
}

SimulationView::~SimulationView()
{
    delete ui;
}

void SimulationView::updateInventoryDisplay(const QString& message)
{
    ui->textBrowserInventorySystem->append(message);
}

void SimulationView::on_btnNextDay_clicked()
{
    emit nextDay();
}


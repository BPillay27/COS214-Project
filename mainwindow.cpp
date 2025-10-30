#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dashboard.h"

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

void MainWindow::on_startButton_clicked()
{
    // Option 2: Create new window and hide current window
    Dashboard* dashboardWindow = new Dashboard();
    dashboardWindow->show();
    this->hide(); // Hide the main window
}


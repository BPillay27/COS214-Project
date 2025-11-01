#include "nursaryview.h"
#include "ui_nursaryview.h"

NursaryView::NursaryView(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NursaryView)
{
    ui->setupUi(this);
}

NursaryView::~NursaryView()
{
    delete ui;
}

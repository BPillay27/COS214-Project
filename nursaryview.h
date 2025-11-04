#ifndef NURSARYVIEW_H
#define NURSARYVIEW_H

#include <QWidget>
#include "Plant.h"
namespace Ui {
class NursaryView;
}

class NursaryView : public QWidget
{
    Q_OBJECT

public:
    explicit NursaryView(QWidget *parent = nullptr);
    ~NursaryView();
public slots:
    void passTime();
signals:
    void inventoryUpdated(const QString& message);

private:
    void setupNurseryTable();
    void updateNurseryTable();
    void addPlantToTable(int row, Plant* plant, bool canSellBefore, bool canSellAfter);

private:
    Ui::NursaryView *ui;
};

#endif // NURSARYVIEW_H

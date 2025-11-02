#ifndef SIMULATIONVIEW_H
#define SIMULATIONVIEW_H

#include <QWidget>

namespace Ui {
class SimulationView;
}

class SimulationView : public QWidget
{
    Q_OBJECT

public:
    explicit SimulationView(QWidget *parent = nullptr);
    ~SimulationView();

public slots:
    // Slot to receive inventory updates from NursaryView
    void updateInventoryDisplay(const QString& message);

private slots:
    void on_btnNextDay_clicked();
signals:
    void nextDay();
private:
    Ui::SimulationView *ui;
};

#endif // SIMULATIONVIEW_H

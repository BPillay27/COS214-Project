#ifndef DASHBOARD_H
#define DASHBOARD_H

#include <QWidget>

namespace Ui {
class Dashboard;
}

class Dashboard : public QWidget
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr);
    ~Dashboard();

private slots:
    void on_pushButton_clicked();

    void on_btnPay_clicked();

    void on_btnAddItemCol_1_clicked();

    void on_btnAddItemCol_2_clicked();

    void on_btnAddItemCol_3_clicked();

    void on_btnAddItemCol_4_clicked();

    void on_btnAddItemCol_5_clicked();

    void on_btnDetailsCol_1_clicked();

    void on_btnDetailsCol_2_clicked();

    void on_btnDetailsCol_3_clicked();

    void on_btnDetailsCol_4_clicked();

    void on_btnDetailsCol_5_clicked();

    void on_btnPrevRow_clicked();

    void on_btnNextRow_clicked();

private:
    Ui::Dashboard *ui;
    void init();
};

#endif // DASHBOARD_H

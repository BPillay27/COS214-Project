#ifndef NURSARYVIEW_H
#define NURSARYVIEW_H

#include <QWidget>

namespace Ui {
class NursaryView;
}

class NursaryView : public QWidget
{
    Q_OBJECT

public:
    explicit NursaryView(QWidget *parent = nullptr);
    ~NursaryView();

private:
    Ui::NursaryView *ui;
};

#endif // NURSARYVIEW_H

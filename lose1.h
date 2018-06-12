#ifndef LOSE1_H
#define LOSE1_H

#include <QDialog>

namespace Ui {
class Lose1;
}

class Lose1 : public QDialog
{
    Q_OBJECT

public:
    explicit Lose1(QWidget *parent = 0);
    ~Lose1();

private:
    Ui::Lose1 *ui;
};

#endif // LOSE1_H

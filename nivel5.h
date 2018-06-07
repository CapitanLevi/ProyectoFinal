#ifndef NIVEL5_H
#define NIVEL5_H

#include <QDialog>

namespace Ui {
class Nivel5;
}

class Nivel5 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel5(QWidget *parent = 0);
    ~Nivel5();

private:
    Ui::Nivel5 *ui;
};

#endif // NIVEL5_H

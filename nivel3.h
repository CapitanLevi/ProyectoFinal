#ifndef NIVEL3_H
#define NIVEL3_H

#include <QDialog>

namespace Ui {
class Nivel3;
}

class Nivel3 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel3(QWidget *parent = 0);
    ~Nivel3();

private:
    Ui::Nivel3 *ui;
};

#endif // NIVEL3_H

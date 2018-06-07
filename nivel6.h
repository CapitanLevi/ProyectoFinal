#ifndef NIVEL6_H
#define NIVEL6_H

#include <QDialog>

namespace Ui {
class Nivel6;
}

class Nivel6 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel6(QWidget *parent = 0);
    ~Nivel6();

private:
    Ui::Nivel6 *ui;
};

#endif // NIVEL6_H

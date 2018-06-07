#ifndef NIVEL2_H
#define NIVEL2_H

#include <QDialog>

namespace Ui {
class Nivel2;
}

class Nivel2 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = 0);
    ~Nivel2();

private:
    Ui::Nivel2 *ui;
};

#endif // NIVEL2_H

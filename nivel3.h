#ifndef NIVEL3_H
#define NIVEL3_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class Nivel3;
}

class Nivel3 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel3(QWidget *parent = 0);
    ~Nivel3();
    QMovie *movie;
private:
    Ui::Nivel3 *ui;
};

#endif // NIVEL3_H

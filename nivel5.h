#ifndef NIVEL5_H
#define NIVEL5_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class Nivel5;
}

class Nivel5 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel5(QWidget *parent = 0);
    ~Nivel5();
    QMovie *movie;
private:
    Ui::Nivel5 *ui;
};

#endif // NIVEL5_H

#ifndef NIVEL2_H
#define NIVEL2_H

#include <QDialog>
#include <QMovie>

namespace Ui {
class Nivel2;
}

class Nivel2 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = 0);
    ~Nivel2();
    QMovie *movie;
private:
    Ui::Nivel2 *ui;
};

#endif // NIVEL2_H

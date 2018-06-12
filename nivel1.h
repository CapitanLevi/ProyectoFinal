#ifndef NIVEL1_H
#define NIVEL1_H

//#include <QMediaPlayer>
#include <QDialog>
#include <QMovie>
#include "win1.h"

namespace Ui {
class Nivel1;
}

class Nivel1 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel1(QWidget *parent = 0);
    ~Nivel1();
//    QMediaPlayer * music1;
    QMovie *movie;
    int tamletra = 25;
    Win1 *win1 = new Win1();
private slots:
    void cerrar();
    void on_win1_clicked();

private:
    Ui::Nivel1 *ui;
};

#endif // NIVEL1_H

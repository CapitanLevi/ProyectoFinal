#ifndef LISTANIVELES_H
#define LISTANIVELES_H

#include <QDialog>
#include "menuprincipal.h"
//#include "nivel1.h"
//#include "nivel2.h"
//#include "nivel3.h"
//#include "nivel4.h"
//#include "nivel5.h"
//#include "nivel6.h"

namespace Ui {
class ListaNiveles;
}

class ListaNiveles : public QDialog
{
    Q_OBJECT

public:
    explicit ListaNiveles(QWidget *parent = 0);
    ~ListaNiveles();

private slots:
    void on_nivel_clicked();

    void on_nivel_2_clicked();

    void on_nivel_3_clicked();

    void on_nivel_4_clicked();

    void on_nivel_5_clicked();

    void on_nivel_6_clicked();

    void on_nivel_7_clicked();

private:
    Ui::ListaNiveles *ui;
    MenuPrincipal *m;
//    Nivel1 *nivel1;
//    Nivel2 *nivel2;
//    Nivel3 *nivel3;
//    Nivel4 *nivel4;
//    Nivel5 *nivel5;
//    Nivel6 *nivel6;
};

#endif // LISTANIVELES_H

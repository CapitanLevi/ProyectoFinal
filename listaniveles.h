#ifndef LISTANIVELES_H
#define LISTANIVELES_H

#include <QDialog>
#include "menuprincipal.h"
#include "nivel1.h"2
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

    Nivel1 nivel1;
//    Nivel1 *nivel1;
//    Nivel2 *nivel2;
//    Nivel3 *nivel3;
//    Nivel4 *nivel4;
//    Nivel5 *nivel5;
//    Nivel6 *nivel6;
private slots:
    void on_nivel1_clicked();
    void on_nivel2_clicked();
    void on_nivel3_clicked();
    void on_nivel4_clicked();
    void on_nivel5_clicked();
    void on_nivel6_clicked();
    void on_quit_clicked();

private:
    Ui::ListaNiveles *ui;
    MenuPrincipal *m;

};

#endif // LISTANIVELES_H

#include "listaniveles.h"
#include "ui_listaniveles.h"
#include "menuprincipal.h"
#include "win1.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "nivel4.h"
#include "nivel5.h"
#include "nivel6.h"
#include "ui_nivel1.h"
extern MenuPrincipal *w;
//extern Win1 *win1;

ListaNiveles::ListaNiveles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaNiveles)
{
    ui->setupUi(this);

    // connect the win1's clicked signal with the executor of level 2
//    connect(,SIGNAL(clicked()),this,SLOT(on_nivel2_clicked()));

}

ListaNiveles::~ListaNiveles()
{
    delete ui;
}


void ListaNiveles::on_nivel1_clicked()
{
//    w->MenuPrincipal::~MenuPrincipal();
    nivel1.setModal(true);
    nivel1.exec();
}

void ListaNiveles::on_nivel2_clicked()
{
//    w->MenuPrincipal::~MenuPrincipal();
    Nivel2 nivel2;
    nivel2.setModal(true);
    nivel2.exec();
}

void ListaNiveles::on_nivel3_clicked()
{
//    w->MenuPrincipal::~MenuPrincipal();
    Nivel3 nivel3;
    nivel3.setModal(true);
    nivel3.exec();
}

void ListaNiveles::on_nivel4_clicked()
{
//    w->MenuPrincipal::~MenuPrincipal();
    Nivel4 nivel4;
    nivel4.setModal(true);
    nivel4.exec();
}

void ListaNiveles::on_nivel5_clicked()
{
//    w->MenuPrincipal::~MenuPrincipal();
    Nivel5 nivel5;
    nivel5.setModal(true);
    nivel5.exec();
}

void ListaNiveles::on_nivel6_clicked()
{
//    w->MenuPrincipal::~MenuPrincipal();
    Nivel6 nivel6;
    nivel6.setModal(true);
    nivel6.exec();
}

void ListaNiveles::on_quit_clicked()
{
    this->close();
//    w = new MenuPrincipal();
//    w->show();
}

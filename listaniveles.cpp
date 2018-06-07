#include "listaniveles.h"
#include "ui_listaniveles.h"
#include "menuprincipal.h"
#include "nivel1.h"
#include "nivel2.h"
#include "nivel3.h"
#include "nivel4.h"
#include "nivel5.h"
#include "nivel6.h"
extern MenuPrincipal *w;

ListaNiveles::ListaNiveles(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaNiveles)
{
    ui->setupUi(this);
}

ListaNiveles::~ListaNiveles()
{
    delete ui;
}


void ListaNiveles::on_nivel_clicked()
{
    w->music->stop();
    w->MenuPrincipal::~MenuPrincipal();
    Nivel1 nivel1;
    nivel1.setModal(true);
    nivel1.exec();
}

void ListaNiveles::on_nivel_2_clicked()
{
    w->music->stop();
    w->MenuPrincipal::~MenuPrincipal();
    Nivel2 nivel2;
    nivel2.setModal(true);
    nivel2.exec();
}

void ListaNiveles::on_nivel_3_clicked()
{
    w->music->stop();
    w->MenuPrincipal::~MenuPrincipal();
    Nivel3 nivel3;
    nivel3.setModal(true);
    nivel3.exec();
}

void ListaNiveles::on_nivel_4_clicked()
{
    w->music->stop();
    w->MenuPrincipal::~MenuPrincipal();
    Nivel4 nivel4;
    nivel4.setModal(true);
    nivel4.exec();
}

void ListaNiveles::on_nivel_5_clicked()
{
    w->music->stop();
    w->MenuPrincipal::~MenuPrincipal();
    Nivel5 nivel5;
    nivel5.setModal(true);
    nivel5.exec();
}

void ListaNiveles::on_nivel_6_clicked()
{
    w->music->stop();
    w->MenuPrincipal::~MenuPrincipal();
    Nivel6 nivel6;
    nivel6.setModal(true);
    nivel6.exec();
}

void ListaNiveles::on_nivel_7_clicked()
{
    this->close();
    w = new MenuPrincipal();
    w->show();
}

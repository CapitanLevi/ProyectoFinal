#include "load.h"
#include "ui_load.h"
#include "nivel2.h"
#include "nivel3.h"
#include "nivel4.h"
#include "nivel5.h"
#include "nivel6.h"

Load::Load(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Load)
{
    ui->setupUi(this);
    QString clave;
    clave = ui->clave->text();
}

Load::~Load()
{
    delete ui;
}


void Load::on_clave_returnPressed()
{
    QString clave;
    clave = ui->clave->text();
    if(clave==QString("QRST")){
        Nivel2 nivel2;
        nivel2.setModal(true);
        nivel2.exec();
    }
    else if(clave==QString("ERST")){
        Nivel3 nivel3;
        nivel3.setModal(true);
        nivel3.exec();
    }
    else if(clave==QString("ARST")){
        Nivel4 nivel4;
        nivel4.setModal(true);
        nivel4.exec();
    }
    else if(clave==QString("DRST")){
        Nivel5 nivel5;
        nivel5.setModal(true);
        nivel5.exec();
    }
    else if(clave==QString("FRST")){
        Nivel6 nivel6;
        nivel6.setModal(true);
        nivel6.exec();
    }
    this->close();
}

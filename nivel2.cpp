#include "nivel2.h"
#include "ui_nivel2.h"

Nivel2::Nivel2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
}

Nivel2::~Nivel2()
{
    delete ui;
}

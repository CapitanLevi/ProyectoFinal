#include "nivel4.h"
#include "ui_nivel4.h"

Nivel4::Nivel4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel4)
{
    ui->setupUi(this);
}

Nivel4::~Nivel4()
{
    delete ui;
}

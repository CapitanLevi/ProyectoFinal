#include "nivel6.h"
#include "ui_nivel6.h"

Nivel6::Nivel6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel6)
{
    ui->setupUi(this);
}

Nivel6::~Nivel6()
{
    delete ui;
}

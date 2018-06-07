#include "nivel5.h"
#include "ui_nivel5.h"

Nivel5::Nivel5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel5)
{
    ui->setupUi(this);
}

Nivel5::~Nivel5()
{
    delete ui;
}

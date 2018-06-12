#include "lose1.h"
#include "ui_lose1.h"

Lose1::Lose1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Lose1)
{
    ui->setupUi(this);
}

Lose1::~Lose1()
{
    delete ui;
}

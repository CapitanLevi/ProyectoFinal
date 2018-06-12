#include "win1.h"
#include "ui_win1.h"
#include "nivel1.h"
#include "menuprincipal.h"

Win1::Win1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Win1)
{
    ui->setupUi(this);
}

Win1::~Win1()
{
    delete ui;
}

void Win1::on_ok_clicked()
{
    emit clicked();
    //this->~Win1();

    //Nivel1::destroy();
}

#include "ganadorm2.h"
#include "ui_ganadorm2.h"

GanadorM2::GanadorM2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GanadorM2)
{
    ui->setupUi(this);
    // set title's typography
    QFont audiowide = QFont("Audiowide",11,1);
    ui->label->setFont(audiowide);
}

GanadorM2::~GanadorM2()
{
    delete ui;
}

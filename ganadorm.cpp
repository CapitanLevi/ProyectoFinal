#include "ganadorm.h"
#include "ui_ganadorm.h"

GanadorM::GanadorM(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GanadorM)
{
    ui->setupUi(this);
    // set title's typography
    QFont audiowide = QFont("Audiowide",11,1);
    ui->label->setFont(audiowide);
}

GanadorM::~GanadorM()
{
    delete ui;
}

#include "nivel4.h"
#include "ui_nivel4.h"

Nivel4::Nivel4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel4)
{
    ui->setupUi(this);
    movie = new QMovie(":/gifs/gifs/bg4.gif");
    ui->bg4->setMovie(movie);
    movie->start();
}

Nivel4::~Nivel4()
{
    delete ui;
}

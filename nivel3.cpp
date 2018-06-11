#include "nivel3.h"
#include "ui_nivel3.h"

Nivel3::Nivel3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel3)
{
    ui->setupUi(this);
    movie = new QMovie(":/gifs/gifs/bg3.gif");
    ui->bg3->setMovie(movie);
    movie->start();
}

Nivel3::~Nivel3()
{
    delete ui;
}

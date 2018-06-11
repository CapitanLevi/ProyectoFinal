#include "nivel2.h"
#include "ui_nivel2.h"

Nivel2::Nivel2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
    movie = new QMovie(":/gifs/gifs/bg2.gif");
    ui->bg2->setMovie(movie);
    movie->start();
}

Nivel2::~Nivel2()
{
    delete ui;
}

#include "nivel5.h"
#include "ui_nivel5.h"

Nivel5::Nivel5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel5)
{
    ui->setupUi(this);
    movie = new QMovie(":/gifs/gifs/bg5.gif");
    ui->bg5->setMovie(movie);
    movie->start();
}

Nivel5::~Nivel5()
{
    delete ui;
}

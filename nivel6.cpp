#include "nivel6.h"
#include "ui_nivel6.h"

Nivel6::Nivel6(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel6)
{
    ui->setupUi(this);
    movie = new QMovie(":/gifs/gifs/bg6.gif");
    ui->bg6->setMovie(movie);
    movie->start();
}

Nivel6::~Nivel6()
{
    delete ui;
}

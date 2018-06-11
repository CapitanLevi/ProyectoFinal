#include "nivel1.h"
#include "ui_nivel1.h"

Nivel1::Nivel1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel1)
{
    ui->setupUi(this);
//    music1 = new QMediaPlayer();
//    music1->setMedia(QUrl("qrc:/audio/Good Starts.mp3"));
//    music1->play();
    movie = new QMovie(":/gifs/gifs/bg1.gif");
    ui->bg1->setMovie(movie);
    movie->start();
}

Nivel1::~Nivel1()
{
    delete ui;
}

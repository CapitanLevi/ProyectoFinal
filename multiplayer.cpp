#include "multiplayer.h"
#include "ui_multiplayer.h"
#include "menuprincipal.h"

extern MenuPrincipal *w;

Multiplayer::Multiplayer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Multiplayer)
{
//    w->music->stop();
//    w->MenuPrincipal::~MenuPrincipal();
    ui->setupUi(this);
//    musicm = new QMediaPlayer();
//    musicm->setMedia(QUrl("qrc:/audio/Dust in the wind.mp3"));
//    musicm->play();
    movie = new QMovie(":/gifs/gifs/bgm.gif");
    ui->bgm->setMovie(movie);
    movie->start();
}

Multiplayer::~Multiplayer()
{
    delete ui;
}

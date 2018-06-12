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
    // set background gif
    moviem = new QMovie(":/gifs/gifs/bgm.gif");
    ui->bgm->setMovie(moviem);
    moviem->start();
}

Multiplayer::~Multiplayer()
{
    delete ui;
}

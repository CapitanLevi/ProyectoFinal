#include "menuprincipal.h"
#include "ui_menuprincipal.h"
#include "about.h"
#include "listaniveles.h"
#include "multiplayer.h"

MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/audio/Never Gonna Give You Up 8 Bit Remix.mp3"));
    music->play();
}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}

void MenuPrincipal::on_singleplayer_clicked()
{
    ListaNiveles lista;
    lista.setModal(true);
    lista.exec();
}

void MenuPrincipal::on_about_clicked()
{
    About about;
    about.setModal(true);
    about.exec();
}

void MenuPrincipal::on_multiplayer_clicked()
{
    //this->close();
    Multiplayer m;
    m.setModal(true);
    m.exec();
}

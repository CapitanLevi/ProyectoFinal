#include "menuprincipal.h"
#include "ui_menuprincipal.h"
#include "about.h"
#include "listaniveles.h"
#include "multiplayer.h"
#include <QFont>
#include <QFontDatabase>

MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);
    // set music
    music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/audios/audios/Good Starts.mp3"));
    music->play();
    // set typography
    //QFontDatabase::addApplicationFont(":/fonts/fonts/Cassandra Personal Use.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Sweet Sensations Personal Use.ttf");
    //QFont Cassi = QFont("Cassandra Personal Use",tamletra,1);
    QFont Sweet = QFont("Sweet Sensations Personal Use",tamletra,1);

    ui->singleplayer->setFont(Sweet);
    ui->multiplayer->setFont(Sweet);
    ui->about->setFont(Sweet);
    ui->load->setFont(Sweet);
    ui->title->setFont(Sweet);
}

MenuPrincipal::~MenuPrincipal()
{
//    w->music->stop();
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


#include "menuprincipal.h"
#include "ui_menuprincipal.h"
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
    // set background gif
    movie = new QMovie(":/gifs/gifs/menu.gif");
    ui->fondo->setMovie(movie);
    movie->start();
    // set typography
//    QFontDatabase::addApplicationFont(":/fonts/fonts/Cassandra Personal Use.ttf");
//    QFontDatabase::addApplicationFont(":/fonts/fonts/Sweet Sensations Personal Use.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Audiowide-Regular.ttf");
    QFontDatabase::addApplicationFont(":/fonts/fonts/Monofett.ttf");
    QFont audiowide = QFont("Audiowide",tamletra,1);
    QFont monofett = QFont("Monofett",tamletra+5,1);
    ui->singleplayer->setFont(audiowide);
    ui->multiplayer->setFont(audiowide);
    ui->about->setFont(audiowide);
    ui->load->setFont(audiowide);
    ui->quit->setFont(audiowide);
    ui->title->setFont(monofett);
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
    about = new About();
    about->setModal(true);
    about->exec();
}

void MenuPrincipal::on_multiplayer_clicked()
{
    //this->close();
    Multiplayer m;
    m.setModal(true);
    m.exec();
}


void MenuPrincipal::on_quit_clicked()
{
    this->close();
}

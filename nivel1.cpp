#include "nivel1.h"
#include "ui_nivel1.h"
#include "win1.h"
//#include <QFontDatabase>

Nivel1::Nivel1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel1)
{
    ui->setupUi(this);
    // set music
//    music1 = new QMediaPlayer();
//    music1->setMedia(QUrl("qrc:/audio/Good Starts.mp3"));
//    music1->play();

    // set background gif
    movie = new QMovie(":/gifs/gifs/bg1.gif");
    ui->bg1->setMovie(movie);
    movie->start();

    // set title's typography
//    QFontDatabase::addApplicationFont(":/fonts/fonts/AirbagFree-Regular.ttf");
//    QFont titlefont = QFont("AirbagFree",tamletra,1);
//    ui->title->setFont(titlefont);

    // connect the win1's clicked signal with the destructor of this window
    connect(win1,SIGNAL(clicked()),this,SLOT(cerrar()));
}


Nivel1::~Nivel1()
{
    delete ui;
}

void Nivel1::cerrar()
{
    this->close();
}

void Nivel1::on_win1_clicked()
{
    win1->exec();
}

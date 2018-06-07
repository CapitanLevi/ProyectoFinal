#include "nivel1.h"
#include "ui_nivel1.h"

Nivel1::Nivel1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel1)
{
    ui->setupUi(this);
    music1 = new QMediaPlayer();
    music1->setMedia(QUrl("qrc:/audio/Good Starts.mp3"));
    music1->play();
}

Nivel1::~Nivel1()
{
    delete ui;
}

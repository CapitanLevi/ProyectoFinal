#include "nivel2.h"
#include "ui_nivel2.h"
#include "win1.h"
#include "listaniveles.h"
#include "menuprincipal.h"
//extern MenuPrincipal *w;

Nivel2::Nivel2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Nivel2)
{
    ui->setupUi(this);
    // set background gif
    movie = new QMovie(":/gifs/gifs/bg2.gif");
    ui->bg2->setMovie(movie);
    movie->start();
    // connect the win1's clicked signal with the executor of level 2
//    connect(win1,SIGNAL(clicked()),w,SLOT(on_nivel2_clicked()));
}

Nivel2::~Nivel2()
{
    delete ui;
}

#ifndef NIVEL1_H
#define NIVEL1_H

//#include <QMediaPlayer>
#include <QDialog>
#include <QMovie>
#include "win1.h"
// backend
#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>
#include "Backend/esferagraf.h"
#include "Backend/esferagraf.h"
#include "Backend/esferasimmovcirgraf.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

namespace Ui {
class Nivel1;
}

class Nivel1 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel1(QWidget *parent = 0);
    ~Nivel1();
//    QMediaPlayer * music1;
    QMovie *movie;
    int tamletra = 25;
    Win1 *win1 = new Win1();
private slots:
    void cerrar();
    // backend
    void actualizar();
private:
    Ui::Nivel1 *ui;
    // ************** backend *************** //
    QTimer *timer;              //timer para los intervalos de tiempo entre cada frame
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    QGraphicsRectItem *rectangle;
    QList<QGraphicsRectItem *> rectangles;
    float dt;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    void bordercollision(EsferaSim *b);   //metodo para las colisiones con los bordes del mundo

    QList<EsferaGraf*> bars;
    EsferaGraf *parabolico;
    QList<esferasimmovcirgraf*> bars2;
    float e;
    float tiros=0;
    int Ganador=0;
    QPainter *obstaculo1;


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool Pressed=false;
    // ************** backend *************** //
};

#endif // NIVEL1_H

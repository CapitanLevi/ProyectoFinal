#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

//#include <QMediaPlayer>
#include <QDialog>
#include <QMovie>

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>
#include "Backend/esferasim.h"
#include "Backend/esferagraf.h"
#include "Backend/esferasimmovcirgraf.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

namespace Ui {
class Multiplayer;
}

class Multiplayer : public QDialog
{
    Q_OBJECT

public:
    explicit Multiplayer(QWidget *parent = 0);
    ~Multiplayer();
//    QMediaPlayer * musicm;
    QMovie *moviem;
    int tamletra=25;

    int bandera=0;
    int numero_obstaculos=4;
    int contador=0;
    int banderacontador=0;
private slots:
    void actualizar();
private:
    Ui::Multiplayer *ui;
    // BACK END //
    QTimer *timer;              //timer para los intervalos de tiempo entre cada frame
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    QGraphicsRectItem *rectangle;
    QList<QGraphicsRectItem *> rectangles;
    float dt;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    void bordercollision(EsferaSim *b);   //metodo para las colisiones con los bordes del mundo
    //QPainter *painter;

    QList<EsferaGraf*> bars;
    QList<EsferaGraf*> barsesfera2;
    EsferaGraf *parabolico;
    esferasimmovcirgraf *esfera2;
    QList<esferasimmovcirgraf*> bars2;
    float e;
    float tiros=0;
    int tiros1=0;
    int Ganador=0;
    QPainter *obstaculo1;


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool Pressed=false;
    int turno=0;
    bool Pressed1=false;
};

#endif // MULTIPLAYER_H

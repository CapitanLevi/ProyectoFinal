#ifndef NIVEL2_H
#define NIVEL2_H

#include <QDialog>
#include <QMovie>
#include "win1.h"
#include "ui_nivel1.h"
#include "nivel1.h"
#include "listaniveles.h"
#include "menuprincipal.h"

// *********** back end ************** //
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
// *********** back end ************** //

namespace Ui {
class Nivel2;
}

class Nivel2 : public QDialog
{
    Q_OBJECT

public:
    explicit Nivel2(QWidget *parent = 0);
    ~Nivel2();
    QMovie *movie;
    Win1 *win1;
    int tamletra=25;

    int bandera=0;
    int numero_obstaculos=4;
    int contador=0;
    int banderacontador=0;
private slots:
    void actualizar();
private:
    Ui::Nivel2 *ui;
    // *********** back end ************** //
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
    // *********** back end ************** //
};

#endif // NIVEL2_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QPixmap>
#include <QTimer>
#include <QFile>
#include <QKeyEvent>
#include "esferasim.h"
#include "esferagraf.h"
#include "esferasimmovcirgraf.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void actualizar();

    void on_start_clicked();

    void on_add_clicked();

    void on_stop_clicked();



private:
    Ui::MainWindow *ui;
    QTimer *timer;              //timer para los intervalos de tiempo entre cada frame
    QGraphicsScene *scene;      //scene que muestra los objetos animados
    QGraphicsRectItem *rectangle;
    float dt;                   //intervalo de tiempo entre frames
    int h_limit;                //longitud en X del mundo
    int v_limit;                //longitud en Y del mundo
    void bordercollision(EsferaSim *b);   //metodo para las colisiones con los bordes del mundo
    void colision(EsferaGraf *b, EsferaGraf *c);
    QList<EsferaGraf*> bars;
    EsferaGraf *parabolico;
    QList<esferasimmovcirgraf*> bars2;
    float e;

    QPainter *obstaculo1;


    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool Pressed=false;
};

#endif // MAINWINDOW_H

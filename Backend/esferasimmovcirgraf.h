#ifndef ESFERASIMMOVCIRGRAF_H
#define ESFERASIMMOVCIRGRAF_H
#include "esferasimmovcir.h"

#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsScene>

class esferasimmovcirgraf: public QGraphicsItem
{
public:
    esferasimmovcirgraf(float m, float _a, float _b, float _radio,
                        float _radiotrayectoria, float w0, float _alpha, float v_limit);
    ~esferasimmovcirgraf();
    QRectF boundingRect() const;    //necesario definirla, devuelve el rectangulo que encierra el objeto
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); //define como se pintara el objeto
    void setEscala(float s);
    void actualizar(float dt, float v_lim);

    esferasimmovcir * getesfera();
private:
    float escala;
    esferasimmovcir *esf;
};

#endif // ESFERASIMMOVCIRGRAF_H

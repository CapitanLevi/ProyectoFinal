#include "esferasimmovcirgraf.h"

esferasimmovcirgraf::esferasimmovcirgraf(float m, float _a, float _b, float _radio,
                                         float _radiotrayectoria, float w0,
                                         float _alpha, float v_limit):escala(1)
{
    esf=new esferasimmovcir(m,_a,_b,_radio,_radiotrayectoria,w0,_alpha);
    setPos(esf->getX()*escala,(v_limit-esf->getY())*escala);

    //    setPos(esf->getX()*escala,(v_lim-esf->getY())*escala);

}

esferasimmovcirgraf::~esferasimmovcirgraf()
{
    delete esf;
}

QRectF esferasimmovcirgraf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());

}

void esferasimmovcirgraf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::darkYellow);        //asigna el color
    painter->drawEllipse(boundingRect());    //dibuja una elipse encerrada en la boundingRect

}

void esferasimmovcirgraf::setEscala(float s)
{
    escala=s;
}

void esferasimmovcirgraf::actualizar(float dt, float v_lim)
{
    esf->actualizar(dt);
    setPos(esf->getX()*escala,(v_lim-esf->getY())*escala);
}

esferasimmovcir *esferasimmovcirgraf::getesfera()
{
    return esf;
}

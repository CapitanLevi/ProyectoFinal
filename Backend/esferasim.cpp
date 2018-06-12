#include "esferasim.h"
#include <QDebug>

EsferaSim::EsferaSim(float x, float y, float r, float m):px(x),py(y),radio(r),vx(0),vy(0),masa(m)
{

}

EsferaSim::~EsferaSim()
{

}

void EsferaSim::setVel(float x, float y)
{
    vx=x;
    vy=y;
}

void EsferaSim::setPoint(float x, float y)
{
    px=x;
    py=y;
    vx=0;
    vy=0;
}



void EsferaSim::actualizar(float dt)
{
    aceleracion(dt);
    vx=vx+ax*dt;
    vy=vy+ay*dt;
    px+=vx*dt;
    py+=vy*dt;
}

void EsferaSim::aceleracion(float dt)
{
    ax=0;
    ay=-10;
//    float angulo=0,vt=0;          ESTO JODE EL PROGRAMA. NO SÉ PORQUE
//    angulo=atan2(vy,vx);
//    vt=sqrt(pow(vx,2)+pow(vy,2));
//    ax=((-pow(vt,2)*pow(radio,2))/masa)*cos(angulo);
//    ay=((-pow(vt,2)*pow(radio,2))/masa)*sin(angulo)*(10);
}

float EsferaSim::getX() const
{
    return px;
}

float EsferaSim::getY() const
{
    return py;
}

float EsferaSim::getR() const
{
    return radio;
}

float EsferaSim::getVx() const
{
    return vx;
}

float EsferaSim::getVy() const
{
    return vy;
}




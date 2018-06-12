#include "esferasimmovcir.h"
#include "QDebug"
esferasimmovcir::esferasimmovcir(float m, float _a, float _b, float _radio,
                                 float _radiotrayectoria, float w0, float _alpha)
{
    qDebug()<<"AL inicio"<<endl;
    masa=m;
    radiotrayectoria=_radiotrayectoria;
    radio=_radio;
    a=_a;
    b=_b;
    x=a+radiotrayectoria;
    y=b;
    theta=0;
    omega=w0;
    qDebug()<<"omega es: "<<omega<<endl;
    alpha=_alpha;
    qDebug()<<"alpha es: "<<alpha<<endl<<endl;

}

void esferasimmovcir::setVel(float _x, float _y)
{
    vx=_x;
    vy=_y;
}

void esferasimmovcir::setPoint(float _x, float _y)
{
    x=x;
    y=y;
    vx=0;
    vy=0;
}

void esferasimmovcir::setomega(float _omega)
{
    omega=_omega;

}

void esferasimmovcir::setalpha(float _alpha)
{
    alpha=_alpha;
}

void esferasimmovcir::actualizar(float dt)
{
   // qDebug()<<endl<<endl<<endl;

    theta=theta+omega*dt+alpha*dt*dt*0.5;
   /* if(theta>2*3.1415){
        theta=theta-2*3.1415;
    }*/
    //theta=-theta;
    //theta=theta*3.1415/180;
    //qDebug()<<"theta es: "<<theta<<endl;
    omega=omega+alpha*dt;
   // qDebug()<<"omega es: "<<omega<<endl;
    x=a+radiotrayectoria*cos(theta);
   // qDebug()<<"x es: "<<x<<endl;
    y=b+radiotrayectoria*sin(theta);
   // qDebug()<<"y es: "<<y<<endl;
    vx=-omega*(y-b);
   // qDebug()<<"vx es: "<<vx<<endl;
    vy=omega*(x-a);
  //  qDebug()<<"vy es: "<<vy<<endl;
}

void esferasimmovcir::aceleracionang(float dt)
{
    alpha=alpha;
}

float esferasimmovcir::getX() const
{
    return x;
}

float esferasimmovcir::getY() const
{
    return y;
}

float esferasimmovcir::getRadiotrayectoria() const
{
    return radiotrayectoria;
}

float esferasimmovcir::getR() const
{
    return radio;
}

float esferasimmovcir::getVx() const
{
    return vx;
}

float esferasimmovcir::getVy() const
{
    return vy;
}

float esferasimmovcir::getomega() const
{
    return omega;
}

float esferasimmovcir::getalpha() const
{
    return alpha;
}

float esferasimmovcir::gettheta() const
{
    return theta;
}

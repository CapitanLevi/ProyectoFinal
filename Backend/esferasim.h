#ifndef ESFERASIM_H
#define ESFERASIM_H

#include <math.h>
class EsferaSim
{
public:
    EsferaSim(float x, float y, float r, float m);
    ~EsferaSim();
    void setVel(float x, float y);          //metodo para asignar la velocidad (en X y en Y)
    void actualizar2(float dt);
    void setPoint(float x, float y);        //metodo para asignar la posicion (en X y en Y)
    void actualizar(float dt);              //metodo que cambia los valores de posicion (realiza el movimiento), recive el lapso de tiempo transcurrido
    void aceleracion(float dt);
    void setK(float _K);


    float getX() const;                  //metodos para retornar los atributos
    float getY() const;
    float getR() const;
    float getVx() const;
    float getVy() const;





private:
    float px;                       //posicion en X
    float py;                       //posicion en Y
    const float radio;                //radio
    float vx;                       //velocidad en X
    float vy;                       //velocidad en Y
    float masa;
    float ax;
    float ay;
    float e;
    float k;
};

#endif // ESFERASIM_H

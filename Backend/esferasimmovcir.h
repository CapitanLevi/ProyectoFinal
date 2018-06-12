#ifndef ESFERASIMMOVCIR_H
#define ESFERASIMMOVCIR_H
#include <math.h>

class esferasimmovcir
{
public:
    esferasimmovcir(float m, float _a, float _b, float _radio,
                    float _radiotrayectoria, float w0, float _alpha);


    void setVel(float _x, float _y);          //metodo para asignar la velocidad (en X y en Y)
    void setPoint(float _x, float _y);        //metodo para asignar la posicion (en X y en Y)
    void setomega(float _omega);
    void setalpha(float _alpha);



    void actualizar(float dt);              //metodo que cambia los valores de posicion (realiza el movimiento), recive el lapso de tiempo transcurrido
    void aceleracionang(float dt);



    float getX() const;                  //metodos para retornar los atributos
    float getY() const;
    float getRadiotrayectoria() const;
    float getR() const;
    float getVx() const;
    float getVy() const;
    float getomega() const;
    float getalpha() const;
    float gettheta() const;

private:
    float x;                       //posicion en X
    float y;                       //posicion en Y
    float a;
    float b;
    float radio;
    float omega;
    float alpha;
    float theta;
    float radiotrayectoria;                //radio
    float vx;                       //velocidad en X
    float vy;                       //velocidad en Y
    float masa;

};

#endif // ESFERASIMMOVCIR_H

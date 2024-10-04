#pragma once
#include "Figura2D.h"
class Cuadrado : public Figura2D
{
private:
    float lado;

public:

    Cuadrado() : lado(1) {} 
    Cuadrado(float l);

    void Draw() override;

    float calcularArea() override;

    float calcularPer�metro() override;

    void cambiarTama�o(float nuevoTama�o) override;
};


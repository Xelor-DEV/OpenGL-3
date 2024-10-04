#pragma once
#include "Figura2D.h"
class Triangulo :
    public Figura2D
{
private:
    float base;
    float altura;

public:

    Triangulo(float b, float h);

    void Draw() override;
    float calcularArea() override;
    float calcularPer�metro() override;
    void cambiarTama�o(float nuevoTama�o) override;
};


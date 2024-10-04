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
    float calcularPerímetro() override;
    void cambiarTamaño(float nuevoTamaño) override;
};


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

    float calcularPerímetro() override;

    void cambiarTamaño(float nuevoTamaño) override;
};


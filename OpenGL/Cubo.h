#pragma once
#include "Figura3D.h"
#include "Cuadrado.h"

class Cubo : public Figura3D
{
private:
    Cuadrado* cuad[6];
    float lado;

public:
    Cubo(float l);
    void Draw() override;
    float calcularVolumen() override;
};


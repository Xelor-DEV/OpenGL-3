#pragma once
#include "Figura3D.h"
#include "Triangulo.h"

class Pir�mide : public Figura3D
{
private:
    Triangulo* tri[4];  // 4 tri�ngulos: 1 base y 3 laterales
    float ladoBase;        // Longitud de los lados de los tri�ngulos
    float altura;

public:
    Pir�mide(float baseLado, float h);

    void init() override;
    void Draw() override;
    float calcularVolumen() override;
};


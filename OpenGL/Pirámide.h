#pragma once
#include "Figura3D.h"
#include "Triangulo.h"

class Pirámide : public Figura3D
{
private:
    Triangulo* tri[4];  // 4 triángulos: 1 base y 3 laterales
    float ladoBase;        // Longitud de los lados de los triángulos
    float altura;

public:
    Pirámide(float baseLado, float h);

    void init() override;
    void Draw() override;
    float calcularVolumen() override;
};


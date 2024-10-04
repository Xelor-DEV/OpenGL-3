#pragma once
#include "Figura3D.h"
class Esfera : public Figura3D
{
public:
    int radio;
    Esfera(int r);
    void Draw() override;
    float calcularVolumen() override;
};


#pragma once
#include "Figura3D.h"
#include <math.h>
class Esfera : public Figura3D
{
public:
    float radio;
    int slices;
    int stacks;
    Esfera(float r , int slices, int stacks);
    void Draw() override;
    float calcularVolumen() override;
};


#pragma once
#include "Figura.h"

class Figura2D : public Figura
{
public:
    virtual float calcularArea() = 0;
    virtual float calcularPer�metro() = 0;
    virtual void cambiarTama�o(float nuevoTama�o) = 0;
};

#pragma once
#include "Figura.h"

class Figura2D : public Figura
{
public:
    virtual float calcularArea() = 0;
    virtual float calcularPerímetro() = 0;
    virtual void cambiarTamaño(float nuevoTamaño) = 0;
};

#pragma once
#include "Figura2D.h"
class Circulo : public Figura2D
{
private:
    float radio;
    int segmentos;

public:
    Circulo(float r, int seg = 30);
    void Draw() override;
    float calcularArea() override;
    float calcularPerímetro() override;
    void cambiarTamaño(float nuevoTamaño) override;
};


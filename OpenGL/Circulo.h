#pragma once
#include "Figura2D.h"
class Circulo : public Figura2D
{
private:
    float radio;
    int segmentos;
    float pi = 3.1415926535f;

public:
    Circulo(float r, int seg);
    void GenerateVertex();
    void Draw() override;
    float calcularArea() override;
    float calcularPerímetro() override;
    void cambiarTamaño(float nuevoTamaño) override;
};


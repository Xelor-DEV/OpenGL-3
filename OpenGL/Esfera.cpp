#include "Esfera.h"

Esfera::Esfera(int r) : radio(r) 
{

}

void Esfera::Draw()
{
    glutSolidSphere(radio, 20, 20);
}

float Esfera::calcularVolumen()
{
    float result = (4 / 3.0f) * 3.14159f * radio * radio * radio;
    return result;
}
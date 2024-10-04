#include "Triangulo.h"

Triangulo::Triangulo(float b, float h) : base(b), altura(h)
{

}

void Triangulo::Draw()
{
    glBegin(GL_TRIANGLES);
    glVertex3f(0, altura, 0);
    glVertex3f(-base / 2, 0, 0);
    glVertex3f(base / 2, 0, 0);
    glEnd();
}

float Triangulo::calcularArea()
{
    return (base * altura) / 2;
}

float Triangulo::calcularPerímetro()
{
    // Considerando un triángulo equilátero
    return 3 * base;
}

void Triangulo::cambiarTamaño(float nuevoTamaño)
{
    base = nuevoTamaño;
    altura = nuevoTamaño; // Ajuste proporcional para mantener la forma
}
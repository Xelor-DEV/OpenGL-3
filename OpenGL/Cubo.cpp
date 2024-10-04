#include "Cubo.h"

Cubo::Cubo(float l) : lado(l)
{
    for (int i = 0; i < 6; ++i)
    {
        cuad[i] = new Cuadrado(lado);
    }
}

void Cubo::Draw()
{
    glBegin(GL_QUADS);

    // Frontal
    glVertex3f(-lado / 2, -lado / 2, lado / 2);
    glVertex3f(lado / 2, -lado / 2, lado / 2);
    glVertex3f(lado / 2, lado / 2, lado / 2);
    glVertex3f(-lado / 2, lado / 2, lado / 2);

    // Trasero
    glVertex3f(-lado / 2, -lado / 2, -lado / 2);
    glVertex3f(-lado / 2, lado / 2, -lado / 2);
    glVertex3f(lado / 2, lado / 2, -lado / 2);
    glVertex3f(lado / 2, -lado / 2, -lado / 2);

    // Izquierda
    glVertex3f(-lado / 2, -lado / 2, -lado / 2);
    glVertex3f(-lado / 2, -lado / 2, lado / 2);
    glVertex3f(-lado / 2, lado / 2, lado / 2);
    glVertex3f(-lado / 2, lado / 2, -lado / 2);

    // Derecha
    glVertex3f(lado / 2, -lado / 2, -lado / 2);
    glVertex3f(lado / 2, lado / 2, -lado / 2);
    glVertex3f(lado / 2, lado / 2, lado / 2);
    glVertex3f(lado / 2, -lado / 2, lado / 2);

    // Arriba
    glVertex3f(-lado / 2, lado / 2, -lado / 2);
    glVertex3f(-lado / 2, lado / 2, lado / 2);
    glVertex3f(lado / 2, lado / 2, lado / 2);
    glVertex3f(lado / 2, lado / 2, -lado / 2);

    // Abajo
    glVertex3f(-lado / 2, -lado / 2, -lado / 2);
    glVertex3f(lado / 2, -lado / 2, -lado / 2);
    glVertex3f(lado / 2, -lado / 2, lado / 2);
    glVertex3f(-lado / 2, -lado / 2, lado / 2);

    glEnd();
}

float Cubo::calcularVolumen()
{
    return lado * lado * lado;
}
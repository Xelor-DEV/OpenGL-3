#include "Cuadrado.h"

Cuadrado::Cuadrado(float l) : lado(l)
{
    vertices = new GLfloat[12]{
        -lado / 2, -lado / 2, 0.0f,  // Esquina inferior izquierda
         lado / 2, -lado / 2, 0.0f,  // Esquina inferior derecha
         lado / 2,  lado / 2, 0.0f,  // Esquina superior derecha
        -lado / 2,  lado / 2, 0.0f   // Esquina superior izquierda
    };
	vertexCount = 4;
	primitiveType = GL_QUADS;
}

void Cuadrado::Draw()
{
    glBegin(GL_QUADS);
    glVertex3f(-lado / 2, -lado / 2, 0);
    glVertex3f(lado / 2, -lado / 2, 0);
    glVertex3f(lado / 2, lado / 2, 0);
    glVertex3f(-lado / 2, lado / 2, 0);
    glEnd();
}

float Cuadrado::calcularArea()
{
    return lado * lado;
}

float Cuadrado::calcularPerímetro()
{
    return 4 * lado;
}

void Cuadrado::cambiarTamaño(float nuevoTamaño)
{
    lado = nuevoTamaño;
}
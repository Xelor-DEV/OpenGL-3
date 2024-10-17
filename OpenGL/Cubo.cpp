#include "Cubo.h"

Cubo::Cubo(float l) : lado(l)
{
    for (int i = 0; i < 6; ++i)
    {
        cuad[i] = new Cuadrado(lado);
    }
    vertices = new GLfloat[72]{
        // Frente
        -lado / 2, -lado / 2,  lado / 2,
         lado / 2, -lado / 2,  lado / 2,
         lado / 2,  lado / 2,  lado / 2,
        -lado / 2,  lado / 2,  lado / 2,
        // Atrás
        -lado / 2, -lado / 2, -lado / 2,
        -lado / 2,  lado / 2, -lado / 2,
         lado / 2,  lado / 2, -lado / 2,
         lado / 2, -lado / 2, -lado / 2,
         // Izquierda
         -lado / 2, -lado / 2, -lado / 2,
         -lado / 2, -lado / 2,  lado / 2,
         -lado / 2,  lado / 2,  lado / 2,
         -lado / 2,  lado / 2, -lado / 2,
         // Derecha
          lado / 2, -lado / 2, -lado / 2,
          lado / 2,  lado / 2, -lado / 2,
          lado / 2,  lado / 2,  lado / 2,
          lado / 2, -lado / 2,  lado / 2,
          // Arriba
          -lado / 2,  lado / 2,  lado / 2,
           lado / 2,  lado / 2,  lado / 2,
           lado / 2,  lado / 2, -lado / 2,
          -lado / 2,  lado / 2, -lado / 2,
          // Abajo
          -lado / 2, -lado / 2,  lado / 2,
          -lado / 2, -lado / 2, -lado / 2,
           lado / 2, -lado / 2, -lado / 2,
           lado / 2, -lado / 2,  lado / 2
    };
	vertexCount = 24;
	primitiveType = GL_QUADS;
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
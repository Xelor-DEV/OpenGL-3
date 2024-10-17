#include "Triangulo.h"

Triangulo::Triangulo(float b, float h) : base(b), altura(h)
{
    vertices = new GLfloat[9]{
        -base / 2, 0.0f, 0.0f,  // Vértice 1 (esquina izquierda)
         base / 2, 0.0f, 0.0f,  // Vértice 2 (esquina derecha)
         0.0f, altura, 0.0f     // Vértice 3 (ápice superior)
    };
	vertexCount = 3;
	primitiveType = GL_TRIANGLES;
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
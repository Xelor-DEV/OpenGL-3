#include "Circulo.h"
#include <cmath>

Circulo::Circulo(float r, int seg) : radio(r), segmentos(seg) 
{
	GenerateVertex();
    primitiveType = GL_TRIANGLE_FAN;
}

void Circulo::GenerateVertex() 
{
    // Creamos un array para los vértices
    vertexCount = segmentos + 2; // +2 por el centro y el primer vértice duplicado para cerrar el círculo
    vertices = new GLfloat[vertexCount * 3]; // 3 componentes por vértice (x, y, z)

    // Centro del círculo
    vertices[0] = 0.0f; // x
    vertices[1] = 0.0f; // y
    vertices[2] = 0.0f; // z

    // Calculamos los vértices del círculo
    for (int i = 0; i <= segmentos; ++i) { // <= segmentos para incluir el vértice final que cierra el círculo
        float angle = 2.0f * pi * i / segmentos; // Calculamos el ángulo
        vertices[(i + 1) * 3] = radio * cos(angle); // x
        vertices[(i + 1) * 3 + 1] = radio * sin(angle); // y
        vertices[(i + 1) * 3 + 2] = 0.0f; // z
    }

}

void Circulo::Draw() {

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Centro del círculo
    for (int i = 0; i <= segmentos; ++i) {
        float angulo = 2.0f * 3.14159f * i / segmentos; // Calcular el ángulo
        float x = radio * cos(angulo);
        float y = radio * sin(angulo);
        glVertex2f(x, y); // Añadir el vértice del círculo
    }
    glEnd();
}

// Método para calcular el área del círculo
float Circulo::calcularArea() {
    return 3.14159f * radio * radio;
}

// Método para calcular el perímetro (circunferencia) del círculo
float Circulo::calcularPerímetro() {
    return 2 * 3.14159f * radio;
}

// Método para cambiar el tamaño del círculo (cambiar radio)
void Circulo::cambiarTamaño(float nuevoTamaño) {
    radio = nuevoTamaño;
}
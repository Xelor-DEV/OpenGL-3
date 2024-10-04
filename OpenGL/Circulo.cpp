#include "Circulo.h"
#include <cmath>

Circulo::Circulo(float r, int seg) : radio(r), segmentos(seg) {}

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
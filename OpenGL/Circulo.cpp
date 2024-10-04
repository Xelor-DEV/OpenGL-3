#include "Circulo.h"
#include <cmath>

Circulo::Circulo(float r, int seg) : radio(r), segmentos(seg) {}

void Circulo::Draw() {

    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0f, 0.0f); // Centro del c�rculo
    for (int i = 0; i <= segmentos; ++i) {
        float angulo = 2.0f * 3.14159f * i / segmentos; // Calcular el �ngulo
        float x = radio * cos(angulo);
        float y = radio * sin(angulo);
        glVertex2f(x, y); // A�adir el v�rtice del c�rculo
    }
    glEnd();
}

// M�todo para calcular el �rea del c�rculo
float Circulo::calcularArea() {
    return 3.14159f * radio * radio;
}

// M�todo para calcular el per�metro (circunferencia) del c�rculo
float Circulo::calcularPer�metro() {
    return 2 * 3.14159f * radio;
}

// M�todo para cambiar el tama�o del c�rculo (cambiar radio)
void Circulo::cambiarTama�o(float nuevoTama�o) {
    radio = nuevoTama�o;
}
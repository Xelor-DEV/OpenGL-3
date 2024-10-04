#include "Pir�mide.h"

Pir�mide::Pir�mide(float baseLado, float h) : ladoBase(baseLado), altura(h)
{
    // Inicializamos los 4 tri�ngulos
    for (int i = 0; i < 4; ++i) 
    {
        tri[i] = new Triangulo(ladoBase, altura); // Usar new para crear tri�ngulos
    }
}

void Pir�mide::init()
{
    // Inicializaci�n de texturas u otras configuraciones necesarias
}

void Pir�mide::Draw()
{
    // Calcular los v�rtices de la base triangular
    GLfloat halfBase = ladoBase / 2.0f;
    GLfloat baseVertices[3][3] = {
        {-halfBase, 0.0f, -halfBase}, // V�rtice 1 de la base
        {halfBase, 0.0f, -halfBase},  // V�rtice 2 de la base
        {0.0f, 0.0f, halfBase}        // V�rtice 3 de la base (punta hacia adelante)
    };

    // V�rtice del �pice de la pir�mide
    GLfloat apex[] = { 0.0f, altura, 0.0f };

    // Comenzamos a dibujar la pir�mide
    glBegin(GL_TRIANGLES);

    // Dibujar las caras laterales (3 tri�ngulos)
    for (int i = 0; i < 3; ++i) {
        glVertex3fv(apex);            // �pice
        glVertex3fv(baseVertices[i]); // Primer v�rtice de la base
        glVertex3fv(baseVertices[(i + 1) % 3]); // Segundo v�rtice de la base
    }

    glVertex3fv(baseVertices[0]);
    glVertex3fv(baseVertices[1]);
    glVertex3fv(baseVertices[2]);

    glEnd();
}

float Pir�mide::calcularVolumen()
{
    return (ladoBase * ladoBase * altura) / 6;  // F�rmula para el volumen de un tetraedro
}

#include "Pirámide.h"

Pirámide::Pirámide(float baseLado, float h) : ladoBase(baseLado), altura(h)
{
    // Inicializamos los 4 triángulos
    for (int i = 0; i < 4; ++i) 
    {
        tri[i] = new Triangulo(ladoBase, altura); // Usar new para crear triángulos
    }
}

void Pirámide::init()
{
    // Inicialización de texturas u otras configuraciones necesarias
}

void Pirámide::Draw()
{
    // Calcular los vértices de la base triangular
    GLfloat halfBase = ladoBase / 2.0f;
    GLfloat baseVertices[3][3] = {
        {-halfBase, 0.0f, -halfBase}, // Vértice 1 de la base
        {halfBase, 0.0f, -halfBase},  // Vértice 2 de la base
        {0.0f, 0.0f, halfBase}        // Vértice 3 de la base (punta hacia adelante)
    };

    // Vértice del ápice de la pirámide
    GLfloat apex[] = { 0.0f, altura, 0.0f };

    // Comenzamos a dibujar la pirámide
    glBegin(GL_TRIANGLES);

    // Dibujar las caras laterales (3 triángulos)
    for (int i = 0; i < 3; ++i) {
        glVertex3fv(apex);            // Ápice
        glVertex3fv(baseVertices[i]); // Primer vértice de la base
        glVertex3fv(baseVertices[(i + 1) % 3]); // Segundo vértice de la base
    }

    glVertex3fv(baseVertices[0]);
    glVertex3fv(baseVertices[1]);
    glVertex3fv(baseVertices[2]);

    glEnd();
}

float Pirámide::calcularVolumen()
{
    return (ladoBase * ladoBase * altura) / 6;  // Fórmula para el volumen de un tetraedro
}

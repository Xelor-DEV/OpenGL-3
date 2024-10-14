#include "Example7.h"

Example7::Example7()
{

}

void Example7::init()
{

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);

}

void Example7::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawPyramidWithInstancing();
    glFlush();
}

void Example7::KeyboardFunc(unsigned char key, int X, int Y)
{

}

void Example7::Idle()
{

}

void Example7::drawCube() {
    glBegin(GL_QUADS);

    // Frente
    glColor3f(1.0f, 0.0f, 0.0f); // Rojo
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Detrás
    glColor3f(0.0f, 1.0f, 0.0f); // Verde
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);

    // Arriba
    glColor3f(0.0f, 0.0f, 1.0f); // Azul
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Abajo
    glColor3f(1.0f, 1.0f, 0.0f); // Amarillo
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    // Izquierda
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Derecha
    glColor3f(0.0f, 1.0f, 1.0f); // Cian
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);

    glEnd();
}

void Example7::drawQuad() {
    glBegin(GL_QUADS);

    glColor3f(1.0f, 0.5f, 0.0f); // Color del quad
    glVertex2f(-1.0f, -1.0f); // Esquina inferior izquierda
    glVertex2f(1.0f, -1.0f);  // Esquina inferior derecha
    glVertex2f(1.0f, 1.0f);   // Esquina superior derecha
    glVertex2f(-1.0f, 1.0f);  // Esquina superior izquierda

    glEnd();
}

void Example7::drawSphere() {
	glutSolidSphere(1.0f, 20, 20);
}

void Example7::drawPyramid() {
    glBegin(GL_TRIANGLES);

    // Base
    glVertex3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);

    glVertex3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);

    // Lados
    glVertex3f(0.0f, 1.0f, 0.0f); // Punta
    glVertex3f(-1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, -1.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);

    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, 0.0f, 1.0f);
    glVertex3f(-1.0f, 0.0f, -1.0f);

    glEnd();
}

void Example7::drawCubeWithVertexArray() {
    // Vértices para las seis caras del cubo
    GLfloat vertices[] = {
        // Frente
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        // Atrás
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         // Izquierda
         -1.0f, -1.0f, -1.0f,
         -1.0f, -1.0f,  1.0f,
         -1.0f,  1.0f,  1.0f,
         -1.0f,  1.0f, -1.0f,
         // Derecha
          1.0f, -1.0f, -1.0f,
          1.0f,  1.0f, -1.0f,
          1.0f,  1.0f,  1.0f,
          1.0f, -1.0f,  1.0f,
          // Arriba
          -1.0f,  1.0f,  1.0f,
           1.0f,  1.0f,  1.0f,
           1.0f,  1.0f, -1.0f,
          -1.0f,  1.0f, -1.0f,
          // Abajo
          -1.0f, -1.0f,  1.0f,
          -1.0f, -1.0f, -1.0f,
           1.0f, -1.0f, -1.0f,
           1.0f, -1.0f,  1.0f
    };

    glEnableClientState(GL_VERTEX_ARRAY);  // Habilitar arreglo de vértices
    glVertexPointer(3, GL_FLOAT, 0, vertices);  // Especificar puntero de vértices

    // Dibujar las seis caras del cubo (4 vértices por cara, 6 caras)
    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);  // Deshabilitar arreglo de vértices
}

void Example7::drawQuadWithIndexedArray() {
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,  // Esquina inferior izquierda
        1.0f, -1.0f, 0.0f,   // Esquina inferior derecha
        1.0f, 1.0f, 0.0f,    // Esquina superior derecha
        -1.0f, 1.0f, 0.0f    // Esquina superior izquierda
    };

    GLubyte indices[] = {
        0, 1, 2, 3
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, indices);

    glDisableClientState(GL_VERTEX_ARRAY);
}

void Example7::drawPyramidWithInstancing() {
    // Vértices para las 4 caras laterales y la base de la pirámide
    GLfloat vertices[] = {
        0.0f,  1.0f,  0.0f,  
        -1.0f, -1.0f,  1.0f,  
        1.0f, -1.0f,  1.0f,   

        0.0f,  1.0f,  0.0f,
        1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,  

        0.0f,  1.0f,  0.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f, 

        0.0f,  1.0f,  0.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f, -1.0f,  1.0f, 
        1.0f, -1.0f,  1.0f,  
        1.0f, -1.0f, -1.0f,   
        -1.0f, -1.0f, -1.0f   
    };

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    // Dibujar las caras triangulares (4 triángulos, 3 vértices cada uno)
    glDrawArrays(GL_TRIANGLES, 0, 12);

    // Dibujar la base (1 cuadrado, 4 vértices)
    glDrawArrays(GL_QUADS, 12, 4);

    glDisableClientState(GL_VERTEX_ARRAY);
}



/*
#include "Vector3.h"
#include <iostream>
#include <cmath> // Solo para sin, cos y PI

// Definimos el valor de PI
#define PI 3.14159265359

// Parámetros de la esfera
const float radius = 1.0f;  // Radio de la esfera
const int stacks = 10;      // Número de stacks (divisiones verticales)
const int slices = 10;      // Número de slices (divisiones horizontales)

// Arreglo estático de tamaño predefinido
const int totalVertices = stacks * slices;
Vector3 vertices[totalVertices];  // Arreglo estático de vértices

void generarEsfera() {
    int index = 0;

    for (int i = 0; i < stacks; ++i) {
        // Ángulo de la stack (latitud)
        float theta = (i * PI) / (stacks - 1);
        float sinTheta = std::sin(theta);
        float cosTheta = std::cos(theta);

        for (int j = 0; j < slices; ++j) {
            // Ángulo de la slice (longitud)
            float phi = (j * 2 * PI) / (slices - 1);
            float sinPhi = std::sin(phi);
            float cosPhi = std::cos(phi);

            // Cálculo de las coordenadas del vértice
            float x = radius * sinTheta * cosPhi;
            float y = radius * cosTheta;
            float z = radius * sinTheta * sinPhi;

            // Asignar el vértice al arreglo
            vertices[index] = Vector3(x, y, z);
            index++;
        }
    }
}

int main() {
    // Generamos los vértices de la esfera
    generarEsfera();

    // Imprimimos algunos vértices para verificar
    for (int i = 0; i < totalVertices; ++i) {
        std::cout << "Vertice " << i << ": ("
                  << vertices[i].x << ", "
                  << vertices[i].y << ", "
                  << vertices[i].z << ")" << std::endl;
    }

    return 0;
}


*/
#include "Example7.h"

Example7::Example7()
{
    quad = new GLfloat[12]{
    -1.0f, -1.0f, 0.0f,  // Esquina inferior izquierda
    1.0f, -1.0f, 0.0f,   // Esquina inferior derecha
    1.0f, 1.0f, 0.0f,    // Esquina superior derecha
    -1.0f, 1.0f, 0.0f    // Esquina superior izquierda
    };
    cube = new GLfloat[72]{
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
    pyramid = new GLfloat[54]{
        // Lado 1
        0.0f,  1.0f,  0.0f,
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,

        // Lado 2
        0.0f,  1.0f,  0.0f,
        1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,

        // Lado 3
        0.0f,  1.0f,  0.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,

        // Lado 4
        0.0f,  1.0f,  0.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,

        // Base - Triángulo 1
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,

        // Base - Triángulo 2
        -1.0f, -1.0f,  1.0f,
        1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f
    };
    sphereVertex = 400;
	figura = new Triangulo(2,2);
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

    /*
     // Dibuja el cubo utilizando los métodos genéricos
    drawWithVertexArray(cube, 24, GL_QUADS); // Vertex Array
    drawWithIndexedArray(cube, 24, GL_QUADS); // Indexed Array
    drawInstanced(cube, 24, GL_QUADS, 1); // Instanced (1 instancia)

    // Dibuja el cuadrado utilizando los métodos genéricos
    drawWithVertexArray(quad, 4, GL_QUADS); // Vertex Array
    drawWithIndexedArray(quad, 4, GL_QUADS); // Indexed Array
    drawInstanced(quad, 4, GL_QUADS, 3); // Instanced (1 instancia)

    drawWithVertexArray(generateSphere(), sphereVertex, GL_TRIANGLES); // Vertex Array
    drawWithIndexedArray(generateSphere(), sphereVertex, GL_TRIANGLES); // Indexed Array
    drawInstanced(generateSphere(), sphereVertex, GL_TRIANGLES, 3); // Instanced (1 instancia)

    // Dibuja la pirámide utilizando los métodos genéricos
    drawWithVertexArray(pyramid, 18, GL_TRIANGLES); // Vertex Array
    drawWithIndexedArray(pyramid, 18, GL_TRIANGLES); // Indexed Array
    drawInstanced(pyramid, 18, GL_TRIANGLES, 1); // Instanced (1 instancia)   
    */
    figura->VertexArrayIndexed();

    glFlush();
}

void Example7::KeyboardFunc(unsigned char key, int X, int Y)
{

}

void Example7::Idle()
{

}

Vector3* Example7::generateSphere()
{
    int latSegments = 20;  // Segmentos de latitud
    int lonSegments = 20;  // Segmentos de longitud
    float radius = 1.0f;

    sphereVertex = latSegments * lonSegments * 6;  // Triángulos (dos por cada cuadrado de la esfera)
    Vector3* vertices = new Vector3[sphereVertex];

    int index = 0;

    for (int lat = 0; lat < latSegments; ++lat) {
        float theta1 = lat * pi / latSegments;  // Ángulo de latitud
        float theta2 = (lat + 1) * pi / latSegments;

        for (int lon = 0; lon < lonSegments; ++lon) {
            float phi1 = lon * 2 * pi / lonSegments;  // Ángulo de longitud
            float phi2 = (lon + 1) * 2 * pi / lonSegments;

            // Puntos de cada cuadrante de la esfera
            Vector3 p1(radius * sin(theta1) * cos(phi1), radius * cos(theta1), radius * sin(theta1) * sin(phi1));
            Vector3 p2(radius * sin(theta2) * cos(phi1), radius * cos(theta2), radius * sin(theta2) * sin(phi1));
            Vector3 p3(radius * sin(theta2) * cos(phi2), radius * cos(theta2), radius * sin(theta2) * sin(phi2));
            Vector3 p4(radius * sin(theta1) * cos(phi2), radius * cos(theta1), radius * sin(theta1) * sin(phi2));

            // Primer triángulo
            vertices[index++] = p1;
            vertices[index++] = p2;
            vertices[index++] = p3;

            // Segundo triángulo
            vertices[index++] = p1;
            vertices[index++] = p3;
            vertices[index++] = p4;
        }
    }

    return vertices;
}

void Example7::drawWithIndexedArray(GLfloat* vertices, int vertexCount, GLenum primitiveType) {
    GLuint* indices = nullptr;
    int indexCount = 0;

    if (primitiveType == GL_QUADS) {
        // Calcular índices para quads
        indexCount = (vertexCount / 4) * 4;  // 4 vértices por cada quad
        indices = new GLuint[indexCount];

        for (int i = 0, j = 0; i < indexCount; i += 4, j += 4) {
            indices[i] = j;
            indices[i + 1] = j + 1;
            indices[i + 2] = j + 2;
            indices[i + 3] = j + 3;
        }
    }
    else if (primitiveType == GL_TRIANGLES) {
        // Calcular índices para triángulos
        indexCount = (vertexCount / 3) * 3;  // 3 vértices por cada triángulo
        indices = new GLuint[indexCount];

        for (int i = 0, j = 0; i < indexCount; i += 3, j += 3) {
            indices[i] = j;
            indices[i + 1] = j + 1;
            indices[i + 2] = j + 2;
        }
    }
    else {
        return;
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    // Dibujar los elementos con los índices calculados
    glDrawElements(primitiveType, indexCount, GL_UNSIGNED_INT, indices);

    glDisableClientState(GL_VERTEX_ARRAY);

    delete[] indices;  // Liberar memoria de los índices
}

void Example7::drawWithVertexArray(GLfloat* vertices, int vertexCount, GLenum primitiveType) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(primitiveType, 0, vertexCount);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void Example7::drawInstanced(GLfloat* vertices, int vertexCount, GLenum primitiveType, int instanceCount) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    // Mover las instancias
    GLfloat offsetX = 1.0f; // Valor de desplazamiento en el eje X
    GLfloat offsetZ = 1.0f; // Valor de desplazamiento en el eje Z

    for (int i = 0; i < instanceCount; ++i) {
        // Aplicar la transformación de traslación
        glPushMatrix(); // Guardar la matriz actual
        glTranslatef(i * offsetX, 0.0f, i * offsetZ); // Mover en x y z

        // Dibujar con instancing
        glDrawArrays(primitiveType, 0, vertexCount);

        glPopMatrix(); // Restaurar la matriz anterior
    }

    glDisableClientState(GL_VERTEX_ARRAY);
}

void Example7::drawWithIndexedArray(Vector3* vertices, int vertexCount, GLenum primitiveType) {
    GLuint* indices = nullptr;
    int indexCount = 0;

    if (primitiveType == GL_QUADS) {
        // Calcular índices para quads
        indexCount = (vertexCount / 4) * 4;  // 4 vértices por cada quad
        indices = new GLuint[indexCount];

        for (int i = 0, j = 0; i < indexCount; i += 4, j += 4) {
            indices[i] = j;
            indices[i + 1] = j + 1;
            indices[i + 2] = j + 2;
            indices[i + 3] = j + 3;
        }
    }
    else if (primitiveType == GL_TRIANGLES) {
        // Calcular índices para triángulos
        indexCount = (vertexCount / 3) * 3;  // 3 vértices por cada triángulo
        indices = new GLuint[indexCount];

        for (int i = 0, j = 0; i < indexCount; i += 3, j += 3) {
            indices[i] = j;
            indices[i + 1] = j + 1;
            indices[i + 2] = j + 2;
        }
    }
    else {
        return;
    }

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    // Dibujar los elementos con los índices calculados
    glDrawElements(primitiveType, indexCount, GL_UNSIGNED_INT, indices);

    glDisableClientState(GL_VERTEX_ARRAY);

    delete[] indices;  // Liberar memoria de los índices
}

void Example7::drawWithVertexArray(Vector3* vertices, int vertexCount, GLenum primitiveType) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(primitiveType, 0, vertexCount);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void Example7::drawInstanced(Vector3* vertices, int vertexCount, GLenum primitiveType, int instanceCount) {
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);


    // Mover las instancias
    GLfloat offsetX = 1.0f; // Valor de desplazamiento en el eje X
    GLfloat offsetZ = 1.0f; // Valor de desplazamiento en el eje Z

    for (int i = 0; i < instanceCount; ++i) {
        // Aplicar la transformación de traslación
        glPushMatrix(); // Guardar la matriz actual
        glTranslatef(i * offsetX, 0.0f, i * offsetZ); // Mover en x y z

        // Dibujar con instancing
        glDrawArrays(primitiveType, 0, vertexCount);

        glPopMatrix(); // Restaurar la matriz anterior
    }

    glDisableClientState(GL_VERTEX_ARRAY);
}

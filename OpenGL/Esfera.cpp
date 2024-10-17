#include "Esfera.h"

Esfera::Esfera(float r, int slices, int stacks) : radio(r),slices(slices),stacks(stacks)
{
	sphereVertex = GenerateVertex();
	primitiveType = GL_TRIANGLES;
}

void Esfera::Draw()
{
    for (int i = 0; i < stacks; i++) {
        double lat0 = 3.141592f * (-0.5 + (float)(i) / stacks);
        double z0 = radio * sin(lat0);
        double zr0 = radio * cos(lat0);

        double lat1 = 3.141592f * (-0.5 + (float)(i + 1) / stacks);
        double z1 = radio * sin(lat1);
        double zr1 = radio * cos(lat1);

        glBegin(GL_QUAD_STRIP);
        for (int j = 0; j <= slices; j++) {
            float lng = 2 * 3.141592f * (float)(j) / slices;
            double x = cos(lng);
            double y = sin(lng);

            glVertex3f((GLfloat)x * (GLfloat)zr0, (GLfloat)y * (GLfloat)zr0, (GLfloat)z0);
            glVertex3f((GLfloat)x * (GLfloat)zr1, (GLfloat)y * (GLfloat)zr1, (GLfloat)z1);
        }
        glEnd();
    }
}

Vector3* Esfera::GenerateVertex()
{
    int latSegments = stacks;  // Segmentos de latitud
    int lonSegments = slices;  // Segmentos de longitud
    float radius = radio;

    vertexCount = latSegments * lonSegments * 6;  // Triángulos (dos por cada cuadrado de la esfera)
    Vector3* vertices = new Vector3[vertexCount];

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

float Esfera::calcularVolumen()
{
    float result = (4 / 3.0f) * 3.14159f * radio * radio * radio;
    return result;
}

void Esfera::VertexArray()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, sphereVertex);
    glDrawArrays(primitiveType, 0, vertexCount);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void Esfera::VertexArrayIndexed()
{
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
    glVertexPointer(3, GL_FLOAT, 0, sphereVertex);

    // Dibujar los elementos con los índices calculados
    glDrawElements(primitiveType, indexCount, GL_UNSIGNED_INT, indices);

    glDisableClientState(GL_VERTEX_ARRAY);

    delete[] indices;  // Liberar memoria de los índices
}

void Esfera::VertexArrayInstanced(int instanceCount)
{
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, sphereVertex);


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

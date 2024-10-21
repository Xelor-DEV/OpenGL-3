#include "Figura.h"

void Figura::EnableTexture()
{
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glEnable(GL_TEXTURE_GEN_T);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	glBindTexture(GL_TEXTURE_2D, IDTexture);
}

void Figura::DisableTexture()
{
	glDisable(GL_TEXTURE_GEN_S); //enable texture coordinate generation
	glDisable(GL_TEXTURE_GEN_T);
	glDisable(GL_TEXTURE_2D);
	glutSwapBuffers();
}

void Figura::init()
{

}

void Figura::Render()
{
	EnableTexture();
	Draw();
	DisableTexture();
}

void Figura::DrawWithColor()
{
	glColor3f(color.r, color.g, color.b);
	Draw();
}

void Figura::RenderWithColor()
{
	EnableTexture();
	DrawWithColor();
	DisableTexture();
}

void Figura::SetTexture(GLuint idTexture)
{
	IDTexture = idTexture;
}

void Figura::SetColor(Color color)
{
	this->color = color;
}

void Figura::VertexArray()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(primitiveType, 0, vertexCount);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Figura::VertexArrayIndexed()
{
    GLuint* indices = nullptr;
    int indexCount = 0;

    if (primitiveType == GL_QUADS) {
        // Calcular índices para quads
        // Asegurarse de que el número de índices sea un múltiplo de 4
        indexCount = (vertexCount / 4) * 4;  // 4 vértices por cada quad
        indices = new GLuint[indexCount];

        // Llenar el array de índices con las posiciones de los vértices
        int j = 0; // Declarar j fuera del bucle
        for (int i = 0; i < indexCount; i += 4) {
            indices[i] = j;         // Primer vértice del quad
            indices[i + 1] = j + 1; // Segundo vértice del quad
            indices[i + 2] = j + 2; // Tercer vértice del quad
            indices[i + 3] = j + 3; // Cuarto vértice del quad
            j += 4; // Incrementar j en 4 para la siguiente iteración
        }
    }
    else if (primitiveType == GL_TRIANGLES) {
        // Calcular índices para triángulos
        indexCount = (vertexCount / 3) * 3;  // 3 vértices por cada triángulo
        indices = new GLuint[indexCount];

        int j = 0; // Declarar j fuera del bucle
        for (int i = 0; i < indexCount; i += 3) {
            indices[i] = j;         // Primer vértice
            indices[i + 1] = j + 1; // Segundo vértice
            indices[i + 2] = j + 2; // Tercer vértice
            j += 3; // Incrementar j después de usarlo
        }
    }
    else if (primitiveType == GL_TRIANGLE_FAN) {
        // Calcular índices para GL_TRIANGLE_FAN
        indexCount = vertexCount - 1; // Excluimos el centro para los índices
        indices = new GLuint[indexCount];

        int j = 1; // Comenzar en 1 para saltar el centro
        for (int i = 0; i < indexCount; ++i) {
            indices[i] = j; // Usamos el vértice correspondiente
            j++; // Incrementar j
        }
        indices[indexCount - 1] = 1; // Para cerrar el fan, el último índice apunta al primer vértice
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

void Figura::VertexArrayInstanced(int instanceCount)
{
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




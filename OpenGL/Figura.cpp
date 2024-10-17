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




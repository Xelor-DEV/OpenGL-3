#include "Esfera.h"

Esfera::Esfera(float r, int slices, int stacks) : radio(r),slices(slices),stacks(stacks)
{

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

float Esfera::calcularVolumen()
{
    float result = (4 / 3.0f) * 3.14159f * radio * radio * radio;
    return result;
}
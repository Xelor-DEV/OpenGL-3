#include "DirectionalLight.h"

void DirectionalLight::apply(int lightIndex) {
    glEnable(GL_LIGHT0 + lightIndex);
    glLightfv(GL_LIGHT0 + lightIndex, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0 + lightIndex, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0 + lightIndex, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0 + lightIndex, GL_POSITION, positionDirection);
}

DirectionalLight::DirectionalLight(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat direction[4])
    : Light(ambient, diffuse, specular, direction) {
    positionDirection[3] = 0.0f; // Establecer en 0.0f indica que es una luz direccional (se usa la dirección, no la posición)
}

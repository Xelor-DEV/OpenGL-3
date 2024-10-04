#include "PointLight.h"

void PointLight::apply(int lightIndex) {
    glEnable(GL_LIGHT0 + lightIndex);
    glLightfv(GL_LIGHT0 + lightIndex, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0 + lightIndex, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0 + lightIndex, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0 + lightIndex, GL_POSITION, positionDirection);
}

PointLight::PointLight(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat position[4])
    : Light(ambient, diffuse, specular, position) {
    positionDirection[3] = 1.0f; // 1 para PointLight
}
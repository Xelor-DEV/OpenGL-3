#include "SpotLight.h"

void SpotLight::apply(int lightIndex) {
    glEnable(GL_LIGHT0 + lightIndex);
    glLightfv(GL_LIGHT0 + lightIndex, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0 + lightIndex, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0 + lightIndex, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0 + lightIndex, GL_POSITION, positionDirection);
    glLightfv(GL_LIGHT0 + lightIndex, GL_SPOT_DIRECTION, direction);
    glLightf(GL_LIGHT0 + lightIndex, GL_SPOT_CUTOFF, cutoff);
    glLightf(GL_LIGHT0 + lightIndex, GL_SPOT_EXPONENT, exponent);
}

SpotLight::SpotLight(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat position[4], GLfloat direction[3], GLfloat cutoff, GLfloat exponent)
    : Light(ambient, diffuse, specular, position), cutoff(cutoff), exponent(exponent) {
    for (int i = 0; i < 3; i++) {
        this->direction[i] = direction[i];
    }
    positionDirection[3] = 1.0f; // 1 para SpotLight
}

#pragma once
#include "IncludeGL.h"

class Light
{
protected:
    GLfloat ambient[4];
    GLfloat diffuse[4];
    GLfloat specular[4];
    GLfloat positionDirection[4]; // Posición para PointLight y SpotLight, Dirección para DirectionalLight

public:
    Light(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat positionDirection[4]);
    virtual void apply(int lightIndex) = 0;
};


#pragma once
#include "Light.h"

class PointLight : public Light
{
public:
    PointLight(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat position[4]);
    void apply(int lightIndex) override;
};


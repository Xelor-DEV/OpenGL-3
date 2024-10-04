#pragma once
#include "Light.h"
class DirectionalLight : public Light
{
public:
    DirectionalLight(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat direction[4]);
    void apply(int lightIndex) override;
};


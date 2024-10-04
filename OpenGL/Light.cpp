#include "Light.h"

Light::Light(GLfloat ambient[4], GLfloat diffuse[4], GLfloat specular[4], GLfloat positionDirection[4])
{
    for (int i = 0; i < 4; ++i) 
    {
        this->ambient[i] = ambient[i];
        this->diffuse[i] = diffuse[i];
        this->specular[i] = specular[i];
        this->positionDirection[i] = positionDirection[i];
    }
}

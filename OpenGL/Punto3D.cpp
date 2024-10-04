#include "Punto3D.h"
#include "IncludeGL.h"

Punto3D::Punto3D(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

void Punto3D::Draw() 
{
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POINTS);
	glVertex3f(x,y,z);
    glEnd();
}
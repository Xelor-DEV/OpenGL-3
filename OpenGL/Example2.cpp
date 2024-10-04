#include "Example2.h"
#include "IncludeGL.h"
#include <iostream>

float angle = 20;

Example2::Example2()
{
	translate = new Vector3(1, 1, 1);
	rotation = new Vector3(0, 1, 0);
	scale = new Vector3(1.5f, 1.5f, 1.5f);
}

void Example2::init()
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);

}

void Example2::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();

	glTranslatef(translate->x, translate->y, translate->z);
	glScalef(scale->x, scale->y, scale->z);
	glRotatef(angle, rotation->x, rotation->y, rotation->z);

	Draw2DAxis(10);

	glPopMatrix();
	glFlush();
}

void Example2::KeyboardFunc(unsigned char key, int X, int Y)
{

}

void Example2::Idle()
{

}

void Example2::Draw2DAxis(float lineLength)
{
	// Dibuja el eje X en rojo
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(-lineLength, 0.0f, 0.0f); // Extremo negativo del eje X
	glVertex3f(lineLength, 0.0f, 0.0f);  // Extremo positivo del eje X
	glEnd();

	// Dibuja el eje Y en verde
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(0.0f, -lineLength, 0.0f); // Extremo negativo del eje Y
	glVertex3f(0.0f, lineLength, 0.0f);  // Extremo positivo del eje Y
	glEnd();
}

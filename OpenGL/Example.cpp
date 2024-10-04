#include "Example.h"
#include "IncludeGL.h"

Example::Example()
{

}

void Example::Draw3DAxis(float distance)
{
	glColor3f(1.0f, 0.0f, 0.0f);

	glBegin(GL_LINES);
	glVertex3f(-distance, 0.0f, 0.0f); // Start of the x-axis
	glVertex3f(distance, 0.0f, 0.0f);  // End of the x-axis
	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_LINES);
	glVertex3f(0.0f, -distance, 0.0f); // Start of the y-axis
	glVertex3f(0.0f, distance, 0.0f);  // End of the y-axis
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_LINES);
	glVertex3f(0.0f, 0.0f, -distance); // Start of the z-axis
	glVertex3f(0.0f, 0.0f, distance);  // End of the z-axis
	glEnd();
}

void Example::DrawGrids(float gridSize, float step)
{
	glColor3f(0.5f, 0.5f, 0.5f);

	glBegin(GL_LINES);

	// Draw lines parallel to the Z axis
	for (float x = -gridSize; x <= gridSize; x += step)
	{
		glVertex3f(x, 0.0f, -gridSize);
		glVertex3f(x, 0.0f, gridSize);
	}

	// Draw lines parallel to the X axis
	for (float z = -gridSize; z <= gridSize; z += step)
	{
		glVertex3f(-gridSize, 0.0f, z);
		glVertex3f(gridSize, 0.0f, z);
	}

	glEnd();
}

void Example::Draw3DAxisWithGrid(float gridSize, float step, float distance)
{
	DrawGrids(gridSize,step);
	Draw3DAxis(distance);
}


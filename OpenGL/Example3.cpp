#include "Example3.h"
Example3::Example3()
{
	camera = Camera();
	direction_temp = Vector3(2,2,2);
    position_temp = Vector3(0,0,0);
}

void Example3::init()
{

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
    camera.Init();
}

void Example3::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DrawGrids(10, 1);
	Draw3DAxis(50);

	camera.Update();
    DrawCube(1.0f, -2.0f, 0.0f, 0.0f);
    DrawSphere(0.5f, 2.0f, 0.0f, 0.0f);
    DrawCone(0.5f, 1.0f, 0.0f, 2.0f, 0.0f);

	glFlush();
}

void Example3::KeyboardFunc(unsigned char key, int X, int Y)
{
	position_temp = camera.GetPosition();
	direction_temp = camera.GetDirection();

	switch (key)
	{
	case 'a':
		position_temp.x = position_temp.x + 0.1f;
		break;
	case 'd':
		position_temp.x = position_temp.x - 0.1f;
		break;
	case 'w':
		position_temp.z = position_temp.z + 0.1f;
		break;
	case 's':
		position_temp.z = position_temp.z - 0.1f;
		break;
	case 'q':
		direction_temp.x = direction_temp.x + 0.1f;
		break;
	case 'e':
		direction_temp.x = direction_temp.x - 0.1f;
		break;
	case 'z':
		direction_temp.z = direction_temp.z + 0.1f;
		break;
	case 'c':
		direction_temp.z = direction_temp.z - 0.1f;
		break;
	}
	camera.SetPosition(position_temp);
	camera.SetDirection(direction_temp);

	glutPostRedisplay();
}

void Example3::Idle()
{

}

void Example3::DrawCube(float size, float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(1.0f, 0.0f, 0.0f);
    glutSolidCube(size);
    glPopMatrix();
}

void Example3::DrawSphere(float radius, float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(0.0f, 1.0f, 0.0f);
    glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}

void Example3::DrawCone(float base, float height, float x, float y, float z) {
    glPushMatrix();
    glTranslatef(x, y, z);
    glColor3f(0.0f, 0.0f, 1.0f);
    glutSolidCone(base, height, 20, 20);
    glPopMatrix();
}

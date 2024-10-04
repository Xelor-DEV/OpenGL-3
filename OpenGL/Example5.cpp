#include "Example5.h"
#include <stdio.h>
#include "BMPTextureLoader.h"

Example5::Example5()
{
    _TextureLoader = new BMPTextureLoader();
    texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./Textures/wallBMP.bmp");

    pos = { 0.0f, 0.0f, 0.0f };
    rotation = { 0.0f, 0.0f, 0.0f };
    scale = { 1.0f, 1.0f, 1.0f };

    color = { 1.0f, 1.0f, 0 };

    figura = new Circulo(2);
}
void Example5::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    figura->SetTexture(texture);
	figura->SetColor(color);
}
void Example5::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::Draw3DAxis(50);
    figura->Render();
    glFlush();
}
void Example5::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example5::Idle()
{

}

void Example5::DrawTriangle(float x, float y, float z)
{
    glBegin(GL_TRIANGLES);
    glTranslatef(x, y, z);
    glVertex3f(0.0f, 1.0f, 0.0f);
    glVertex3f(-1.0f, -1.0f, 0.0f); 
    glVertex3f(1.0f, -1.0f, 0.0f); 
    glEnd(); 
}

void Example5::DrawQuad(float x, float y, float z)
{
    glBegin(GL_QUADS); 
    glTranslatef(x, y, z);
    glVertex3f(-1.0f, 1.0f, 0.0f); 
    glVertex3f(1.0f, 1.0f, 0.0f); 
    glVertex3f(1.0f, -1.0f, 0.0f);  
    glVertex3f(-1.0f, -1.0f, 0.0f);
    glEnd();
}

void Example5::DrawCube(float size, float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidCube(size);
    glPopMatrix();
}

void Example5::DrawSphere(float radius, float x, float y, float z)
{
    glPushMatrix();
    glTranslatef(x, y, z);
    glutSolidSphere(radius, 20, 20);
    glPopMatrix();
}

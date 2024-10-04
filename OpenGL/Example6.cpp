#include "Example6.h"
#include <stdio.h>
#include "BMPTextureLoader.h"

GLuint idDisplayList;

Example6::Example6()
{
    _TextureLoader = new BMPTextureLoader();
    texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./Textures/wallBMP.bmp");

    // Inicializa las variables de posición, rotación y escala
    pos = { 0.0f, 0.0f, 0.0f };
    rotation = { 0.0f, 0.0f, 0.0f };
    scale = { 1.0f, 1.0f, 1.0f };

    cuadrado = new Cuadrado(1);
}
void Example6::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    cuadrado->SetTexture(texture);
    createDisplayList();
}
void Example6::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Example::Draw3DAxis(50);
    glCallList(idDisplayList);
    glFlush();
}
void Example6::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example6::Idle()
{

}

void Example6::createDisplayList() {
    idDisplayList = glGenLists(1); // Genera un ID para la display list
    glNewList(idDisplayList, GL_COMPILE); // Inicia la definición de la lista
    
    cuadrado->Render();
    glEndList(); // Finaliza la display list
}

void Example6::DrawShape()
{
    

    
}

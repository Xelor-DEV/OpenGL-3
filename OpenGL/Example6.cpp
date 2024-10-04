#include "Example6.h"
#include <stdio.h>
#include "BMPTextureLoader.h"

Example6::Example6()
{
    _TextureLoader = new BMPTextureLoader();
    texture = ((BMPTextureLoader*)_TextureLoader)->LoadBMP("./Textures/wallBMP.bmp");

    // Inicializa las variables de posición, rotación y escala
    pos = { 0.0f, 0.0f, 0.0f };
    rotation = { 0.0f, 0.0f, 0.0f };
    scale = { 1.0f, 1.0f, 1.0f };

    idDisplayList = glGenLists(1);

    figura = new Cuadrado(1);

    n = 5;
}
void Example6::init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
    glMatrixMode(GL_MODELVIEW);
    createDisplayList();
}
void Example6::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    for (int i = 0; i < n; ++i) {
        glPushMatrix(); // Guardar la matriz actual
        glTranslatef(i * 1, 0.0f, 0.0f); // Mover a la posición deseada
        glCallList(idDisplayList); // Usar el display list para renderizar el cuadrado
        glPopMatrix(); // Restaurar la matriz original
    }
    Example::Draw3DAxis(50);
    glFlush();
}

void Example6::createDisplayList() 
{
    glNewList(idDisplayList, GL_COMPILE); // Inicia la definición de la lista
    figura->Draw();
    glEndList(); // Finaliza la display list
}

void Example6::KeyboardFunc(unsigned char key, int X, int Y)
{

}
void Example6::Idle()
{

}


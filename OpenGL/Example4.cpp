#include "Example4.h"
#include "Light.h"
#include "PointLight.h"
#include "SpotLight.h"
#include "DirectionalLight.h"

GLfloat lightTestPosition[3] = { 0,2,0 };
GLfloat firstSolidSphere[3] = { 0,0,0 };
GLfloat secondSolidSphere[3] = { 1.5f, 0, 0 };

Light* currentLight = nullptr;

Example4::Example4()
{

}

void Example4::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
    glEnable(GL_LIGHTING);

    // Inicializar con un PointLight por defecto
    GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseColor[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specularColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat pointPos[] = { 0.0f, 2.0f, 0.0f, 1.0f };

    currentLight = new PointLight(ambientColor, diffuseColor, specularColor, pointPos);
}

void Example4::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    Draw3DAxis(50);
    // Aplicar la luz actual
    if (currentLight) {
        currentLight->apply(0);
    }
    // Dibujar esfera
    MaterialShadeSmooth(); 
    DrawSphere(firstSolidSphere, 0.5f);
    DrawSphere(secondSolidSphere, 0.5f);
	glFlush();
}

void Example4::MaterialShadeSmooth()
{
    SetupMaterialTest();
    glShadeModel(GL_SMOOTH);
}

void Example4::MaterialShadeFlat()
{
    SetupMaterialTest();
    glShadeModel(GL_FLAT);
}

void Example4::SetupMaterialTest()
{
    // Definición de propiedades del material
    GLfloat ambientMaterial[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // Material ambiental
    GLfloat diffuseMaterial[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Material difuso
    GLfloat specularMaterial[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Material especular
    GLfloat shininess[] = { 50.0f }; // Brillo del material

    // Establecer propiedades del material
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambientMaterial);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuseMaterial);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularMaterial);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
}

void Example4::SetupLightingTest()
{
    // Activar el uso de iluminación
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0); // Activar la luz 0
    DrawSphere(lightTestPosition, 0.4f);

    // Definición de propiedades de la luz
    GLfloat ambientLight[] = { 0.2f, 0.2f, 0.2f, 1.0f };  // Luz ambiental
    GLfloat diffuseLight[] = { 0.8f, 0.8f, 0.8f, 1.0f };  // Luz difusa
    GLfloat specularLight[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // Luz especular
    GLfloat lightPosition[] = { lightTestPosition[0], lightTestPosition[1], lightTestPosition[2], 1.0f }; // Posición de la luz en el espacio
    // Establecer propiedades de la luz
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specularLight);
    // Posición de la luz
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
}

void Example4::DrawSphere(GLfloat position[3] , float radius)
{
    glPushMatrix();
    glTranslatef(position[0], position[1], position[2]);
    glutSolidSphere(radius, 50, 50);   // Dibujar esfera con radio 1.0, con 50 segmentos

    glPopMatrix();
}

void Example4::KeyboardFunc(unsigned char key, int X, int Y)
{
    // Cambiar el tipo de luz según la tecla presionada
    GLfloat ambientColor[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuseColor[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat specularColor[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    if (key == 'a' || key == 'A') {
        // Cambiar a PointLight
        //delete currentLight; // Liberar memoria
        GLfloat pointPos[] = { 0.0f, 2.0f, 0.0f, 1.0f }; // Posición
        currentLight = new PointLight(ambientColor, diffuseColor, specularColor, pointPos);
    }
    else if (key == 'b' || key == 'B') {
        // Cambiar a DirectionalLight
        //delete currentLight; // Liberar memoria
        GLfloat dir[] = { 1.0f, -1.0f, 0.0f, 0.0f }; // Dirección desde arriba a la derecha
        currentLight = new DirectionalLight(ambientColor, diffuseColor, specularColor, dir);
    }
    else if (key == 'c' || key == 'C') {
        // Cambiar a SpotLight
        //delete currentLight; // Liberar memoria
        GLfloat spotDir[] = { -1.0f, -1.0f, 0.0f }; // Dirección del spot hacia abajo a la izquierda
        currentLight = new SpotLight(ambientColor, diffuseColor, specularColor, lightTestPosition, spotDir, 45.0f, 2.0f);
    }
}

void Example4::Idle()
{

}



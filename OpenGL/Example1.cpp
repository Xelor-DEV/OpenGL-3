#include "Example1.h"
#include "IncludeGL.h"
#include <iostream>

char currentOption = ' '; 
bool menuShown = false; 

Example1::Example1()
{
	point = new Punto3D(1.5f,1.5f,0);
	polygon = new Polígono();
}

void Example1::init()
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClearDepth(1.0);
	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
}

void Example1::Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (menuShown == false)
	{
		ShowMenu();
		menuShown = true;
	}
	// Dependiendo de la opción seleccionada, se ejecuta la función correspondiente
	switch (currentOption)
	{
	case 'a':
		DrawPoint();
		break;
	case 'b':
		DrawLine();
		break;
	case 'c':
		DrawTriangle();
		break;
	case 'd':
		DrawLineStrip();
		break;
	case 'e':
		Draw2DAxis(10.0f);
		break;
	case 'f':
		DrawLineWithColor();
		break;
	case 'g':
		Draw3DAxis(5.0f);
		break;
	case 'h':
		Draw3DAxisWithGrid(10.0f, 1.0f, 5.0f);
		break;
	case 'i':
		DrawGrids(10.0f, 1.0f); 
		break;
	case 'j':
		polygon->Draw();
		break;
	case 'k':
		point->Draw();
		break;
	default:
		std::cout << "Esperando entrada de teclado..." << std::endl;
		break;
	}
	glFlush();
}

void Example1::DrawPoint()
{
	glBegin(GL_POINTS);
	glVertex3f(2.0f, 2.0f, 0.0f);
	glEnd();
}

void Example1::DrawLine()
{
	glBegin(GL_LINES);
	glVertex3f(-2.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();
}

void Example1::DrawLineWithColor()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_LINES);
	glVertex3f(-2.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glEnd();
}

void Example1::DrawTriangle()
{
	glBegin(GL_TRIANGLES);
	glVertex3f(0.0f, -2.0f, 0.0f);
	glVertex3f(1.0f, -2.0f, 0.0f);
	glVertex3f(0.5f, -1.0f, 0.0f);
	glEnd();
}

void Example1::DrawLineStrip()
{
	glColor3f(0.0f, 1.0f, 0.0f);

	glBegin(GL_LINE_STRIP);
	glVertex3f(-2.0f, -1.0f, 0.0f);
	glVertex3f(-1.0f, -1.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(2.0f, 0.0f, 0.0f);
	glEnd();

}

void Example1::Draw2DAxis(float lineLength)
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

void Example1::ShowMenu()
{
	std::cout << "Seleccione una opción:" << std::endl;
	std::cout << "a: Dibujar Punto" << std::endl;
	std::cout << "b: Dibujar Línea" << std::endl;
	std::cout << "c: Dibujar Triángulo" << std::endl;
	std::cout << "d: Dibujar Line Strip" << std::endl;
	std::cout << "e: Dibujar Eje 2D" << std::endl;
	std::cout << "f: Dibujar Línea con Color" << std::endl;
	std::cout << "g: Dibujar Eje 3D" << std::endl;
	std::cout << "h: Dibujar Eje 3D con Grilla" << std::endl;
	std::cout << "i: Dibujar Grilla" << std::endl;
	std::cout << "j: Dibujar Poligono de la clase Poligono" << std::endl;
	std::cout << "k: Dibujar Punto de la clase Punto3D" << std::endl;
}

void Example1::KeyboardFunc(unsigned char key, int X, int Y)
{
	currentOption = key;
}

void Example1::Idle()
{

}
#pragma once
#include "Example.h"
#include "Punto3D.h"
#include "Polígono.h"

class Example1: public Example
{
public:
	Example1();
	
	virtual void init()override;
	virtual void Render()override;
	void ShowMenu();
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;

	void DrawPoint();
	void DrawLine();
	void DrawTriangle();
	void DrawLineStrip();
	void Draw2DAxis(float lineLength);
	void DrawLineWithColor();
	Punto3D* point;
	Polígono* polygon; 
};


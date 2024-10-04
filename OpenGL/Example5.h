#pragma once
#include "Example.h"
#include "Vector3.h"
#include "TextureLoader.h"

#include "Cubo.h"
#include "Pirámide.h"
#include "Esfera.h"
#include "Cuadrado.h"
#include "Triangulo.h"
#include "Circulo.h"

#include "Color.h"

class Example5 : public Example
{
	Vector3 pos;
	Vector3 rotation;
	Vector3 scale;

	Color color;

	TextureLoader* _TextureLoader;
	GLuint texture;

	Figura* figura;

public:
	Example5();
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void DrawTriangle(float x, float y, float z);
	void DrawQuad(float x, float y, float z);
	void DrawCube(float size, float x, float y, float z);
	void DrawSphere(float radius, float x, float y, float z);
};

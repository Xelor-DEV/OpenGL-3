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

class Example6 : public Example
{
	Vector3 pos;
	Vector3 rotation;
	Vector3 scale;

	TextureLoader* _TextureLoader;
	GLuint texture;
	GLuint idDisplayList;

	float n;

	Figura* figura;

public:
	Example6();
	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void createDisplayList();
};

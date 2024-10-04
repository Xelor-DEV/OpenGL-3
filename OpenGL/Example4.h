#pragma once
#include "Example.h"
#include "IncludeGL.h"
class Example4 : public Example
{
public:
	Example4();

	virtual void init()override;
	virtual void Render()override;
	void MaterialShadeSmooth();
	void MaterialShadeFlat();
	void SetupMaterialTest();
	void SetupLightingTest();
	void DrawSphere(GLfloat position[3], float radius);
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
};


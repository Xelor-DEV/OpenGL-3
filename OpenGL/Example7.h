#pragma once
#include "Example.h"
#include "IncludeGL.h"
#include <math.h>

class Example7 : public Example
{
public:
	Example7();
	void init();
	void Render();
	void KeyboardFunc(unsigned char key, int X, int Y);
	void Idle();
	void drawCube();
	void drawQuad();
	void drawSphere();
	void drawPyramid();
	void drawCubeWithVertexArray();
	void drawQuadWithIndexedArray();
	void drawPyramidWithInstancing();
};

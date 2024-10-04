#pragma once
#include "Example.h"
#include "Vector3.h"

class Example2 : public Example
{
public:
	Example2();

	virtual void init()override;
	virtual void Render()override;
	virtual void KeyboardFunc(unsigned char key, int X, int Y)override;
	virtual void Idle()override;
	void Draw2DAxis(float lineLength);
	Vector3* translate;
	Vector3* scale;
	Vector3* rotation;
};


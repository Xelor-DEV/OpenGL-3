#pragma once
#include "IncludeGL.h"
#include "Color.h"

class Figura
{
protected:
	GLuint IDTexture;
	char nombre[20];
	int GrosorBorde;
	Color color;
	void EnableTexture();
	void DisableTexture();
public:
	virtual void init();
	virtual void Render();
	void DrawWithColor();
	void RenderWithColor();
	virtual void Draw()=0;
	void SetTexture(GLuint idTexture);
	void SetColor(Color color);

};
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
	GLfloat* vertices;
	int vertexCount;
	GLenum primitiveType;

public:
	virtual void init();
	virtual void Render();
	void DrawWithColor();
	void RenderWithColor();
	virtual void Draw()=0;
	void SetTexture(GLuint idTexture);
	void SetColor(Color color);
	virtual void VertexArray();
	virtual void VertexArrayIndexed();
	virtual void VertexArrayInstanced(int instanceCount);
};
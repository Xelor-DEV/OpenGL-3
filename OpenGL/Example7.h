#pragma once
#include "Example.h"
#include "IncludeGL.h"
#include <math.h>
#include "Vector3.h"

class Example7 : public Example
{
	GLfloat* sphere;
	GLfloat* quad;
	GLfloat* pyramid;
	GLfloat* cube;

	GLfloat pi = 3.1415926535f;

	int sphereVertex;

public:
	Example7();
	void init();
	void Render();
	void KeyboardFunc(unsigned char key, int X, int Y);
	void Idle();
	Vector3* generateSphere();
	void drawWithIndexedArray(GLfloat* vertices, int vertexCount, GLenum primitiveType);
	void drawWithVertexArray(GLfloat* vertices, int vertexCount, GLenum primitiveType);
	void drawInstanced(GLfloat* vertices, int vertexCount, GLenum primitiveType, int instanceCount);
	void drawWithIndexedArray(Vector3* vertices, int vertexCount, GLenum primitiveType);
	void drawWithVertexArray(Vector3* vertices, int vertexCount, GLenum primitiveType);
	void drawInstanced(Vector3* vertices, int vertexCount, GLenum primitiveType, int instanceCount);
};


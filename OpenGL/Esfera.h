#pragma once
#include "Figura3D.h"
#include <math.h>
#include "Vector3.h"

class Esfera : public Figura3D
{
private:
    float pi = 3.1415926535f;
public:
    float radio;
    int slices;
    int stacks;
	Vector3* sphereVertex;

    Esfera(float r , int slices, int stacks);
    void Draw() override;
    Vector3* GenerateVertex();
    float calcularVolumen() override;
    void VertexArray() override;
	void VertexArrayIndexed() override;
	void VertexArrayInstanced(int instanceCount) override;
};
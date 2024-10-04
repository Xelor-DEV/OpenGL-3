#pragma once
class Vector3
{
public:
    float x, y, z;

    // Constructor por defecto
    Vector3();

    // Constructor con parámetros
    Vector3(float x, float y, float z);

    // Suma de vectores
    Vector3 operator+(const Vector3& other) const;

    // Resta de vectores
    Vector3 operator-(const Vector3& other) const;

    // Escalar un vector
    Vector3 operator*(float scalar) const;

    // Sobrecarga del operador +=
    Vector3& operator+=(const Vector3& other);

    Vector3& operator-=(const Vector3& other);

    // Magnitud del vector
    float magnitude() const;

    // Normalizar el vector
    Vector3 normalize() const;

    // Producto punto
    float dot(const Vector3& other) const;

    // Producto cruz
    Vector3 cross(const Vector3& other) const;

    // Multiplicar componente a componente
    Vector3 operator*(const Vector3& other) const;
};
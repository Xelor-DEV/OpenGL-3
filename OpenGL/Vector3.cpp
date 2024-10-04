#include "Vector3.h"
#include <cmath>

// Constructor por defecto
Vector3::Vector3() : x(0), y(0), z(0) {}

// Constructor con parámetros
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

// Suma de vectores
Vector3 Vector3::operator+(const Vector3& other) const
{
    return Vector3(x + other.x, y + other.y, z + other.z);
}

// Resta de vectores
Vector3 Vector3::operator-(const Vector3& other) const
{
    return Vector3(x - other.x, y - other.y, z - other.z);
}

// Escalar un vector
Vector3 Vector3::operator*(float scalar) const
{
    return Vector3(x * scalar, y * scalar, z * scalar);
}

// Magnitud del vector
float Vector3::magnitude() const
{
    return std::sqrt(x * x + y * y + z * z);
}

// Normalizar el vector
Vector3 Vector3::normalize() const
{
    float mag = magnitude();
    return Vector3(x / mag, y / mag, z / mag);
}

// Producto punto
float Vector3::dot(const Vector3& other) const
{
    return x * other.x + y * other.y + z * other.z;
}

// Producto cruz
Vector3 Vector3::cross(const Vector3& other) const
{
    return Vector3(
        y * other.z - z * other.y,
        z * other.x - x * other.z,
        x * other.y - y * other.x
    );
}

// Multiplicar componente a componente
Vector3 Vector3::operator*(const Vector3& other) const
{
    return Vector3(x * other.x, y * other.y, z * other.z);
}

Vector3& Vector3::operator+=(const Vector3& other)
{
    x += other.x;
    y += other.y;
    z += other.z;
    return *this; // Devuelve la referencia al objeto actual
}

Vector3& Vector3::operator-=(const Vector3& other)
{
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this; // Devuelve la referencia al objeto actual
}

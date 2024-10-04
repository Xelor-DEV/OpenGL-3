#include "Color.h"

Color::Color() : r(1.0f), g(1.0f), b(1.0f) {
    // Constructor por defecto: asigna blanco (1.0, 1.0, 1.0) a r, g y b
}

Color::Color(float red, float green, float blue) : r(red), g(green), b(blue) {
    // Constructor con parámetros: asigna los valores proporcionados a r, g y b
}
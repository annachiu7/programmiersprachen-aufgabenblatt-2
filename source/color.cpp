#include "color.hpp"
#include <iostream>

Color::Color(float f) :
r{0.0f},
g{0.0f},
b{0.0f} {}

Color::Color(float x, float y, float z) :
r{x},
g{y},
b{z} {}
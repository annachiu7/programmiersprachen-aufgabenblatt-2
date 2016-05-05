#include "circle.hpp"
#include <iostream>
#include <cmath>

Circle::Circle(float r) :
x_position{0.0},
y_position{0.0},
radius{r} {}

Circle::Circle(float a, float b, float r) :
x_position{a},
y_position{b},
radius{r} {}

float Circle::circumference() const
{
	return 2*M_PI*radius;
}

float Circle::get_x_position() const
{
	return x_position;
}
float Circle::get_y_position() const
{
	return y_position;
}
float Circle::get_radius() const
{
	return radius;
}

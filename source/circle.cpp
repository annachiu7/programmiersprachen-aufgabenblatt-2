#include "circle.hpp"
#include <iostream>
#include <cmath>
#include "color.hpp"

Circle::Circle(float r) :
x_position{0.0},
y_position{0.0},
radius{r},
clr_{0.0} {}

Circle::Circle(float a, float b, float r, Color const& clr) :
x_position{a},
y_position{b},
radius{r},
clr_{clr} {}

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
Color Circle::get_Color() const&
{
	return clr_;
}
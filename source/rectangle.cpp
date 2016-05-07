#include "rectangle.hpp"
#include <iostream>
#include "color.hpp"

Rectangle::Rectangle(float w, float h) :
x_start{0.0},
y_start{0.0},
width{w},
height{h},
clr_{0.0} {}


Rectangle::Rectangle(float x, float y, float w, float h, Color const& clr) :
x_start{x},
y_start{y},
width{w},
height{h},
clr_{clr} {}

float Rectangle::circumference() const
{
	return 2*(width+height);
}

float Rectangle::get_x_start() const
{
	return x_start;
}
float Rectangle::get_y_start() const
{
	return y_start;
}
float Rectangle::get_width() const
{
	return width;
}
float Rectangle::get_height() const
{
	return height;
}
Color Rectangle::get_Color() const&
{
	return clr_;
}
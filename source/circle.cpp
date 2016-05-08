#include "circle.hpp"
#include <iostream>
#include <cmath>
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include <utility>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

Circle::Circle(float r) :
x_position{0.0},
y_position{0.0},
radius{r},
clr_{0.0},
center_{0.0, 0.0} {}

Circle::Circle(float a, float b, float r, Color const& clr) :
x_position{a},
y_position{b},
radius{r},
clr_{clr},
center_{a, b} {}



float Circle::circumference() const
{
	return 2*M_PI*radius;
}


// getter
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
Vec2 Circle::get_Center() const&
{
	return center_;
}

// setter(color)
void Circle::set_Color(Color const& clr)
{
	clr_ = clr;
}

// draw-method
void Circle::draw(Window const& win) const
{
	for (int i = 0; i <= 360 ; ++i)
	{	
		Vec2 begin_point = make_rotation_mat2(2*M_PI*i/360) * Vec2(get_radius(),0) + get_Center();
		Vec2 end_point = make_rotation_mat2(2*M_PI*(i+1)/360) * Vec2(get_radius(),0) + get_Center();
		win.draw_line(begin_point.x, begin_point.y, end_point.x, end_point.y, 0, 0, 0);
	}
}


// draw-method with color
void Circle::draw(Window const& win, Color const& clr) const
{
	for (int i = 0; i <= 360 ; ++i)
	{
		Vec2 begin_point = make_rotation_mat2(2*M_PI*i/360) * Vec2(get_radius(),0) + get_Center();
		Vec2 end_point = make_rotation_mat2(2*M_PI*(i+1)/360) * Vec2(get_radius(),0) + get_Center();
		win.draw_line(begin_point.x, begin_point.y, end_point.x, end_point.y, clr.r, clr.g, clr.b);
	}
}


//is_inside
bool Circle::is_inside(Vec2 const& point) const
{
	if (sqrt((point.x - get_Center().x)*(point.x - get_Center().x)
			+(point.y - get_Center().y)*(point.y - get_Center().y)) <= get_radius())
	{
		return true;
	}
	return false;
}
#include "rectangle.hpp"
#include <iostream>
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"
#include "vec2.hpp"

Rectangle::Rectangle(float w, float h) :
x_start{0.0},
y_start{0.0},
width{w},
height{h},
clr_{0.0},
startPoint_{0.0,0.0} {}


Rectangle::Rectangle(float x, float y, float w, float h, Color const& clr) :
x_start{x},
y_start{y},
width{w},
height{h},
clr_{clr},
startPoint_{x,y} {}



float Rectangle::circumference() const
{
	return 2*(width+height);
}


// getter
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
Vec2 Rectangle::get_StartPoint() const&
{
	return startPoint_;
}

// setter(color)
void Rectangle::set_Color(Color const& clr)
{
	clr_ = clr;
}


// draw-method
void Rectangle::draw(Window const& win) const
{
	Vec2 point1 = get_StartPoint();
	Vec2 point2 = point1 + Vec2(0,get_height());
	Vec2 point3 = point2 + Vec2(get_width(),0);
	Vec2 point4 = point1 + Vec2(get_width(),0);

	win.draw_line(point1.x, point1.y, point2.x, point2.y, 0.0, 0.0, 0.0);
	win.draw_line(point2.x, point2.y, point3.x, point3.y, 0.0, 0.0, 0.0);
	win.draw_line(point3.x, point3.y, point4.x, point4.y, 0.0, 0.0, 0.0);
	win.draw_line(point4.x, point4.y, point1.x, point1.y, 0.0, 0.0, 0.0);
}

// draw-method with color
void Rectangle::draw(Window const& win, Color const& clr) const
{
	Vec2 point1 = get_StartPoint();
	Vec2 point2 = point1 + Vec2(0,get_height());
	Vec2 point3 = point2 + Vec2(get_width(),0);
	Vec2 point4 = point1 + Vec2(get_width(),0);

	win.draw_line(point1.x, point1.y, point2.x, point2.y, clr.r, clr.g, clr.b);
	win.draw_line(point2.x, point2.y, point3.x, point3.y, clr.r, clr.g, clr.b);
	win.draw_line(point3.x, point3.y, point4.x, point4.y, clr.r, clr.g, clr.b);
	win.draw_line(point4.x, point4.y, point1.x, point1.y, clr.r, clr.g, clr.b);
}

//is_inside
bool Rectangle::is_inside(Vec2 const& point) const
{
	Vec2 start = get_StartPoint();
	if ((start.x <= point.x) && (point.x <= start.x + get_width()) 
		&& (start.y <= point.y) && (point.y <= start.y + get_height()))
	{
		return true;
	}
	return false;
}
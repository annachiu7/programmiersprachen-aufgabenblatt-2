#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"
#include "vec2.hpp"

class Rectangle
{
public:
	Rectangle(float w, float h);
	Rectangle(float x, float y, float w, float h, Color const& clr);
	
	float circumference() const;
	
	float get_x_start() const;
	float get_y_start() const;
	float get_width() const;
	float get_height() const;
	Color get_Color() const&;
	Vec2 get_StartPoint() const&;

	void draw_line(Window const& win) const;
	void draw_line(Window const& win, Color const& clr) const;

private:
	float x_start;
	float y_start;
	float width;
	float height;
	Color clr_;
	Vec2 startPoint_;
};


#endif
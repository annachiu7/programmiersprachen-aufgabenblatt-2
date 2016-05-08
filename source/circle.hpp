#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "window.hpp"
#include "mat2.hpp"
#include "vec2.hpp"

class Circle
{
public:
	Circle(float r);
	Circle(float a, float b, float r, Color const& clr);

	float circumference() const;
	//getter
	float get_x_position() const;
	float get_y_position() const;
	float get_radius() const;
	Color get_Color() const&;
	Vec2 get_Center() const&;
	//setter
	void set_Color(Color const& clr);
	
	void draw(Window const& win) const;
	void draw(Window const& win, Color const& clr) const;

	bool is_inside(Vec2 const& point) const;

private:
	float x_position;
	float y_position;
	float radius;
	Color clr_;
	Vec2 center_;
};


#endif 
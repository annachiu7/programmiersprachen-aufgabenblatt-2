#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"

class Circle
{
public:
	Circle(float r);
	Circle(float a, float b, float r, Color const& clr);
	Color color() const;
	float circumference() const;
	float get_x_position() const;
	float get_y_position() const;
	float get_radius() const;
	Color get_Color() const&;

private:
	float x_position;
	float y_position;
	float radius;
	Color clr_;
};


#endif 
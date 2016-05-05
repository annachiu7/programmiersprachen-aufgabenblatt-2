#ifndef CIRCLE_HPP
#define CIRCLE_HPP

class Circle
{
public:
	Circle(float r);
	Circle(float a, float b, float r);
	float circumference() const;
	float get_x_position() const;
	float get_y_position() const;
	float get_radius() const;

private:
	float x_position;
	float y_position;
	float radius;
};


#endif 
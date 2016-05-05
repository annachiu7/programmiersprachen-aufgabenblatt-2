#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

class Rectangle
{
public:
	Rectangle(float w, float h);
	Rectangle(float x, float y, float w, float h);
	float circumference() const;
	float get_x_start() const;
	float get_y_start() const;
	float get_width() const;
	float get_height() const;

private:
	float x_start;
	float y_start;
	float width;
	float height;
};


#endif
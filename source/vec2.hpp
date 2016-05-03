#ifndef VEC2_HPP
#define VEC2_HPP

class Vec2
{
public:
	Vec2();
	Vec2(float a, float b);

	float x;
	float y;

	Vec2& operator+=(Vec2 const& v);
	Vec2& operator-=(Vec2 const& v);
	Vec2& operator*=(float v);
	Vec2& operator/=(float v);

};



#endif
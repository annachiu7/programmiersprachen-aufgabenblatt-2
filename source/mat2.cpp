#include "mat2.hpp"
#include <iostream>

Mat2::Mat2() :
a1{1},
a2{0},
b1{0},
b2{1}
{}

Mat2::Mat2(int a, int b, int c, int d) :
a1{a},
a2{b},
b1{c},
b2{d}
{}

/////////////////////////////////////////////////////////

Mat2& Mat2::operator *=( Mat2 const & m )
{
	a1 = a1*m.a1+a2*m.b1;
	a2 = a1*m.a2+a2*m.b2;
	b1 = b1*m.a1+b2*m.b1;
	b2 = b1*m.a2+b2*m.b2;
	return *this;
}

////////////////////////////////////////////////////////

Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 )
{
	return Mat2{m1.a1*m2.a1+m1.a2*m2.b1, 
				m1.a1*m2.a2+m1.a2*m2.b2, 
				m1.b1*m2.a1+m1.b2*m2.b1,
				m1.b1*m2.a2+m1.b2*m2.b2};
}
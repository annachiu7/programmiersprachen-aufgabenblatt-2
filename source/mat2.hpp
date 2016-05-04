#ifndef MAT2_HPP
#define MAT2_HPP

// Mat2 class definition
class Mat2
{
public:
	Mat2();  // default constructor
	Mat2(int a, int b, int c, int d);  // user constructor

	int a1;
	int a2;
	int b1;
	int b2;

	Mat2& operator *=( Mat2 const & m );

};

Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 );

#endif
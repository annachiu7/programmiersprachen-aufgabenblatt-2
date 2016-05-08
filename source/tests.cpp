#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"
#include "mat2.hpp"
#include <cmath>
#include "circle.hpp"
#include "rectangle.hpp"

TEST_CASE("describe_vec2","[create_vec2]") 
{ 
	Vec2 v1;
	Vec2 v2{2.0f, 1.0f};
	REQUIRE(v1.x == Approx(0.0f)); 
	REQUIRE(v1.y == Approx(0.0f)); 
	REQUIRE(v2.x == Approx(2.0f)); 
	REQUIRE(v2.y == Approx(1.0f));
} 

TEST_CASE("describe_vec2_andoperator","[operator_vec2]") 
{ 
	Vec2 v1{1.0f, 1.0f};
	Vec2 v2{2.0f, 1.0f};
	v1+=(v2);
	REQUIRE(v1.x == Approx(3.0f)); 
	REQUIRE(v1.y == Approx(2.0f)); 
	v1+=(v2);
	REQUIRE(v1.x == Approx(5.0f)); 
	REQUIRE(v1.y == Approx(3.0f)); 

	v1-=(v2);
	REQUIRE(v1.x == Approx(3.0f)); 
	REQUIRE(v1.y == Approx(2.0f)); 
	v1-=(v2);
	REQUIRE(v1.x == Approx(1.0f)); 
	REQUIRE(v1.y == Approx(1.0f)); 

	float v=0.0f;
	v1*=v;
	REQUIRE(v1.x == Approx(0.0f)); 
	REQUIRE(v1.y == Approx(0.0f)); 

	float s=1.0f;
	v2/=s; 
	REQUIRE(v2.x == Approx(2.0f)); 
	REQUIRE(v2.y == Approx(1.0f)); 
} 

TEST_CASE("describe_vec2_operator","[opr_vec2]") 
{ 
	Vec2 v1;
	Vec2 v2{2.0f, 1.0f};
	Vec2 v3 = v1 + v2;
	REQUIRE(v3.x == Approx(2.0f)); 
	REQUIRE(v3.y == Approx(1.0f)); 
	Vec2 v4 = v3 + v2;
	REQUIRE(v4.x == Approx(4.0f)); 
	REQUIRE(v4.y == Approx(2.0f));

	Vec2 v5 = v1 - v2;
	REQUIRE(v5.x == Approx(-2.0f)); 
	REQUIRE(v5.y == Approx(-1.0f)); 
	Vec2 v6 = v4 - v2;
	REQUIRE(v6.x == Approx(2.0f)); 
	REQUIRE(v6.y == Approx(1.0f)); 

	float s = 3.0f;
	Vec2 v7 = v1 * s;
	REQUIRE(v7.x == Approx(0.0f)); 
	REQUIRE(v7.y == Approx(0.0f)); 
	Vec2 v8 = v2 * s;
	REQUIRE(v8.x == Approx(6.0f)); 
	REQUIRE(v8.y == Approx(3.0f)); 

	Vec2 v9 = v1 / s;
	REQUIRE(v9.x == Approx(0.0f)); 
	REQUIRE(v9.y == Approx(0.0f)); 
	Vec2 v10 = v8 / s;
	REQUIRE(v10.x == Approx(2.0f)); 
	REQUIRE(v10.y == Approx(1.0f)); 

	Vec2 v11 = s * v1;
	REQUIRE(v11.x == Approx(0.0f)); 
	REQUIRE(v11.y == Approx(0.0f)); 
}

TEST_CASE("describe_mat2","[create_mat2]") 
{ 
	Mat2 m_einheit;
	Mat2 m1{1.0f,1.0f,1.0f,1.0f};
	Mat2 m2{1.0f,2.0f,3.0f,4.0f};
	REQUIRE(m1.a == 1.0f); 
	REQUIRE(m1.b == 1.0f); 
	REQUIRE(m1.c == 1.0f);
	REQUIRE(m1.d == 1.0f); 
	REQUIRE(m_einheit.a == 1.0f); 
	REQUIRE(m_einheit.b == 0.0f); 
	REQUIRE(m_einheit.c == 0.0f);
	REQUIRE(m_einheit.d == 1.0f); 
	REQUIRE(m2.a == 1.0f); 
	REQUIRE(m2.b == 2.0f); 
	REQUIRE(m2.c == 3.0f);
	REQUIRE(m2.d == 4.0f); 
}

TEST_CASE("describe_mult_mrf_mat2","[mult_mrf_mat2]") 
{ 
	Mat2 m_einheit;
	Mat2 m1{1.0f,1.0f,1.0f,1.0f};
	m1*=m_einheit;
	REQUIRE(m1.a == 1.0f); 
	REQUIRE(m1.b == 1.0f); 
	REQUIRE(m1.c == 1.0f); 
	REQUIRE(m1.d == 1.0f); 
	m1*=m1;
	REQUIRE(m1.a == 2.0f); 
	REQUIRE(m1.b == 2.0f); 
	REQUIRE(m1.c == 2.0f); 
	REQUIRE(m1.d == 2.0f); 
}


TEST_CASE("describe_mult_mat2","[mult_mat2]") 
{ 
	Mat2 m_einheit;
	Mat2 m1{1.0f,1.0f,1.0f,1.0f};
	Mat2 m2{1.0f,2.0f,3.0f,4.0f};
	Mat2 m3 = m_einheit * m1;
	REQUIRE(m3.a == 1.0f); 
	REQUIRE(m3.b == 1.0f); 
	REQUIRE(m3.c == 1.0f); 
	REQUIRE(m3.d == 1.0f); 
	Mat2 m4 = m_einheit * m2;
	REQUIRE(m4.a == 1.0f); 
	REQUIRE(m4.b == 2.0f); 
	REQUIRE(m4.c == 3.0f); 
	REQUIRE(m4.d == 4.0f); 
	Mat2 m5 = m1 * m2;
	REQUIRE(m5.a == 4.0f); 
	REQUIRE(m5.b == 6.0f); 
	REQUIRE(m5.c == 4.0f); 
	REQUIRE(m5.d == 6.0f); 
	Mat2 m6 = m2 * m1;
	REQUIRE(m6.a == 3.0f); 
	REQUIRE(m6.b == 3.0f); 
	REQUIRE(m6.c == 7.0f); 
	REQUIRE(m6.d == 7.0f); 
}

TEST_CASE("describe_mat2_det","[determinant_mat2]") 
{ 
	Mat2 m_einheit;
	Mat2 m1{1.0f,1.0f,1.0f,1.0f};
	Mat2 m2{1.0f,2.0f,3.0f,4.0f};
	REQUIRE(m_einheit.det() == Approx(1));
	REQUIRE(m1.det() == Approx(0));
	REQUIRE(m2.det() == Approx(-2));
}

TEST_CASE("describe_mat2_mult_vec2","[mat2_mult_vec2]") 
{ 
	Mat2 m_einheit;
	Mat2 m1{1.0f,1.0f,1.0f,1.0f};
	Vec2 v1{1.0f, 1.0f};
	Vec2 v2 = m_einheit*v1;
	REQUIRE(v2.x == Approx(1.0f)); 
	REQUIRE(v2.y == Approx(1.0f)); 
	Vec2 v3 = m1*v1;
	REQUIRE(v3.x == Approx(2.0f)); 
	REQUIRE(v3.y == Approx(2.0f)); 
} 

TEST_CASE("describe_inverse_mat","[mat2_inverse]") 
{ 
	Mat2 m_einheit;
	Mat2 m1{2.0f,5.0f,1.0f,3.0f};
	Mat2 m2{1,1,1,1};
	REQUIRE(inverse(m_einheit).a == Approx(1.0f)); 
	REQUIRE(inverse(m_einheit).b == Approx(0.0f)); 
	REQUIRE(inverse(m_einheit).c == Approx(0.0f)); 
	REQUIRE(inverse(m_einheit).d == Approx(1.0f)); 
	REQUIRE(inverse(m1).a == Approx(3.0f)); 
	REQUIRE(inverse(m1).b == Approx(-5.0f)); 
	REQUIRE(inverse(m1).c == Approx(-1.0f)); 
	REQUIRE(inverse(m1).d == Approx(2.0f)); 
	REQUIRE(inverse(m2).a == Approx(0)); 
	REQUIRE(inverse(m2).b == Approx(0)); 
	REQUIRE(inverse(m2).c == Approx(0)); 
	REQUIRE(inverse(m2).d == Approx(0)); 
} 

TEST_CASE("describe_mat2_transpose","[mat2_trans]") 
{ 
	Mat2 m_einheit;
	Mat2 m1{-1.0f,2.0f,3.0f,4.0f};
	REQUIRE(transpose(m_einheit).a == Approx(1)); 
	REQUIRE(transpose(m_einheit).b == Approx(0)); 
	REQUIRE(transpose(m_einheit).c == Approx(0)); 
	REQUIRE(transpose(m_einheit).d == Approx(1)); 
	REQUIRE(transpose(m1).a == Approx(-1)); 
	REQUIRE(transpose(m1).b == Approx(3)); 
	REQUIRE(transpose(m1).c == Approx(2)); 
	REQUIRE(transpose(m1).d == Approx(4)); 
} 

TEST_CASE("describe_mat2_rotation","[mat2_rotation]") 
{ 
	Mat2 m = make_rotation_mat2(M_PI/2);
	REQUIRE(m.a == Approx(0)); 
	REQUIRE(m.b == Approx(-1)); 
	REQUIRE(m.c == Approx(1)); 
	REQUIRE(m.d == Approx(0)); 
	Mat2 m1 = make_rotation_mat2(M_PI);
	REQUIRE(m1.a == Approx(-1)); 
	REQUIRE(m1.b == Approx(0)); 
	REQUIRE(m1.c == Approx(0)); 
	REQUIRE(m1.d == Approx(-1)); 
	Mat2 m2 = make_rotation_mat2(M_PI/6);
	REQUIRE(m2.a == Approx(0.86603f)); 
	REQUIRE(m2.b == Approx(-0.5)); 
	REQUIRE(m2.c == Approx(0.5)); 
	REQUIRE(m2.d == Approx(0.86603f)); 
} 
/*
TEST_CASE("describe_circle","[create_circle]") 
{ 
	Circle c{5};
	Circle clr{1,1,3,{0.5,0.6,0.7}};
	REQUIRE(c.get_x_position() == Approx(0.0)); 
	REQUIRE(c.get_y_position() == Approx(0.0)); 
	REQUIRE(c.get_radius() == Approx(5.0)); 
	REQUIRE(clr.get_x_position() == Approx(1.0)); 
	REQUIRE(clr.get_y_position() == Approx(1.0)); 
	REQUIRE(clr.get_radius() == Approx(3.0)); 
	REQUIRE(clr.get_Color().r == Approx(0.5)); 
} 

TEST_CASE("describe_rectangle","[create_rectangle]") 
{ 
	Rectangle rec{5, 8};
	Rectangle rec2{-3, 7, 4, 6, {0.0}};
	REQUIRE(rec.get_x_start() == Approx(0)); 
	REQUIRE(rec.get_y_start() == Approx(0)); 
	REQUIRE(rec.get_width() == Approx(5)); 
	REQUIRE(rec.get_height() == Approx(8)); 
	REQUIRE(rec2.get_x_start() == Approx(-3)); 
	REQUIRE(rec2.get_y_start() == Approx(7));
	REQUIRE(rec2.get_width() == Approx(4)); 
	REQUIRE(rec2.get_height() == Approx(6)); 
} 

TEST_CASE("describe_circumference_circle","[circumference_circle]") 
{ 
	Circle c{5};
	Circle clr{1,1,3,{0.0}};
	REQUIRE(c.circumference() == Approx(2*M_PI*5)); 
	REQUIRE(clr.circumference() == Approx(2*M_PI*3)); 
} 

TEST_CASE("describe_circumference_rec","[circumference_rec]") 
{ 
	Rectangle rec{3,4};
	Rectangle rec2{3,3,5,5,{0.0}};
	REQUIRE(rec.circumference() == Approx(14)); 
	REQUIRE(rec2.circumference() == Approx(20)); 
} 

TEST_CASE("describe_is_inside_circle", "[is_inside_circle]")
{
	Circle c{5};
	Circle clr{1,1,3,{0.0}};
	Vec2 v1{};
	Vec2 v2{5.0,0.0};
	REQUIRE(c.is_inside(v1) == true);
	REQUIRE(c.is_inside(v2) == true);
	REQUIRE(clr.is_inside(v1) == true);
	REQUIRE(clr.is_inside(v2) == false);
}

TEST_CASE("describe_is_inside_rec", "[is_inside_rec]")
{
	Rectangle rec1{3,2};
	Rectangle rec2{5,8,1,2,{0.0}};
	Vec2 v1{};
	Vec2 v2{9.0,9.0};
	Vec2 v3{6.0,8.0};
	REQUIRE(rec1.is_inside(v1) == true);
	REQUIRE(rec1.is_inside(v2) == false);
	REQUIRE(rec2.is_inside(v1) == false);
	REQUIRE(rec2.is_inside(v2) == false);
	REQUIRE(rec2.is_inside(v3) == true);
}

*/
int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "vec2.hpp"

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
	Vec2 v3 = v1+=(v2);
	REQUIRE(v3.x == Approx(3.0f)); 
	REQUIRE(v3.y == Approx(2.0f)); 
	Vec2 v3_2 = v3+=(v2);
	REQUIRE(v3_2.x == Approx(5.0f)); 
	REQUIRE(v3_2.y == Approx(3.0f)); 

	Vec2 v4 = v1-=(v2);
	REQUIRE(v4.x == Approx(-1.0f)); 
	REQUIRE(v4.y == Approx(0.0f));
	Vec2 v4_2 = v3-=(v2);
	REQUIRE(v4_2.x == Approx(1.0f)); 
	REQUIRE(v4_2.y == Approx(1.0f));

	float v = 3.0f;
	Vec2 v5 = v2*=(v);
	REQUIRE(v5.x == Approx(6.0f)); 
	REQUIRE(v5.y == Approx(3.0f)); 
	Vec2 v5_2 = v1*=(v);
	REQUIRE(v5_2.x == Approx(3.0f)); 
	REQUIRE(v5_2.y == Approx(3.0f)); 

	Vec2 v6 = v5/=(v);
	REQUIRE(v6.x == Approx(2.0f)); 
	REQUIRE(v6.y == Approx(1.0f)); 
	Vec2 v6_2 = v5_2/=(v);
	REQUIRE(v6_2.x == Approx(1.0f)); 
	REQUIRE(v6_2.y == Approx(1.0f)); 
} 

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}

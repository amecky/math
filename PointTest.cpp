#include "catch.hpp"
#include "Point.h"

TEST_CASE("Add","[point]") {
	Point2f p(1.0f,2.0f);
	Point2f c = p + Point2f(3.0f,3.0f);
	REQUIRE( c.x == 4.0f) ;
	REQUIRE( c.y == 5.0f) ;
}

TEST_CASE("Mul","[point]") {
	Point2f p(3.0f,2.0f);
	Point2f m = p * Point2f(3.0f,3.0f);
	REQUIRE( m.x == 9.0f) ;
	REQUIRE( m.y == 6.0f) ;
}
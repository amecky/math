#include "catch.hpp"
#include "Vector.h"

TEST_CASE("Constructor-V2","[Vector]") {
	Vector2i a;
	REQUIRE( a.x == 0 );
	REQUIRE( a.y == 0 );

	Vector2i b(2);
	REQUIRE( b.x == 2 );
	REQUIRE( b.y == 2 );

	Vector2i c(2,3);
	REQUIRE( c.x == 2 );
	REQUIRE( c.y == 3 );

	Vector2i d(b);
	REQUIRE( d.x == 2 );
	REQUIRE( d.y == 2 );

	int ar[] = {4,5};
	Vector2i e(ar);
	REQUIRE( e.x == 4 );
	REQUIRE( e.y == 5 );

	REQUIRE( e[0] == 4 );
	REQUIRE( e[1] == 5 );

	int* v = e();
	REQUIRE( *v == 4 );
	++v;
	REQUIRE( *v == 5 );
}




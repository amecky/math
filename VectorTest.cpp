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

TEST_CASE("Lerp","[Vector]") {
	Vector3f a(2.0f,8.0,-2.0f);
	Vector3f b (3.0f,2.0f,4.0f);
	Vector3f c = lerp(a,b,0.5f);
	REQUIRE( c.x == 2.5f );
	REQUIRE( c.y == 5.0f );
	REQUIRE( c.z == 1.0f );
}

TEST_CASE("LerpRange","[Vector]") {
	Vector3f a(2.0f,8.0,-2.0f);
	Vector3f b (3.0f,2.0f,4.0f);
	Vector3f c = lerp(a,b,2.5f);
	REQUIRE( c.x == 3.0f );
	REQUIRE( c.y == 2.0f );
	REQUIRE( c.z == 4.0f );
}

TEST_CASE("Vec_Min","[Vector]") {
	Vector3f a(2.0f,8.0,-2.0f);
	Vector3f b (3.0f,2.0f,4.0f);
	Vector3f c = vec_min(a,b);
	REQUIRE( c.x == 2.0f );
	REQUIRE( c.y == 2.0f );
	REQUIRE( c.z == -2.0f );
}

TEST_CASE("Vec_Max","[Vector]") {
	Vector3f a(2.0f,8.0,-2.0f);
	Vector3f b (3.0f,2.0f,4.0f);
	Vector3f c = vec_max(a,b);
	REQUIRE( c.x == 3.0f );
	REQUIRE( c.y == 8.0f );
	REQUIRE( c.z == 4.0f );
}

TEST_CASE("Clamp","[Vector]") {
	Vector3f a(2.0f,8.0,-2.0f);
	Vector3f b = clamp(a,Vector3f(1.0f),Vector3f(4.0f));
	REQUIRE( b.x == 2.0f );
	REQUIRE( b.y == 4.0f );
	REQUIRE( b.z == 1.0f );
}

TEST_CASE("Saturate","[Vector]") {
	Vector3f a(2.0f,8.0,-2.0f);
	Vector3f b = saturate(a);
	REQUIRE( b.x == 1.0f );
	REQUIRE( b.y == 1.0f );
	REQUIRE( b.z == 0.0f );
}

TEST_CASE("Cross","[Vector]") {
	Vector3f a = cross(Vector3f(1.0f,0.0f,0.0f),Vector3f(0.0f,1.0f,0.0f));
	REQUIRE( a.x == 0.0f );
	REQUIRE( a.y == 0.0f );
	REQUIRE( a.z == 1.0f );

	Vector3f tmp;
	cross(Vector3f(1.0f,0.0f,0.0f),Vector3f(0.0f,1.0f,0.0f),&tmp);
	REQUIRE( tmp.x == 0.0f );
	REQUIRE( tmp.y == 0.0f );
	REQUIRE( tmp.z == 1.0f );
}




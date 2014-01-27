#include "catch.hpp"
#include "IPath.h"
#include "Vector.h"

TEST_CASE("BasicConst","[IPath]") {
	IPath<10,float> p;
	p.add(0.0f,1.0f);
	p.add(0.5f,2.0f);
	p.add(1.0f,3.0f);
	REQUIRE( p.size() == 3 );

}

TEST_CASE("V2Path","[IPath]") {
	IPath<10,Vector2f> p;
	p.add(0.0f,Vector2f(1.0f,1.0f));
	p.add(0.5f,Vector2f(2.0f,2.0f));
	p.add(1.0f,Vector2f(3.0f,3.0f));
	Vector2f f;
	bool ret = p.get(0.25f,&f);
	REQUIRE( ret == true );
	REQUIRE( f.x == 1.5f );
	REQUIRE( f.y == 1.5f );

	p.get(0.75f,&f);
	REQUIRE( ret == true );
	REQUIRE( f.x == 2.5f );
	REQUIRE( f.y == 2.5f );

	p.get(1.25f,&f);
	REQUIRE( ret == true );
	REQUIRE( f.x == 3.0f );
	REQUIRE( f.y == 3.0f );

}

TEST_CASE("V2Path-Step","[IPath]") {
	IPath<10,Vector2f> p;
	p.add(0.0f,Vector2f(1.0f,1.0f));
	p.add(0.5f,Vector2f(2.0f,2.0f));
	p.add(1.0f,Vector2f(3.0f,3.0f));
	p.setInterpolationMode(PI_STEP);
	Vector2f f;
	bool ret = p.get(0.25f,&f);
	REQUIRE( ret == true );
	REQUIRE( f.x == 1.0f );
	REQUIRE( f.y == 1.0f );

	p.get(0.75f,&f);
	REQUIRE( ret == true );
	REQUIRE( f.x == 2.0f );
	REQUIRE( f.y == 2.0f );

	p.get(1.25f,&f);
	REQUIRE( ret == true );
	REQUIRE( f.x == 3.0f );
	REQUIRE( f.y == 3.0f );

}
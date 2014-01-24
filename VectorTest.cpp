#include "catch.hpp"

#include "Vector.h"

TEST_CASE("InstantiateEmpty","Vector") {
    v2i a;
    REQUIRE( a.x == 0 );
    REQUIRE( a.y == 0 );
    
    v3f b;
    REQUIRE( b.x == 0.0f );
    REQUIRE( b.y == 0.0f );
    REQUIRE( b.z == 0.0f );
}

TEST_CASE("InstantiatePtr","Vector") {
    int array[] = {2,3};
    v2i a(array);
    REQUIRE( a.x == 2 );
    REQUIRE( a.y == 3 );    
}

TEST_CASE("InstantiateOneValue","Vector") {
    v2i a(1);
    REQUIRE( a.x == 1 );
    REQUIRE( a.y == 1 );
    
    v3f b(1.0f);
    REQUIRE( b.x == 1.0f );
    REQUIRE( b.y == 1.0f );
    REQUIRE( b.z == 1.0f );
}

TEST_CASE("InstantiateTwoValue","Vector") {
    v2i a(1,2);
    REQUIRE( a.x == 1 );
    REQUIRE( a.y == 2 );
    
    v3f b(1.0f,2.0f,3.0f);
    REQUIRE( b.x == 1.0f );
    REQUIRE( b.y == 2.0f );
    REQUIRE( b.z == 3.0f );
}

TEST_CASE("BasicAdd","Vector") {
    v2i a(1);
    v2i b(2);
    v2i r = a + b;
    REQUIRE( r.x == 3 );
    REQUIRE( r.y == 3 );
    
    v3f v(1.0f,2.0f,3.0f);
    v3f u(3.0f,4.0f,5.0f);
    v += u;
    REQUIRE( v.x == 4.0f );
    REQUIRE( v.y == 6.0f );
    REQUIRE( v.z == 8.0f );
}

TEST_CASE("Dot3","Vector") {
    v3f a(1.0f,0.0f,0.0f);
    v3f b(1.0f,1.0f,0.0f);
    float c = dot(a,b);    
    REQUIRE( c == 1.0f );
}

TEST_CASE("Equals2","Vector") {
    v2i a(1,2);
    v2i b(1,2);
    REQUIRE( a == b );
    b.x = 3;
    REQUIRE( a != b );
}

TEST_CASE("Length","Vector") {    
    v3f b(1.0f,1.0f,0.0f);
    float l = length(b);
    REQUIRE( l == Approx(1.41421f) );
}

TEST_CASE("Clamp","Vector") {    
    v3f b(4.0f,5.0f,0.0f);
    v3f n = clamp(b,v3f(1.0f),v3f(2.0f));
    REQUIRE( n.x == 2.0f );
    REQUIRE( n.y == 2.0f );
    REQUIRE( n.z == 1.0f );
}

TEST_CASE("Saturate","Vector") {    
    v3f b(4.0f,5.0f,-5.0f);
    v3f n = saturate(b);
    REQUIRE( n.x == 1.0f );
    REQUIRE( n.y == 1.0f );
    REQUIRE( n.z == 0.0f );
}

TEST_CASE("Identity22","Matrix") {
    mat22i m;
    identity(m);
    REQUIRE( m.m11 == 1 );
    REQUIRE( m.m12 == 0 );
    REQUIRE( m.m21 == 0 );
    REQUIRE( m.m22 == 1 );
}

TEST_CASE("Identity33","Matrix") {
    mat33 m;
    identity(m);
    REQUIRE( m.m11 == 1.0f );
    REQUIRE( m.m12 == 0.0f );
    REQUIRE( m.m21 == 0.0f );
    REQUIRE( m.m22 == 1.0f );
    REQUIRE( m.m33 == 1.0f );
}

TEST_CASE("Mul","Matrix") {
    mat33 m;
    identity(m);
    mat33 w(2.0f);
    mat33 a = m * w;
    REQUIRE( a.m11 == 2.0f );
    REQUIRE( a.m12 == 2.0f );
    REQUIRE( a.m21 == 2.0f );
    REQUIRE( a.m22 == 2.0f );
    REQUIRE( a.m33 == 2.0f );
}

TEST_CASE("VecMul","Matrix") {
    mat33 m;
    identity(m);
    v3f v(2.0f,3.0f,4.0f);
    v3f u = m * v;
    REQUIRE( u.x == 2.0f );
    REQUIRE( u.y == 3.0f );
    REQUIRE( u.z == 4.0f );
}

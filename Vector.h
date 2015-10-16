//-------------------------------------------------------------------------
//
// File:		Vector.h
// Desc:		A template vector implementation
// Author:		amecky <amecky@gmail.com>
// License:     BSD - do whatever you want
//
//-------------------------------------------------------------------------
#pragma once
#include <cmath>
#include <iostream>
//! Basic Vector template
/*! This is the basic template defining only the array of data.
	The size and the class needs to be defined.
*/
template<int Size,class T>
struct Vector {

	typedef T Type; //!< The actual type

	T data[Size]; //!< Internal array of values

};

//! Specialized template version for size 2
/*!	
*/
template <class T> 
struct Vector<2,T> { 
	union { 
		T data[2]; 
		struct { 
			T x, y; 
		};       
	}; 	
	//! Default constructor. Setting x and y to 0
	Vector<2,T>() : x(0) , y(0) {}
	//! Constructor setting x and y to given value
	explicit Vector<2,T>(T t) : x(t) , y(t) {}
	//! Constructor setting x and y to given values
	Vector<2,T>(T xv,T yv) : x(xv) , y(yv) {}
	//! Copy constructor.
	Vector<2,T>(const Vector<2,int>& other) : x(other.x) , y(other.y) {}
	//! Constructor taking x and y from the given array
	Vector<2,T>(const T* value) {
		x = *value;
		++value;
		y = *value;
	}	
	const T& operator[] (int idx) const { return data[idx];}
	T& operator[] (int idx) { return data[idx]; }
	//! Conversion operator returning a pointer to internal data
	T* operator() () {
		return &data[0];
	}
	//! assignment operator
	Vector<2,T>& operator = (const Vector<2,T>& other) {
		x = other.x;
		y = other.y;
		return *this;
	}
};

//! Specialized template for size 3
template <class T> 
struct Vector<3,T> { 
	union { 
		T data[3]; 
		struct { 
			T x, y, z; 
		};       
	}; 

	Vector<3,T>() : x(0.0f) , y(0.0f) , z(0.0f) {}
	explicit Vector<3,T>(T t) : x(t) , y(t) , z(t) {}
	Vector<3,T>(T xv,T yv,T zv) : x(xv) , y(yv) , z(zv) {}
	Vector<3,T>(const Vector<2,T>& other,T tz) : x(other.x) , y(other.y) , z(tz) {}
	Vector<3,T>(const Vector<3,T>& other) : x(other.x) , y(other.y) , z(other.z) {}
	Vector<3,T>(const T* value) {
		x = *value;
		++value;
		y = *value;
		++value;
		z = *value;
	}
	Vector<3, T>(const Vector<2, T>& v) { x = v.x; y = v.y; z = 0.0f; }	
	const T& operator[] (int idx) const { return data[idx];}
	T& operator[] (int idx) { return data[idx]; }
	T* operator() () {
		return &data[0];
	}
	//! assignment operator
	Vector<3,T>& operator = (const Vector<3,T>& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}
	Vector<2,T> xy() {
		return Vector<2,T>(x,y);
	}	
};

//! Specialized Vector with size 4
template <class T> struct Vector<4,T> { 
	union { 
		T data[4]; 
		struct { 
			T x, y, z, w; 
		}; 
		struct { 
			T r, g, b, a; 
		}; 
	}; 
	Vector<4,T>() : x(0) , y(0) , z(0) , w(0) {}
	explicit Vector<4,T>(T t) : x(t) , y(t) , z(t) , w(t) {}
	Vector<4,T>(T tx,T ty,T tz,T tw) : x(tx) , y(ty) , z(tz) , w(tw) {}
	Vector<4,T>(const Vector<4,T>& other) : x(other.x) , y(other.y) , z(other.z) , w(other.w) {}
	Vector<4,T>(const Vector<3,T>& other,float tw) : x(other.x) , y(other.y) , z(other.z) , w(tw) {}
	Vector<4,T>(const T* data) {
		x = *data;
		++data;
		y = *data;
		++data;
		z = *data;
		++data;
		w = *data;
	}
	const T* operator() () const {
		return &data[0];
	}
	//! assignment operator
	Vector<4,T>& operator = (const Vector<4,T>& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}
	Vector<2, T> xy() {
		return Vector<2, T>(x, y);
	}
	Vector<3, T> xyz() {
		return Vector<3, T>(x, y, z);
	}
};

//! The == operator
/*! The compound == operator will return true if both vectors are equals
	\param u first vector
	\param v second vector
	\return true if equals
*/
template<int Size,class T>
bool operator == (const Vector<Size,T>& u,const Vector<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		if ( u.data[i] != v.data[i] ) {
			return false;
		}
	}
	return true;
}

//! The != operator
/*! The compound != operator will return true if both vectors are not equals
	\param u first vector
	\param v second vector
	\return true if not equals
*/
template<int Size,class T>
bool operator != (const Vector<Size,T>& u,const Vector<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		if ( u.data[i] != v.data[i] ) {
			return true;
		}
	}
	return false;
}

/*! Unary operator - which will change the sign on every member
	\param u the first vector
	\return a vector with the result
*/
template<int Size,class T>
Vector<Size,T> operator - (const Vector<Size,T>& v) {
	Vector<Size,T> ret;
	for ( int i = 0; i < Size; ++i ) {
		ret.data[i] = -v.data[i];
	}
	return ret;
}


/*! Compound operator += which will add the second to the first vector
	\param u the first vector
	\param v the vector that will be added to the first one
	\return a vector with the result
*/
template<int Size,class T>
Vector<Size,T> operator += (Vector<Size,T>& u,const Vector<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] += v.data[i];
	}
	return u;
}

/*! Compound operator += which will add the second to the first vector
	\param u the first vector
	\param v the vector that will be added to the first one
	\return a vector with the result
*/
template<int Size,class T>
Vector<Size,T> operator += (const Vector<Size,T>& u,const Vector<Size,T>& v) {
	Vector<Size,T> r;
	for ( int i = 0; i < Size; ++i ) {
		r.data[i] = u.data[i] + v.data[i];
	}
	return r;
}

// -------------------------------------------------------
// operator *=
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T> operator *= (Vector<Size,T>& u,T other) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] *= other;
	}
	return u;
}

// -------------------------------------------------------
// operator /=
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T>& operator /= (Vector<Size,T>& u,T other) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] /= other;
	}
	return u;
}

/*! Compound operator -= which will subtract the second to the first vector
	\param u the first vector
	\param v the vector that will be subtracted to the first one
	\return a vector with the result
*/
template<int Size,class T>
Vector<Size,T>& operator -= (Vector<Size,T>& u,const Vector<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] -= v.data[i];
	}
	return u;
}

template<int Size, class T>
Vector<Size, T>& operator -= (const Vector<Size, T>& u, const Vector<Size, T>& v) {
	Vector<Size, T> r;
	for (int i = 0; i < Size; ++i) {
		r.data[i] = u.data[i] - v.data[i];
	}
	return r;
}
// -------------------------------------------------------
// operator +
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T> operator + (const Vector<Size,T>& u,const Vector<Size,T>& v) {
	Vector<Size,T> ret = u;
	return ret += v;
}

// -------------------------------------------------------
// operator -
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T> operator - (const Vector<Size,T>& u,const Vector<Size,T>& v) {
	Vector<Size,T> ret = u;
	return ret -= v;
}

/*! Multiplies a vector by a scalar
	\param u the vector
	\param v the scalar
	\return a vector with the result
*/
template<int Size,class T>
Vector<Size,T> operator * (const Vector<Size,T>& u,const T& v) {
	Vector<Size,T> ret = u;
	return ret *= v;
}

/*! Multiplies a vector by a scalar
	\param u the vector
	\param v the scalar
	\return a vector with the result
*/
template<int Size,class T>
Vector<Size,T> operator * (const T& v,const Vector<Size,T>& u) {
	Vector<Size,T> ret = u;
	return ret *= v;
}

/*! Divides a vector by a scalar
	\param u the vector
	\param v the scalar
	\return a vector with the result
*/
template<int Size,class T>
Vector<Size,T> operator / (const Vector<Size,T>& u,const T& v) {
	Vector<Size,T> ret = u;
	return ret /= v;
}

/*! Dot product of two vectors
	\param u first vector
	\param v second vector
	\return the dot product as scalar
*/
template<int Size,class T>
T dot(const Vector<Size,T>& v,const Vector<Size,T>& u) {
	T t(0);
	for ( int i = 0; i < Size; ++i ) {
		t += v.data[i] * u.data[i];
	}
	return t;
}


/*! Calculates the length of a vector
	\param v the vector
	\return the length of a vector as scalar
*/
template<int Size,class T>
T length(const Vector<Size,T>& v) {
	T t = dot(v,v);	
	float tmp = std::sqrt(static_cast<float>(t));
	return static_cast<T>(tmp);
}

/*! Calculates the squared length of a vector. Sometimes
	it can be handy to avoid the sqrt of the regular length
	method and the sqr_length will also work.
    \param v The vector 
    \return the square length
*/ 
template<int Size,class T>
T sqr_length(const Vector<Size,T>& v) {
	return dot(v,v);	
}

/*! Calculates a normalized vector .
    \param u The vector that will be normalized 
    \return A normalized vector
*/ 
template<int Size,class T>
Vector<Size,T> normalize(const Vector<Size,T>& u) {
	T len = length(u);
	if ( len == 0.0f ) {
		return Vector<Size,T>();
	}
	return u / len;	
}

/*! Calculates a normalized vector .
    \param u The vector that will be normalized 
	\param ret a pointer to a Vector that will contain the normalized values
    \return A pointer to a normalized vector
*/ 
template<int Size,class T>
Vector<Size,T>* normalize(const Vector<Size,T>& u,Vector<Size,T>* ret) {
	T len = length(u);
	for ( int i = 0; i < Size; ++i ) {
		ret->data[i] /= len;
	}
	return ret;	
}

/*! Calculates the distance between to vectors
	\param u first vector
	\param v second vector
	\return the distance
*/
template<int Size,class T>
T distance(const Vector<Size,T>& u,const Vector<Size,T>& v) {
	Vector<Size,T> sub = u - v;
	return length(sub);
}

/*! Cross product of two vectors
	\param u first vector
	\param v second vector
	\return a vector containing the cross product
*/
template<class T>
Vector<3,T> cross(const Vector<3,T>& u,const Vector<3,T>& v) {
	T x = u.y * v.z - u.z * v.y;
	T y = u.z * v.x - u.x * v.z; 
	T z = u.x * v.y - u.y * v.x;
	return Vector<3,T>(x,y,z);
}

/*! Cross product of two vectors
	\param u first vector
	\param v second vector
	\param ret a pointer to a vector which will contain the cross product
	\return a pointer to a vector
*/
template<class T>
Vector<3,T>* cross(const Vector<3,T>& u,const Vector<3,T>& v,Vector<3,T>* ret) {
	ret->x = u.y * v.z - u.z * v.y;
	ret->y = u.z * v.x - u.x * v.z; 
	ret->z = u.x * v.y - u.y * v.x;
	return ret;
}

template<class T>
T cross(const Vector<2,T>& v1,const Vector<2,T>& v2) {
	return v1.x * v2.y - v2.x * v1.y;		
}

/*! Linear interpolation of two vectors of the type float.
	\param u first vector
	\param v second vector
	\param t the normalized time. It will be clamped to 0 to 1.
	\param ret a pointer to a vector that will be updated
	\return a pointer to vector containing the interpolation
*/
template<int Size>
Vector<Size,float>* lerp(const Vector<Size,float>& u,const Vector<Size,float>& v,float time,Vector<Size,float>* ret) {
	float norm = time;
	if ( norm < 0.0f ) {
		norm = 0.0f;
	}
	if ( norm > 1.0f ) {
		norm = 1.0f;
	}
	for ( int i = 0; i < Size; ++i ) {
		ret->data[i] = u.data[i] * (1.0f - norm) + v.data[i] * norm;
	}
	return ret;
}

/*! Linear interpolation of two vectors of the type float.
	\param u first vector
	\param v second vector
	\param t the normalized time. It will be clamped to 0 to 1.
	\return a vector containing the interpolation
*/
template<int Size>
Vector<Size,float> lerp(const Vector<Size,float>& u,const Vector<Size,float>& v,float time) {	
	Vector<Size,float> ret;
	lerp(u,v,time,&ret);
	return ret;
}

template<int Size,class T>
Vector<Size,T> vec_min(const Vector<Size,T>& u,const Vector<Size,T>& v) {
	Vector<Size,T> ret;
	for ( int i = 0; i < Size; ++i ) {
		if ( u.data[i] <= v.data[i] ) {
			ret.data[i] = u.data[i];
		}
		else {
			ret.data[i] = v.data[i];
		}
	}
	return ret;
}

template<int Size,class T>
Vector<Size,T> vec_max(const Vector<Size,T>& u,const Vector<Size,T>& v) {
	Vector<Size,T> ret;
	for ( int i = 0; i < Size; ++i ) {
		if ( u.data[i] >= v.data[i] ) {
			ret.data[i] = u.data[i];
		}
		else {
			ret.data[i] = v.data[i];
		}
	}
	return ret;
}

template<int Size,class T>
Vector<Size,T> clamp(const Vector<Size,T>& u,const Vector<Size,T>& min,const Vector<Size,T>& max) {
    Vector<Size,T> ret;
    for ( int i = 0; i < Size; ++i ) {
        ret.data[i] = u.data[i];
        if ( u.data[i] > max.data[i] ) {
            ret.data[i] = max.data[i];
        }
        else if ( u.data[i] < min.data[i] ){
            ret.data[i] = min.data[i];
        }
    }
    return ret;
}

template<int Size, class T>
void clamp(Vector<Size, T>* u, const Vector<Size, T>& min, const Vector<Size, T>& max) {
	for (int i = 0; i < Size; ++i) {		
		if (u->data[i] > max.data[i]) {
			u->data[i] = max.data[i];
		}
		else if (u->data[i] < min.data[i]){
			u->data[i] = min.data[i];
		}
	}
}

template<int Size>
Vector<Size,float> saturate(const Vector<Size,float>& u) {
	return clamp(u,Vector<Size,float>(0.0f),Vector<Size,float>(1.0f));    
}

template<int Size>
Vector<Size,int> saturate(const Vector<Size,int>& u) {
	return clamp(u,Vector<Size,int>(0),Vector<Size,int>(1));    
}

template<int Size,class T>
void limit(Vector<Size,T>* v,const Vector<Size,T>& u) {
	for (int i = 0; i < Size; ++i) {
		if (v->data[i] > u.data[i]) {
			v->data[i] = u.data[i];
		}
		else if (v->data[i] < -u.data[i]){
			v->data[i] = -u.data[i];
		}
	}
}

template<int Size, class T>
Vector<Size, T> reflect(const Vector<Size, T>& u, const Vector<Size, T>& norm) {
	Vector<Size, T> ret;
	float dp = dot(u, norm);
	for (int i = 0; i < Size; ++i) {
		ret.data[i] = u.data[i] - 2.0f * dp * norm.data[i];
	}
	return ret;
}

/*! Cubic interpolation of four vectors of the type float.
	\param v0 first vector
	\param v1 second vector
	\param v2 third vector
	\param v3 fourth vector
	\param t the normalized time
	\return a vector containing the cubic interpolation
*/
template<int Size>
Vector<Size,float> catmullRom(float t,const Vector<Size,float>& v0,const Vector<Size,float>& v1,const Vector<Size,float>& v2,const Vector<Size,float>& v3) {
	float tt = t*t;
	Vector<Size,float> ret(0.0f);
	for ( int i = 0; i < Size; ++i ) {
		ret.data[i] = 0.5f*((2.0f*v1.data[i])+(-v0.data[i]+v2.data[i])*t+(2.0f*v0.data[i]-5.0f*v1.data[i]+4.0f*v2.data[i]-v3.data[i])*tt+(-v0.data[i]+3.0f*(v1.data[i]-v2.data[i])+v3.data[i])*tt*t);
	}
	return ret;
}

typedef Vector<2,int> Vector2i;
typedef Vector<2,float> Vector2f;
typedef Vector<3,int> Vector3i;
typedef Vector<3,float> Vector3f;
typedef Vector<4,float> Vector4f;


typedef Vector<2, float> v2;
typedef Vector<3, float> v3;
typedef Vector<4, float> v4;

const Vector2f V2_RIGHT = Vector2f(1,0);
const Vector2f V2_LEFT = Vector2f(-1,0);
const Vector2f V2_UP   = Vector2f(0,1);
const Vector2f V2_DOWN = Vector2f(0,-1);
const Vector2f V2_ZERO = Vector2f(0, 0);
const Vector2f V2_ONE = Vector2f(1,1);

const Vector3f V3_RIGHT = Vector3f(1, 0, 0);
const Vector3f V3_LEFT  = Vector3f(-1, 0, 0);
const Vector3f V3_UP    = Vector3f(0, 1 , 0);
const Vector3f V3_DOWN  = Vector3f(0, -1, 0);
const Vector3f V3_FORWARD  = Vector3f(0, 0, -1);
const Vector3f V3_BACKWARD = Vector3f(0, 0, 1);
const Vector3f V3_ZERO  = Vector3f(0, 0, 0);
const Vector3f V3_ONE   = Vector3f(1, 1, 1);

inline std::ostream& operator << (std::ostream& os, const Vector2f& v) {
	os << v.x;
	os << v.y;
	return os;
}

inline std::istream& operator >> (std::istream& input, Vector2f& v) {
	input >> v.x;
	input >> v.y;	
	return input;
}

inline std::ostream& operator << (std::ostream& os, const Vector3f& v) {
	os << v.x;
	os << v.y;
	os << v.z;
	return os;
}

inline std::istream& operator >> (std::istream& input, Vector3f& v) {
	input >> v.x;
	input >> v.y;	
	input >> v.z;	
	return input;
}


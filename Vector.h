#pragma once
#include <cmath>

// -------------------------------------------------------
// Basic Vector template
// -------------------------------------------------------
template<int Size,class T>
struct Vector {

	typedef T Type;

	T data[Size];

};

// -------------------------------------------------------
// Specialized template for size 2
// -------------------------------------------------------
template <class T> 
struct Vector<2,T> { 
	union { 
		T data[2]; 
		struct { 
			T x, y; 
		};       
	}; 	
	Vector<2,T>() : x(0) , y(0) {}
	explicit Vector<2,T>(T t) : x(t) , y(t) {}
	Vector<2,T>(T xv,T yv) : x(xv) , y(yv) {}
	Vector<2,T>(const Vector<2,int>& other) : x(other.x) , y(other.y) {}
	Vector<2,T>(const T* value) {
		x = *value;
		++value;
		y = *value;
	}
	const T& operator[] (int idx) const { return data[idx];}
	T* operator() () {
		return &data[0];
	}
};

// -------------------------------------------------------
// Specialized template for size 3
// -------------------------------------------------------
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
	const T operator[] (int idx) const { return data[idx];}
	T* operator() () {
		return &data[0];
	}
	Vector<2,T> xy() {
		return Vector<2,T>(x,y);
	}
	
};

// -------------------------------------------------------
// operator +=
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T> operator += (Vector<Size,T>& u,const Vector<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] += v.data[i];
	}
	return u;
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

// -------------------------------------------------------
// operator -=
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T>& operator -= (Vector<Size,T>& u,const Vector<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] -= v.data[i];
	}
	return u;
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

// -------------------------------------------------------
// operator *
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T> operator * (const Vector<Size,T>& u,const T& v) {
	Vector<Size,T> ret = u;
	return ret *= v;
}

// -------------------------------------------------------
// operator /
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T> operator / (const Vector<Size,T>& u,const T& v) {
	Vector<Size,T> ret = u;
	return ret /= v;
}

// -------------------------------------------------------
// Dot
// -------------------------------------------------------
template<int Size,class T>
T dot(const Vector<Size,T>& v,const Vector<Size,T>& u) {
	T t(0);
	for ( int i = 0; i < Size; ++i ) {
		t += v.data[i] * u.data[i];
	}
	return t;
}

// -------------------------------------------------------
// Length
// -------------------------------------------------------
template<int Size,class T>
T length(const Vector<Size,T>& v) {
	T t = dot(v,v);	
	float tmp = std::sqrt(static_cast<float>(t));
	return static_cast<T>(tmp);
}

// -------------------------------------------------------
// sqr_length
// -------------------------------------------------------
template<int Size,class T>
T sqr_length(const Vector<Size,T>& v) {
	return dot(v,v);	
}

// -------------------------------------------------------
// Normalize
// -------------------------------------------------------
template<int Size,class T>
Vector<Size,T> normalize(const Vector<Size,T>& u) {
	T len = length(u);
	return u / len;	
}

// -------------------------------------------------------
// Distance
// -------------------------------------------------------
template<int Size,class T>
T distance(const Vector<Size,T>& u,const Vector<Size,T>& v) {
	Vector<Size,T> sub = u - v;
	return length(sub);
}

// -------------------------------------------------------
// Cross
// -------------------------------------------------------
template<class T>
Vector<3,T> cross(const Vector<3,T>& v1,const Vector<3,T>& v2) {
	T x = v1.y * v2.z - v1.z * v2.y;
	T y = v1.z * v2.x - v1.x * v2.z; 
	T z = v1.x * v2.y - v1.y * v2.x;
	return Vector<3,T>(x,y,z);
}

template <int Size,class T> 
struct Point { 

	T data[Size];
	
};

template<class T>
struct Point<2,T> {
	union { 
		T data[2]; 
		struct { 
			T x, y; 
		};       
	}; 	
	Point<2,T>() : x(0) , y(0) {}
	explicit Point<2,T>(T t) : x(t) , y(t) {}
	Point<2,T>(T xv,T yv) : x(xv) , y(yv) {}
	Point<2,T>(const Point<2,int>& other) : x(other.x) , y(other.y) {}
	Point<2,T>(const T* value) {
		x = *value;
		++value;
		y = *value;
	}
	const T& operator[] (int idx) const { return data[idx];}
	T* operator() () {
		return &data[0];
	}
};

// -------------------------------------------------------
// operator +=
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator += (Point<Size,T>& u,const Point<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] += v.data[i];
	}
	return u;
}

// -------------------------------------------------------
// operator *=
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator *= (Point<Size,T>& u,T other) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] *= other;
	}
	return u;
}

// -------------------------------------------------------
// operator *=
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator *= (Point<Size,T>& u,const Point<Size,T>& other) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] *= other.data[i];
	}
	return u;
}

// -------------------------------------------------------
// operator /=
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T>& operator /= (Point<Size,T>& u,T other) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] /= other;
	}
	return u;
}

// -------------------------------------------------------
// operator /=
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T>& operator /= (Point<Size,T>& u,const Point<Size,T>& other) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] /= other.data[i];
	}
	return u;
}

// -------------------------------------------------------
// operator -=
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T>& operator -= (Point<Size,T>& u,const Point<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		u.data[i] -= v.data[i];
	}
	return u;
}

// -------------------------------------------------------
// operator +
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator + (const Point<Size,T>& u,const Point<Size,T>& v) {
	Point<Size,T> ret = u;
	return ret += v;
}

// -------------------------------------------------------
// operator -
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator - (const Point<Size,T>& u,const Point<Size,T>& v) {
	Point<Size,T> ret = u;
	return ret -= v;
}

// -------------------------------------------------------
// operator *
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator * (const Point<Size,T>& u,const T& v) {
	Point<Size,T> ret = u;
	return ret *= v;
}

// -------------------------------------------------------
// operator *
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator * (const Point<Size,T>& u,const Point<Size,T>& v) {
	Point<Size,T> ret = u;
	for ( int i = 0; i < size; ++i ) {
		ret.data[i] *= v.data[i];
	}
	return ret;
}

// -------------------------------------------------------
// operator /
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator / (const Point<Size,T>& u,const T& v) {
	Point<Size,T> ret = u;
	return ret /= v;
}

typedef Vector<2,int> Vector2i;
typedef Vector<2,float> Vector2f;
typedef Vector<3,float> Vector3f;
typedef Point<2,int> Point2i;
typedef Point<2,float> Point2f;
//typedef Point<3,int> Point3i;
//typedef Point<3,float> Pointfi;
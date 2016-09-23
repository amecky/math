#pragma once

//! Basic Point template
/*! This is the basic template defining only the array of data.
	The size and the class needs to be defined.
*/
template<int Size,class T>
struct Point {

	T data[Size]; //!< Internal array of values

};

//! Specialized template version for size 2
/*!	
*/
template <class T> 
struct Point<2,T> { 
	union { 
		T data[2]; 
		struct { 
			T x, y; 
		};       
	}; 	
	//! Default constructor. Setting x and y to 0
	Point<2,T>() : x(0) , y(0) {}
	//! Constructor setting x and y to given value
	explicit Point<2,T>(T t) : x(t) , y(t) {}
	//! Constructor setting x and y to given values
	Point<2,T>(T xv,T yv) : x(xv) , y(yv) {}
	//! Copy constructor.
	Point<2,T>(const Point<2,int>& other) : x(other.x) , y(other.y) {}
	//! Constructor taking x and y from the given array
	Point<2,T>(const T* value) {
		x = *value;
		++value;
		y = *value;
	}	
	const T& operator[] (int idx) const { return data[idx];}
	//! Conversion operator returning a pointer to internal data
	T* operator() () {
		return &data[0];
	}
};

//! Specialized template for size 3
template <class T> 
struct Point<3,T> { 
	union { 
		T data[3]; 
		struct { 
			T x, y, z; 
		};       
	}; 

	Point<3,T>() : x(0.0f) , y(0.0f) , z(0.0f) {}
	explicit Point<3,T>(T t) : x(t) , y(t) , z(t) {}
	Point<3,T>(T xv,T yv,T zv) : x(xv) , y(yv) , z(zv) {}
	Point<3,T>(const Point<2,T>& other,T tz) : x(other.x) , y(other.y) , z(tz) {}
	Point<3,T>(const Point<3,T>& other) : x(other.x) , y(other.y) , z(other.z) {}
	Point<3,T>(const T* value) {
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
	Point<2,T> xy() {
		return Point<2,T>(x,y);
	}
	
};
//! The == operator
/*! The compound == operator will return true if both Points are equals
	\param u first Point
	\param v second Point
	\return true if equals
*/
template<int Size,class T>
bool operator == (const Point<Size,T>& u,const Point<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		if ( u.data[i] != v.data[i] ) {
			return false;
		}
	}
	return true;
}

//! The != operator
/*! The compound != operator will return true if both Points are not equals
	\param u first Point
	\param v second Point
	\return true if not equals
*/
template<int Size,class T>
bool operator != (const Point<Size,T>& u,const Point<Size,T>& v) {
	for ( int i = 0; i < Size; ++i ) {
		if ( u.data[i] != v.data[i] ) {
			return true;
		}
	}
	return false;
}
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
	return ret *= v;
}

// -------------------------------------------------------
// operator /
// -------------------------------------------------------
template<int Size,class T>
Point<Size,T> operator / (const Point<Size,T>& u,const T& v) {
	Point<Size,T> ret = u;
	return ret /= v;
}

template<int Size>
Point<Size,float>* lerp(const Point<Size,float>& u,const Point<Size,float>& v,float time,Point<Size,float>* ret) {
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

template<int Size>
Point<Size,float> lerp(const Point<Size,float>& u,const Point<Size,float>& v,float time) {    
	Point<Size,float> ret;
	lerp(u,v,time,&ret);
	return ret;
}

template<int Size>
float distance(const Point<Size,float>& u,const Point<Size,float>& v) {
	Point<Size,float> sub = u - v;
	float t = 0.0f;
	for ( int i = 0; i < Size; ++i ) {
		t += sub.data[i] * sub.data[i];
	}
	return std::sqrt(t);
}

typedef Point<2,int> Point2i;
typedef Point<2,float> Point2f;
typedef Point<3,int> Point3i;
typedef Point<3,float> Point3f;

typedef Point<2, int> p2i;
typedef Point<2, float> p2;
typedef Point<3, int> p3i;
typedef Point<3, float> p3;
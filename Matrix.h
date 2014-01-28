#pragma once
#include "Vector.h"

template<int rows,int cols,class T>
struct Matrix {

	T data[rows][cols];
};

template<class T>
struct Matrix<2,2,T> {
	union {
		T data[2][2];
		struct {
			float m11, m12;
			float m21, m22;
		};
	};
	Matrix<2,2,T>() : m11(0) , m12(0), m21(0) , m22(0) {}
	Matrix<2,2,T>(T v11,T v12,T v21,T v22) : m11(v11) , m12(v12) , m21(v21) , m22(v22) {}

	operator T *() const { 
		return (T*) &m11; 
	}
};

template<class T>
struct Matrix<3,3,T> {
	union {
		T data[3][3];
		struct {
			float m11, m12, m13;
			float m21, m22, m23;
			float m31, m32, m33;
		};
	};
	Matrix<3,3,T>() : m11(0) , m12(0), m13(0) , m21(0) , m22(0) , m23(0) , m31(0) , m32(0) , m33(0) {}
	Matrix<3,3,T>(T v11,T v12,T v13,T v21,T v22,T v23,T v31,T v32,T v33) 
		: m11(v11) , m12(v12) , m13(v13) , m21(v21) , m22(v22) , m23(v23) , m31(v31) , m32(v32) , m33(v33) {}

	operator T *() const { 
		return (T*) &m11; 
	}
};

/*! Compound operator += which will add the second to the first matrix
	\param m1 the first matrix
	\param m2 the matrix that will be added to the first one
	\return a matrix with the result
*/
template<int rows,int cols,class T>
Matrix<rows,cols,T> operator += (Matrix<rows,cols,T>& m1,const Matrix<rows,cols,T>& m2) {
	for ( int x = 0; x < cols ; ++x ) {
		for ( int y = 0; y < rows; ++y ) {
			m1.data[x][y] += m2.data[x][y];
		}
	}	
	return m1;
}

/*! Operator + which will sum both matrices into a new one
	\param m1 the first matrix
	\param m2 the second matrix
	\return a the matrix containing the sum of both
*/
template<int rows,int cols,class T>
Matrix<rows,cols,T> operator + (const Matrix<rows,cols,T>& m1,const Matrix<rows,cols,T>& m2) {
	Matrix<rows,cols,T> ret = m1;
	ret += m2;
	return ret;
}

template<class T>
Matrix<3,3,T> operator * (const Matrix<3,3,T>& m1,const Matrix<3,3,T>& m2) {
	Matrix<3,3,T> tmp;
	tmp.m11 = m1.m11 * m2.m11 + m1.m12 * m2.m21 + m1.m13 * m2.m31;
	tmp.m12 = m1.m11 * m2.m12 + m1.m12 * m2.m22 + m1.m13 * m2.m32;
	tmp.m13 = m1.m11 * m2.m13 + m1.m12 * m2.m23 + m1.m13 * m2.m33;
	tmp.m21 = m1.m21 * m2.m11 + m1.m22 * m2.m21 + m1.m23 * m2.m31;
	tmp.m22 = m1.m21 * m2.m12 + m1.m22 * m2.m22 + m1.m23 * m2.m32;
	tmp.m23 = m1.m21 * m2.m13 + m1.m22 * m2.m23 + m1.m23 * m2.m33;
	tmp.m31 = m1.m31 * m2.m11 + m1.m32 * m2.m21 + m1.m33 * m2.m31;
	tmp.m32 = m1.m31 * m2.m12 + m1.m32 * m2.m22 + m1.m33 * m2.m32;
	tmp.m33 = m1.m31 * m2.m13 + m1.m32 * m2.m23 + m1.m33 * m2.m33;
	return tmp;
}

template<class T>
Vector<3,T> operator * (const Matrix<3,3,T>& m,const Vector<3,T>& v) {
	Vector<3,T> tmp;
	tmp.x = m.m11 * v.x + m.m12 * v.y + m.m13 * v.z;
	tmp.y = m.m21 * v.x + m.m22 * v.y + m.m23 * v.z;
	tmp.z = m.m31 * v.x + m.m32 * v.y + m.m33 * v.z;
	return tmp;
}

template<class T>
void identity(Matrix<3,3,T>* ret) {
	for ( int i = 0; i < 3; ++i ) {
		for ( int j = 0; j < 3; ++j ) {
			if ( i == j ) {
				ret->data[i][j] = 1;
			}
			else {
				ret->data[i][j] = 0;
			}
		}
	}	
}

typedef Matrix<2,2,float> Mat22f;
typedef Matrix<3,3,float> Mat33f;
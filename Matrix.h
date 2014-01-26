#pragma once

template<int rows,int cols,class T>
struct Matrix {

	T data[rows][cols];
};

typedef Matrix<2,2,float> Mat22f;
typedef Matrix<3,3,float> Mat33f;
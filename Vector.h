/* 
 * File:   Vector.h
 * Author: meckya
 *
 * Created on 23. Januar 2014, 11:08
 */

#ifndef VECTOR_H
#define	VECTOR_H

template<int Size,class T>
struct Vector {
    T data[Size];
};

template<int Size,class T>
struct Matrix {
    T data[Size][Size];
};

// --------------------------------------------------
// Specialized Vector with size 2
// --------------------------------------------------
template <class T> struct Vector<2,T> { 
    union { 
        T data[2]; 
        struct { T x, y; };       
    };     
    Vector<2,T>() : x(0) , y(0) {}
    explicit Vector<2,T>(T t) : x(t) , y(t) {}
    Vector<2,T>(T tx,T ty) : x(tx) , y(ty) {}
    Vector<2,T>(const Vector<2,T>& other) : x(other.x) , y(other.y) {}
    Vector<2,T>(const T* data) {
        x = *data;
        ++data;
        y = *data;
    }
    const T* operator() () const {
        return &data[0];
    }
};

// --------------------------------------------------
// Specialized Vector with size 3
// --------------------------------------------------
template <class T> struct Vector<3,T> { 
    union { 
        T data[3]; 
        struct { T x, y, z; };    
    }; 
    Vector<3,T>() : x(0) , y(0) , z(0) {}
    explicit Vector<3,T>(T t) : x(t) , y(t) , z(t) {}
    Vector<3,T>(T tx,T ty,T tz) : x(tx) , y(ty) , z(tz) {}
    Vector<3,T>(const Vector<3,T>& other) : x(other.x) , y(other.y) , z(other.z) {}
    Vector<3,T>(const Vector<2,T>& v,T tz) : x(v.x) , y(v.y) , z(tz) {}
    Vector<3,T>(const T* data) {
        x = *data;
        ++data;
        y = *data;
        ++data;
        z = *data;
    }
    const T* operator() () const {
        return &data[0];
    }
};

// --------------------------------------------------
// Specialized Vector with size 4
// --------------------------------------------------
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
    Vector<4,T>(const Vector<4,T>& other) : x(other.x) , y(other.y) , z(other.z) , w(other.z) {}
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
};

template<int Size,class T>
Vector<Size,T> operator += (Vector<Size,T>& u,const Vector<Size,T>& v) {
    for ( int i = 0; i < Size; ++i ) {
        u.data[i] += v.data[i];
    }
    return u;
}

template<int Size,class T>
Vector<Size,T> operator + (const Vector<Size,T>& u,const Vector<Size,T>& v) {
    Vector<Size,T> r = u;
    r += v;
    return r;
}

template<int Size,class T>
Vector<Size,T> operator -= (Vector<Size,T>& u,const Vector<Size,T>& v) {
    for ( int i = 0; i < Size; ++i ) {
        u.data[i] -= v.data[i];
    }
    return u;
}

template<int Size,class T>
Vector<Size,T> operator - (const Vector<Size,T>& u,const Vector<Size,T>& v) {
    Vector<Size,T> r = u;
    r -= v;
    return r;
}

template<int Size,class T>
Vector<Size,T> operator *= (Vector<Size,T>& u,T v) {
    for ( int i = 0; i < Size; ++i ) {
        u.data[i] *= v;
    }
    return u;
}

template<int Size,class T>
Vector<Size,T> operator * (const Vector<Size,T>& u,T v) {
    Vector<Size,T> ret = u;
    ret *= v;
    return u;
}

template<int Size,class T>
Vector<Size,T> operator /= (Vector<Size,T>& u,T v) {
    for ( int i = 0; i < Size; ++i ) {
        u.data[i] /= v;
    }
    return u;
}

template<int Size,class T>
Vector<Size,T> operator / (const Vector<Size,T>& u,T v) {
    Vector<Size,T> ret = u;
    ret /= v;
    return u;
}

template<int Size,class T>
bool operator == (const Vector<Size,T>& u,const Vector<Size,T>& v) {
    for ( int i = 0; i < Size; ++i ) {
        if ( u.data[i] != v.data[i] ) {
            return false;
        }
    }
    return true;
}

template<int Size,class T>
bool operator != (const Vector<Size,T>& u,const Vector<Size,T>& v) {
    for ( int i = 0; i < Size; ++i ) {
        if ( u.data[i] != v.data[i] ) {
            return true;
        }
    }
    return false;
}

template<int Size,class T>
T dot(const Vector<Size,T>& u,const Vector<Size,T>& v) {
    T t = 0;
    for ( int i = 0; i < Size; ++i ) {
        t += u.data[i] * v.data[i];
    }
    return t;
}

template<int Size>
Vector<Size,float> lerp(const Vector<Size,float>& u,const Vector<Size,float>& v,float time) {
    float norm = time;
    if ( norm < 0.0f ) {
        norm = 0.0f;
    }
    if ( norm > 1.0f ) {
        norm = 1.0f;
    }
    Vector<Size,float> ret;
    for ( int i = 0; i < Size; ++i ) {
        ret.data[i] = u.data[i] * (1.0f - norm) + v.data[i] * norm;
    }
    return ret;
}

template<int Size,class T>
Vector<Size,T> min(const Vector<Size,T>& u,const Vector<Size,T>& v) {
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
Vector<Size,T> max(const Vector<Size,T>& u,const Vector<Size,T>& v) {
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

template<int Size>
Vector<Size,int> saturate(const Vector<Size,int>& u) {
    return clamp(u,Vector<Size,int>(0),Vector<Size,int>(1));    
}

template<int Size>
Vector<Size,float> saturate(const Vector<Size,float>& u) {
    return clamp(u,Vector<Size,float>(0.0f),Vector<Size,float>(1.0f));    
}

template<int Size,class T>
T sqr_length(const Vector<Size,T>& u) {
    T t = 0;
    for ( int i = 0; i < Size; ++i ) {
        t += u.data[i] * u.data[i];
    }
    return t;
}

template<int Size,class T>
T length(const Vector<Size,T>& u) {
    T t = sqr_length(u);
    return sqrt(t);    
    return t;
}


template <class T> struct Matrix<2,T> { 
    union { 
        T data[2][2]; 
        struct { 
            T m11, m12 , m21, m22; 
        };       
    };     
    Matrix<2,T>() : m11(0) , m12(0) , m21(0) , m22(0) {}
    explicit Matrix<2,T>(T t) : m11(t) , m12(t) , m21(t) , m22(t) {}
    Matrix<2,T>(T _m11,T _m12,T _m21,T _m22) : m11(_m11) , m12(_m12) , m21(_m21) , m22(_m22) {}
};

// --------------------------------------------------
// Specialized Matrix with size 3
// --------------------------------------------------
template <class T> struct Matrix<3,T> { 
    union { 
        T data[3][3]; 
        struct { 
            T m11, m12, m13;
            T m21, m22, m23; 
            T m31, m32, m33;
        };       
    };     
    Matrix<3,T>() : m11(0) , m12(0) , m13(0) , m21(0) , m22(0) , m23(0) , m31(0) , m32(0) , m33(0) {}
    explicit Matrix<3,T>(T t) : m11(t) , m12(t) , m13(t) , m21(t) , m22(t) , m23(t) , m31(t) , m32(t) , m33(t) {}
    Matrix<3,T>(T _m11,T _m12,T _m13,T _m21,T _m22,T _m23,T _m31,T _m32,T _m33) : m11(_m11) , m12(_m12) , m13(_m13) , m21(_m21) , m22(_m22) , m23(_m23) , m31(_m31) , m32(_m32) , m33(_m33) {}
};

template<int Size,class T>
void clear(Matrix<Size,T>& m,T t) {
    for ( int i = 0; i < Size; ++i ) {
        for ( int j = 0; j < Size; ++j ) {
                m.data[i][j] = t;
        }
    }
}

template<int Size,class T>
void identity(Matrix<Size,T>& m) {
    clear<Size,T>(m,0);
    for ( int i = 0; i < Size; ++i ) {
        m.data[i][i] = 1;
    }
}

template<class T>
Matrix<3,T> operator * (const Matrix<3,T>& m1,const Matrix<3,T>& m2) {
    Matrix<3,T> ret;
    ret.m11 = (m1.m11 * m2.m11) + (m1.m12 * m2.m21) + (m1.m13 * m2.m31);
    ret.m21 = (m1.m21 * m2.m11) + (m1.m22 * m2.m21) + (m1.m23 * m2.m31);
    ret.m31 = (m1.m31 * m2.m11) + (m1.m32 * m2.m21) + (m1.m33 * m2.m31);
    ret.m12 = (m1.m11 * m2.m12) + (m1.m12 * m2.m22) + (m1.m13 * m2.m32);
    ret.m22 = (m1.m21 * m2.m12) + (m1.m22 * m2.m22) + (m1.m23 * m2.m32);
    ret.m32 = (m1.m31 * m2.m12) + (m1.m32 * m2.m22) + (m1.m33 * m2.m32);
    ret.m13 = (m1.m11 * m2.m13) + (m1.m12 * m2.m23) + (m1.m13 * m2.m33);
    ret.m23 = (m1.m21 * m2.m13) + (m1.m22 * m2.m23) + (m1.m23 * m2.m33);
    ret.m33 = (m1.m31 * m2.m13) + (m1.m32 * m2.m23) + (m1.m33 * m2.m33);
    return ret;
}

template<class T>
Vector<3,T> operator * (const Matrix<3,T>& m,const Vector<3,T>& v) {
    Vector<3,T> ret;
    ret.x = v.x * m.m11 + v.y * m.m12 + v.z * m.m13;
    ret.y = v.x * m.m21 + v.y * m.m22 + v.z * m.m23;
    ret.z = v.x * m.m31 + v.y * m.m32 + v.z * m.m33;
    return ret;
}

typedef Vector<2,int> v2i;
typedef Vector<2,float> v2f;
typedef Vector<3,int> v3i;
typedef Vector<3,float> v3f;
typedef Vector<4,int> v4i;
typedef Vector<4,float> v4f;
typedef Matrix<2,int> mat22i;
typedef Matrix<2,float> mat22;
typedef Matrix<3,float> mat33;
typedef Matrix<4,float> mat44;
#endif	/* VECTOR_H */


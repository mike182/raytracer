#ifndef __NORMAL_HPP__
#define __NORMAL_HPP__

#include "Vector3D.hpp"
#include "Point3D.hpp"
#include "Matrix.hpp"

class Normal {
public:
    Normal(void);
    Normal(double a);
    Normal(double x, double y, double z);
    Normal(const Normal& n);
    Normal(const Vector3D& n);
    virtual ~Normal(void);

    Normal& operator=(const Normal& rhs);
    Normal& operator=(const Vector3D& rhs);
    Normal& operator=(const Point3D& rhs);

    Normal operator-() const;
    Normal operator+(const Normal& n) const;
    Normal& operator+=(const Normal& n);
    double operator*(const Vector3D& v) const;
    Normal operator*(const double a) const;

    void normalize();

public:
    double x, y, z;
};

// lhs prototype
Normal operator*(const double a, const Normal& n);
Vector3D operator+(const Vector3D& v, const Normal& n);
Vector3D operator-(const Vector3D& v, const Normal& n);
double operator*(const Vector3D& v, const Normal& n);

// matrix
Normal operator*(const Matrix& mat, const Normal& n);

inline Normal Normal::operator-() const {
    return Normal(-x, -y, -z);
}

inline Normal Normal::operator+(const Normal& n) const {
    return Normal(x + n.x, y + n.y, z + n.z);
}

inline Normal& Normal::operator+=(const Normal& n) {
    x += n.x;
    y += n.y;
    z += n.z;

    return *this;
}

inline double Normal::operator*(const Vector3D& v) const {
    return x * v.x + y * v.y + z * v.z;
}

inline Normal Normal::operator*(const double a) const {
    return Normal(x * a, y * a, z * a);
}

// lhs
inline Normal operator*(const double a, const Normal& n) {
    return Normal(a * n.x, a * n.y, a * n.z);
}

// lhs
inline Vector3D operator+(const Vector3D& v, const Normal& n) {
    return Vector3D(v.x + n.x, v.y + n.y, v.z + n.z);
}

// lhs
inline Vector3D operator-(const Vector3D& v, const Normal& n) {
    return Vector3D(v.x - n.x, v.y - n.y, v.z - n.z);
}

// lhs
inline double operator*(const Vector3D& v, const Normal& n) {
    return v.x * n.x + v.y * n.y + v.z * n.z;
}

#endif // __NORMAL_HPP__

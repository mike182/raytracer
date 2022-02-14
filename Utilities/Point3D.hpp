#ifndef __POINT3D_HPP__
#define __POINT3D_HPP__

#include "Vector3D.hpp"
#include "Matrix.hpp"

class Point3D {
public:
    Point3D(void);
    Point3D(const double a);
    Point3D(const double x, const double y, const double z);
    Point3D(const Point3D& p);
    virtual ~Point3D(void);

    Point3D& operator=(const Point3D& rhs);

    Point3D operator-() const;
    Point3D operator+(const Vector3D& v) const;
    Point3D operator-(const Vector3D& v) const;
    Vector3D operator-(const Point3D& p) const;
    Point3D operator*(const double a) const;
    double d_squared(const Point3D& p) const; // ||p - p||^2
    double distance(const Point3D& p) const; // ||p - p||^1/2

public:
    double x, y, z;
};

// lhs
Point3D operator*(double a, const Point3D& p);

// matrix
Point3D operator*(const Matrix& mat, const Point3D& p);

inline Point3D Point3D::operator-() const {
    return Point3D(-x, -y, -z);
}

inline Point3D Point3D::operator+(const Vector3D& v) const {
    return Point3D(x + v.x, y + v.y, z + v.z);
}

inline Point3D Point3D::operator-(const Vector3D& v) const {
    return Point3D(x - v.x, y - v.y, z - v.z);
}

inline Vector3D Point3D::operator-(const Point3D& p) const {
    return Vector3D(x - p.x, y - p.y, z - p.z);
}

inline Point3D Point3D::operator*(const double a) const {
    return Point3D(x * a, y * a, z * a);
}

inline double Point3D::d_squared(const Point3D& p) const {
    return (x - p.x) * (x - p.x)
        + (y - p.y) * (y - p.y)
        + (z - p.z) * (z - p.z);
}

inline Point3D operator* (double a, const Point3D& p) {
    return Point3D(a * p.x, a * p.y, a * p.z);
}

#endif // __POINT3D_HPP__

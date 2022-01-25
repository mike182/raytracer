#ifndef __POINT3D_HPP__
#define __POINT3D_HPP__

#include "Vector3D.hpp"

class Point3D {
public:
    Point3D(void);
    Point3D(const double a);
    Point3D(const double x, const double y, const double z);
    Point3D(const Point3D & p);
    virtual ~Point3D(void);

    Point3D & operator=(const Point3D & rhs);

    Point3D operator-() const;
    Point3D operator+(const Vector3D & v) const;
    Point3D operator-(const Vector3D & v) const;
    Vector3D operator-(const Point3D & p) const;
    double d_squared(const Point3D & p) const; // ||p - p||^2
    double distance(const Point3D & p) const; // ||p - p||^1/2
    Point3D operator*(const double a) const;

public:
    double x, y, z;
};

#endif // __POINT3D_HPP__

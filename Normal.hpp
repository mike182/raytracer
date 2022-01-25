#ifndef __NORMAL_HPP__
#define __NORMAL_HPP__

#include "Vector3D.hpp"
#include "Point3D.hpp"

class Normal {
public:
    Normal(void);
    Normal(double a);
    Normal(double x, double y, double z);
    Normal(const Normal & n);
    Normal(const Vector3D & n);
    virtual ~Normal(void);

    Normal & operator=(const Normal & rhs);
    Normal & operator=(const Vector3D & rhs);
    Normal & operator=(const Point3D & rhs);

    Normal operator-() const;
    Normal operator+(const Normal & n) const;
    Normal & operator+=(const Normal & n);
    double operator*(const Vector3D & v) const;
    Normal operator*(const double a) const;

    void normalize();

public:
    double x, y, z;
};

Normal operator*(const double a, const Normal & n);
Vector3D operator+(const Vector3D & v, const Normal & n);
Vector3D operator-(const Vector3D &, const Normal & n);
double operator*(const Vector3D & v, const Normal & n);

#endif // __NORMAL_HPP__

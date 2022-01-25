#ifndef __VECTOR3D_HPP__
#define __VECTOR3D_HPP__

class Normal;
class Point3D;

class Vector3D {
public:
    Vector3D(void);
    Vector3D(double a);
    Vector3D(double x, double y, double z);
    Vector3D(const Vector3D & v);
    Vector3D(const Normal & n);
    Vector3D(const Point3D & p);
    virtual ~Vector3D(void);

    Vector3D & operator=(const Vector3D & rhs);
    Vector3D & operator=(const Normal & rhs);
    Vector3D & operator=(const Point3D & rhs);

    Vector3D operator-() const;
    Vector3D operator*(const double a) const;
    Vector3D operator/(const double a) const;
    Vector3D operator+(const Vector3D & v) const;
    Vector3D & operator+=(const Vector3D & v);
    Vector3D operator-(const Vector3D & v) const;
    double operator*(const Vector3D & v) const;
    Vector3D operator^(const Vector3D & v) const;

    double length();
    double len_squared();
    void normalize();
    Vector3D & hat();

public:
    double x, y, z;
};

Vector3D operator*(const double a, const Vector3D & v); // prototype

#endif // __VECTOR3D_HPP__

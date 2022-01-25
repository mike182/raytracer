#include "Point3D.hpp"

#include <cmath>

Point3D::Point3D(void)
    : x(0), y(0), z(0) { }

Point3D::Point3D(const double a)
    : x(a), y(a), z(a) { }

Point3D::Point3D(const double x, const double y, const double z)
    : x(x), y(y), z(z) { }

Point3D::Point3D(const Point3D & p)
    : x(p.x), y(p.y), z(p.z) { }

Point3D::~Point3D(void)
{
}

Point3D & Point3D::operator=(const Point3D & rhs) {
    if (this == &rhs)
        return *this;

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Point3D Point3D::operator-() const {
    return Point3D(-x, -y, -z);
}

Point3D Point3D::operator+(const Vector3D & v) const {
    return Point3D(x + v.x, y + v.y, z + v.z);
}

Point3D Point3D::operator-(const Vector3D & v) const {
    return Point3D(x - v.x, y - v.y, z - v.z);
}

Vector3D Point3D::operator-(const Point3D & p) const {
    return Vector3D(x - p.x, y - p.y, z - p.z);
}

double Point3D::d_squared(const Point3D & p) const {
    return ((x - p.x) * (x - p.x)
            + (y - p.y) * (y - p.y)
            + (z - p.z) * (z - p.z));
}

double Point3D::distance(const Point3D & p) const {
      return sqrt((x - p.x) * (x - p.x)
              + (y - p.y) * (y - p.y)
              + (z - p.z) * (z - p.z));
}

Point3D Point3D::operator*(const double a) const {
    return Point3D(x * a, y * a, z * a);
}


#include "Point3D.hpp"

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


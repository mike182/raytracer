#include "Vector3D.hpp"

Vector3D::Vector3D(void)
    :  x(0), y(0), z(0) { }

Vector3D::Vector3D(double a)
    :  x(a), y(a), z(a) { }

Vector3D::Vector3D(double x, double y, double z)
    :  x(x), y(y), z(z) { }

Vector3D::Vector3D(const Vector3D & v)
    : x(v.x), y(v.y), z(v.z) { }

Vector3D::~Vector3D(void)
{
}

Vector3D & Vector3D::operator=(const Vector3D & rhs) {
    if (this == &rhs)
        return *this;

    // x = rhs.x;
    // y = rhs.y;
    // z = rhs.z;

    return *this;
}


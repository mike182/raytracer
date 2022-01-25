#include "Vector3D.hpp"

#include "Normal.hpp"
#include "Point3D.hpp"

#include <cmath>

Vector3D::Vector3D(void)
    :  x(0), y(0), z(0) { }

Vector3D::Vector3D(double a)
    :  x(a), y(a), z(a) { }

Vector3D::Vector3D(double x, double y, double z)
    :  x(x), y(y), z(z) { }

Vector3D::Vector3D(const Vector3D & v)
    : x(v.x), y(v.y), z(v.z) { }

Vector3D::Vector3D(const Normal & n)
    : x(n.x), y(n.y), z(n.z) { }

Vector3D::Vector3D(const Point3D & p)
    : x(p.x), y(p.y), z(p.z) { }

Vector3D::~Vector3D(void)
{
}

Vector3D & Vector3D::operator=(const Vector3D & rhs) {
    if (this == &rhs)
        return *this;

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Vector3D & Vector3D::operator=(const Normal & rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Vector3D & Vector3D::operator=(const Point3D & rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator*(const double a) const {
    return Vector3D(x * a, y * a, z * a);
}

Vector3D operator*(const double a, const Vector3D & v) {
    return Vector3D(a * v.x, a * v.y, a * v.z);
}

Vector3D Vector3D::operator/(const double a) const {
    return Vector3D(x / a, y / a, z / a);
}

Vector3D Vector3D::operator+(const Vector3D & v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

Vector3D & Vector3D::operator+=(const Vector3D & v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

Vector3D Vector3D::operator-(const Vector3D & v) const {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

double Vector3D::operator*(const Vector3D & v) const {
    return x * v.x + y * v.y + z * v.z;
}

Vector3D Vector3D::operator^(const Vector3D & v) const {
    return Vector3D(y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
}

double Vector3D::length() {
    return sqrt(x * x + y * y + z * z);
}

double Vector3D::len_squared() {
    return x * x + y * y + z * z;
}

void Vector3D::normalize() {
    double length = sqrt(x * x + y * y + z * z);
    x /= length;
    y /= length;
    z /= length;
}

Vector3D & Vector3D::hat() {
    double length = sqrt(x * x + y * y + z * z);
    x /= length;
    y /= length;
    z /= length;

    return *this;
}

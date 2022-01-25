#include "Normal.hpp"

#include <cmath>

Normal::Normal(void)
    : x(0.0), y(0.0), z(0.0) { }

Normal::Normal(double a)
    : x(a), y(a), z(a) { }

Normal::Normal(double x, double y, double z)
    : x(x), y(y), z(z) { }

Normal::Normal(const Normal & n)
    : x(n.x), y(n.y), z(n.z) { }

Normal::Normal(const Vector3D & v)
    : x(v.x), y(v.y), z(v.z) { }

Normal::~Normal(void)
{
}

Normal & Normal::operator=(const Normal & rhs) {
    if (this == &rhs)
        return *this;

    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Normal & Normal::operator=(const Vector3D & rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Normal & Normal::operator=(const Point3D & rhs) {
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;

    return *this;
}

Normal Normal::operator-() const {
    return Normal(-x, -y, -z);
}

Normal Normal::operator+(const Normal & n) const {
    return Normal(x + n.x, y + n.y, z + n.z);
}

Normal & Normal::operator+=(const Normal & n) {
    x += n.x;
    y += n.y;
    z += n.z;

    return *this;
}

double Normal::operator*(const Vector3D & v) const {
    return x * v.x + y * v.y + z * v.z;
}

Normal Normal::operator*(const double a) const {
    return Normal(x * a, y * a, z * a);
}

Normal operator*(const double a, const Normal & n) {
    return Normal(a * n.x, a * n.y, a * n.z);
}

Vector3D operator+(const Vector3D & v, const Normal & n) {
    return Vector3D(v.x + n.x, v.y + n.y, v.z + n.z);
}

Vector3D operator-(const Vector3D & v, const Normal & n) {
    return Vector3D(v.x - n.x, v.y - n.y, v.z - n.z);
}

double operator*(const Vector3D & v, const Normal & n) {
    return v.x * n.x + v.y * n.y + v.z * n.z;
}

void Normal::normalize() {
    double length = sqrt(x * x + y * y + z * z);
    x /= length;
    y /= length;
    z /= length;
}


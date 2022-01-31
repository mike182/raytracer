#ifndef __VECTOR3D_HPP__
#define __VECTOR3D_HPP__

class Normal;
class Point3D;

class Vector3D {
public:
    Vector3D(void);
    Vector3D(double a);
    Vector3D(double x, double y, double z);
    Vector3D(const Vector3D& v);
    Vector3D(const Normal& n);
    Vector3D(const Point3D& p);
    virtual ~Vector3D(void);

    Vector3D& operator=(const Vector3D& rhs);
    Vector3D& operator=(const Normal& rhs);
    Vector3D& operator=(const Point3D& rhs);

    Vector3D operator-() const;
    Vector3D operator*(const double a) const;
    Vector3D operator/(const double a) const;
    Vector3D operator+(const Vector3D& v) const;
    Vector3D& operator+=(const Vector3D& v);
    Vector3D operator-(const Vector3D& v) const;
    double operator*(const Vector3D& v) const;
    Vector3D operator^(const Vector3D& v) const;

    double length();
    double len_squared();
    void normalize();
    Vector3D& hat();

public:
    double x, y, z;
};

// lhs prototype
Vector3D operator*(const double a, const Vector3D& v);

inline Vector3D Vector3D::operator-() const {
    return Vector3D(-x, -y, -z);
}

inline Vector3D Vector3D::operator*(const double a) const {
    return Vector3D(x * a, y * a, z * a);
}

inline Vector3D Vector3D::operator/(const double a) const {
    return Vector3D(x / a, y / a, z / a);
}

inline Vector3D Vector3D::operator+(const Vector3D& v) const {
    return Vector3D(x + v.x, y + v.y, z + v.z);
}

inline Vector3D& Vector3D::operator+=(const Vector3D& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    return *this;
}

inline Vector3D Vector3D::operator-(const Vector3D& v) const {
    return Vector3D(x - v.x, y - v.y, z - v.z);
}

inline double Vector3D::operator*(const Vector3D& v) const {
    return x * v.x + y * v.y + z * v.z;
}

inline Vector3D Vector3D::operator^(const Vector3D& v) const {
    return Vector3D(y * v.z - z * v.y,
                    z * v.x - x * v.z,
                    x * v.y - y * v.x);
}

inline double Vector3D::len_squared() {
    return x * x + y * y + z * z;
}

// lhs
inline Vector3D operator*(const double a, const Vector3D& v) {
    return Vector3D(a * v.x, a * v.y, a * v.z);
}

#endif // __VECTOR3D_HPP__

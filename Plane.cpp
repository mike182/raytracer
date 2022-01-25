#include "Plane.hpp"

const double Plane::kEpsilon = 0.00001;

Plane::Plane(void)
    : a(0.0), n(0, 1, 0) { }

Plane::Plane(Point3D point, Normal normal)
    : a(point), n(normal) { }

Plane::Plane(const Plane & plane)
    : a(plane.a), n(plane.n) { }

Plane::~Plane(void)
{
}

Plane & Plane::operator=(const Plane & rhs) {
    if (this == &rhs)
        return *this;

    GeometricObject::operator=(rhs);
    a = rhs.a;
    n = rhs.n;

    return *this;
}

bool Plane::hit(const Ray & ray, double & tmin, ShadeRec & sr) const {
    double t = (a - ray.o) * n / (ray.d * n);

    if (t > kEpsilon) {
        tmin = t;
        sr.normal = n;
        sr.local_hit_point = ray.o + t * ray.d;

        return true;
    }
    else
        return false;
}

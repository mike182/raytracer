#include "Disk.hpp"

// const double Disk::kEpsilon = 0.00001;
const double Disk::kEpsilon = 0.001;

Disk::Disk(void)
    : GeometricObject(),
    center(0, 0, 0),
    radius(1.0),
    normal(0, 1, 0)
{
}

Disk::Disk(const Point3D& c, const double r, const Normal& n)
    : GeometricObject(),
    center(c),
    radius(r),
    normal(n)
{
    normal.normalize();
}

Disk::Disk(const Disk& disk)
    : GeometricObject(),
    center(disk.center),
    radius(disk.radius),
    normal(disk.normal)
{
}

Disk::~Disk(void) {
}

Disk* Disk::clone(void) const {
    return new Disk(*this);
}

Disk& Disk::operator=(const Disk& rhs) {
    if (this == &rhs)
        return *this;
    GeometricObject::operator=(rhs);
    center = rhs.center;
    radius = rhs.radius;
    normal = rhs.normal;
    return *this;
}

bool Disk::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
    float t = (center - ray.o) * normal / (ray.d * normal);

    if (t <= kEpsilon)
        return false;

    Point3D p = ray.o + t * ray.d;

    if (center.d_squared(p) < radius * radius) {
        tmin = t;
        sr.normal = normal;
        sr.local_hit_point = p;
        return true;
    }
    else
        return false;
}

bool Disk::shadow_hit(const Ray& ray, float& tmin) const {
    if (!shadows)
        return false;

    float t = (center - ray.o) * normal / (ray.d * normal);

    if (t <= kEpsilon)
        return false;

    Point3D p = ray.o + t * ray.d;

    if (center.d_squared(p) < radius * radius) {
        tmin = t;
        return true;
    }
    else
        return false;
}

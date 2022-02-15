#include "OpenCone.hpp"

// const double OpenCone::kEpsilon = 0.00001;
const double OpenCone::kEpsilon = 0.001;

OpenCone::OpenCone(void)
    : GeometricObject(),
    y(2.0),
    radius(1.0)
{
}

OpenCone::OpenCone(const double h, const double r)
    :  GeometricObject(),
    y(h),
    radius(r)
{
}

OpenCone::OpenCone(const OpenCone& c)
    : GeometricObject(c),
    y(c.y),
    radius(c.radius)
{
}

OpenCone::~OpenCone(void) {
}

OpenCone* OpenCone::clone(void) const {
    return new OpenCone (*this);
}

OpenCone& OpenCone::operator= (const OpenCone& rhs) {
    if (this == &rhs)
        return *this;

    GeometricObject::operator=(rhs);
    y = rhs.y;
    radius = rhs.radius;
    return *this;
}

// The code reverses the normal when the ray hits the inside surface, allows both
// sides to be shaded, but completely messes up transparency.
bool OpenCone::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
    double t;
    double ox = ray.o.x;
    double oy = ray.o.y;
    double oz = ray.o.z;
    double dx = ray.d.x;
    double dy = ray.d.y;
    double dz = ray.d.z;
    double r = radius;

    double a = (y * y / r * r) * (dx * dx + dz * dz) - dy * dy;
    double b = 2 * (y * y / r * r * (ox * dx + oz * dz) + dy * (y - oy));
    double c = y * y / r * r * (ox * ox + oz * oz) + 2 * oy * y - oy * oy - y * y;
    double disc = b * b - 4.0 * a * c ;

    if (disc < 0.0)
        return false;
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;

        t = (-b - e) / denom; // smaller root

        if (t > kEpsilon) {
            double yhit = oy + t * dy;

            if (yhit >= 0.0 && yhit <= y) {
                tmin = t;
                // sr.normal = Normal(ox + t * dx, oy + t * dy, oz + t * dz);
                sr.normal = Normal(ox + t * dx, 0, oz + t * dz);
                // sr.normal = Normal(y / r * (ox + t * dx), oy + t * dy - y, y / r *(oz + t * dz));
                // sr.normal.normalize();
                // test for hitting from inside
                // if (-ray.d * sr.normal < 0.0)
                    // sr.normal = -sr.normal;
                sr.local_hit_point = ray.o + tmin * ray.d;
                return true;
            }
        }

        t = (-b + e) / denom;    // larger root

        if (t > kEpsilon) {
            double yhit = oy + t * dy;

            if (yhit >= 0.0 && yhit <= y) {
                tmin = t;
                // sr.normal = Normal(ox + t * dx, oy + t * dy, oz + t * dz);
                sr.normal = Normal(ox + t * dx, 0, oz + t * dz);
                // sr.normal = Normal(y / r * (ox + t * dx), oy + t * dy - y, y / r *(oz + t * dz));
                // sr.normal.normalize();
                // test for hitting inside surface
                // if (-ray.d * sr.normal < 0.0)
                    // sr.normal = -sr.normal;
                sr.local_hit_point = ray.o + tmin * ray.d;
                return true;
            }
        }
    }
    return false;
}

bool OpenCone::shadow_hit(const Ray& ray, float& tmin) const {
    if (!shadows)
        return false;

    double t;
    double ox = ray.o.x;
    double oy = ray.o.y;
    double oz = ray.o.z;
    double dx = ray.d.x;
    double dy = ray.d.y;
    double dz = ray.d.z;
    double r = radius;

    double a = (y * y / r * r) * (dx * dx + dz * dz) - dy * dy;
    double b = 2 * (y * y / r * r * (ox * dx + oz * dz) + dy * (y - oy));
    double c = y * y / r * r * (ox * ox + oz * oz) + 2 * oy * y - oy * oy - y * y;
    double disc = b * b - 4.0 * a * c ;

    if (disc < 0.0)
        return false;
    else {
        double e = sqrt(disc);
        double denom = 2.0 * a;

        t = (-b - e) / denom; // smaller root

        if (t > kEpsilon) {
            double yhit = oy + t * dy;

            if (yhit >= 0.0 && yhit <= y) {
                tmin = t;
                return true;
            }
        }

        t = (-b + e) / denom;    // larger root

        if (t > kEpsilon) {
            double yhit = oy + t * dy;

            if (yhit >= 0.0 && yhit <= y) {
                tmin = t;
                return true;
            }
        }
    }
    return false;
}

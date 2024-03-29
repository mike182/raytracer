#include "Rectangle.hpp"
#include "Sampler.hpp"

// const double Rectangle::kEpsilon = 0.00001;
const double Rectangle::kEpsilon = 0.001;

Rectangle::Rectangle(void)
    : GeometricObject(),
    p0(-1, 0, -1),
    a(0, 0, 1),
    b(1, 0, 0),
    normal(0, 1, 0),
    a_len_squared(4.0),
    b_len_squared(4.0),
    area(4.0),
    inv_area(0.25),
    sampler_ptr(nullptr)
{
}

Rectangle::Rectangle(const Point3D& p, const Vector3D& a, const Vector3D& b)
    : GeometricObject(),
    p0(p),
    a(a),
    b(b),
    a_len_squared(a.len_squared()),
    b_len_squared(b.len_squared()),
    area(a.length() * b.length()),
    inv_area(1.0 / area),
    sampler_ptr(nullptr)
{
    normal = a ^ b;
    normal.normalize();
}

Rectangle::Rectangle(const Point3D& p, const Vector3D& a, const Vector3D& b, const Normal& n)
    : GeometricObject(),
    p0(p),
    a(a),
    b(b),
    normal(n),
    a_len_squared(a.len_squared()),
    b_len_squared(b.len_squared()),
    area(a.length() * b.length()),
    inv_area(1.0 / area),
    sampler_ptr(nullptr)
{
    normal.normalize();
}

Rectangle::~Rectangle (void) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
}

Rectangle::Rectangle (const Rectangle& r)
    : GeometricObject(r),
    p0(r.p0),
    a(r.a),
    b(r.b),
    normal(r.normal),
    a_len_squared(r.a_len_squared),
    b_len_squared(r.b_len_squared),
    area(r.area),
    inv_area(r.inv_area)
{
    if(r.sampler_ptr)
        sampler_ptr = r.sampler_ptr->clone();
    else
        sampler_ptr = nullptr;
}

Rectangle* Rectangle::clone(void) const {
    return new Rectangle(*this);
}

Rectangle& Rectangle::operator=(const Rectangle& rhs) {
    if (this == &rhs)
        return *this;
    GeometricObject::operator=(rhs);
    p0 = rhs.p0;
    a = rhs.a;
    b = rhs.b;
    a_len_squared = rhs.a_len_squared;
    b_len_squared = rhs.b_len_squared;
    area = rhs.area;
    inv_area = rhs.inv_area;
    normal = rhs.normal;
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    if (rhs.sampler_ptr)
        sampler_ptr= rhs.sampler_ptr->clone();
    return *this;
}

BBox Rectangle::get_bounding_box(void) {
    double delta = 0.0001;

    return BBox(min(p0.x, p0.x + a.x + b.x) - delta, max(p0.x, p0.x + a.x + b.x) + delta,
                min(p0.y, p0.y + a.y + b.y) - delta, max(p0.y, p0.y + a.y + b.y) + delta,
                min(p0.z, p0.z + a.z + b.z) - delta, max(p0.z, p0.z + a.z + b.z) + delta);
}

bool Rectangle::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
    double t = (p0 - ray.o) * normal / (ray.d * normal);

    if (t <= kEpsilon)
        return false;

    Point3D p = ray.o + t * ray.d;
    Vector3D d = p - p0;

    double ddota = d * a;

    if (ddota < 0.0 || ddota > a_len_squared)
        return false;

    double ddotb = d * b;

    if (ddotb < 0.0 || ddotb > b_len_squared)
        return false;

    tmin = t;
    sr.normal = normal;
    sr.local_hit_point = p;
    return true;
}

bool Rectangle::shadow_hit(const Ray& ray, float& tmin) const {
    if (!shadows)
        return false;

    double t = (p0 - ray.o) * normal / (ray.d * normal);

    if (t <= kEpsilon)
        return false;

    Point3D p = ray.o + t * ray.d;
    Vector3D d = p - p0;

    double ddota = d * a;

    if (ddota < 0.0 || ddota > a_len_squared)
        return false;

    double ddotb = d * b;

    if (ddotb < 0.0 || ddotb > b_len_squared)
        return false;

    tmin = t;
    return true;
}
Point3D Rectangle::sample(void) {
    Point2D sample_point = sampler_ptr->sample_unit_square();
    return p0 + sample_point.x * a + sample_point.y * b;
}

Normal Rectangle::get_normal([[maybe_unused]]const Point3D& p) const {
    return normal;
}

float Rectangle::pdf([[maybe_unused]]const ShadeRec& sr) {
    return inv_area;
}

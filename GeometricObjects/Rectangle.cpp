#include "Rectangle.hpp"
#include "Sampler.hpp"

const double Rectangle::kEpsilon = 0.001;

Rectangle::Rectangle(void)
    : GeometricObject(),
    p(-1, 0, -1),
    a(0, 0, 2), b(2, 0, 0),
    a_len_squared(4.0),
    b_len_squared(4.0),
    normal(0, 1, 0),
    area(4.0),
    inv_area(0.25),
    sampler_ptr(NULL)
{
}

Rectangle::Rectangle(const Point3D& p, const Vector3D& a, const Vector3D& b)
    : GeometricObject(),
    p(p),
    a(a),
    b(b),
    a_len_squared(a.len_squared()),
    b_len_squared(b.len_squared()),
    area(a.length() * b.length()),
    inv_area(1.0 / area),
    sampler_ptr(NULL)
{
    normal = a ^ b;
    normal.normalize();
}

Rectangle::Rectangle(const Point3D& p, const Vector3D& a, const Vector3D& b, const Normal& n)
    : GeometricObject(),
    p(p),
    a(a),
    b(b),
    a_len_squared(a.len_squared()),
    b_len_squared(b.len_squared()),
    normal(n),
    area(a.length() * b.length()),
    inv_area(1.0 / area),
    sampler_ptr(NULL)
{
    normal.normalize();
}

Rectangle* Rectangle::clone(void) const {
    return new Rectangle(*this);
}

Rectangle::Rectangle (const Rectangle& r)
    : GeometricObject(r),
    p(r.p),
    a(r.a),
    b(r.b),
    a_len_squared(r.a_len_squared),
    b_len_squared(r.b_len_squared),
    normal(r.normal),
    area(r.area),
    inv_area(r.inv_area)
{
    if(r.sampler_ptr)
        sampler_ptr = r.sampler_ptr->clone();
    else
        sampler_ptr = NULL;
}

Rectangle& Rectangle::operator=(const Rectangle& rhs) {
    if (this == &rhs)
        return *this;
    GeometricObject::operator=(rhs);
    p = rhs.p;
    a = rhs.a;
    b = rhs.b;
    a_len_squared = rhs.a_len_squared;
    b_len_squared = rhs.b_len_squared;
    area = rhs.area;
    inv_area = rhs.inv_area;
    normal = rhs.normal;
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = NULL;
    }
    if (rhs.sampler_ptr) {
        sampler_ptr= rhs.sampler_ptr->clone();
    }
    return *this;
}

Rectangle::~Rectangle (void) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = NULL;
    }
}

// BBox Rectangle::get_bounding_box(void) {
//     double delta = 0.0001;

//     return(BBox(min(p.x, p.x + a.x + b.x) - delta, max(p.x, p.x + a.x + b.x) + delta,
//                 min(p.y, p.y + a.y + b.y) - delta, max(p.y, p.y + a.y + b.y) + delta,
//                 min(p.z, p.z + a.z + b.z) - delta, max(p.z, p.z + a.z + b.z) + delta));
// }

bool Rectangle::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
    double t = (p - ray.o) * normal / (ray.d * normal);

    if (t <= kEpsilon)
        return false;

    Point3D p = ray.o + t * ray.d;
    Vector3D d = p - p;

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

// Point3D Rectangle::sample(void) {
    // Point2D sample_point = sampler_ptr->sample_unit_square();
    // return p + sample_point.x * a + sample_point.y * b;
// }

// Normal Rectangle::get_normal(const Point3D& p) {
//     return normal;
// }

// float Rectangle::pdf(const ShadeRec& sr) {
//     return inv_area;
// }

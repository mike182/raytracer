#include "Box.hpp"

Box::Box(Point3D c0, Point3D c1)
    : GeometricObject(),
    p0(c0),
    p1(c1)
{
}

Box::Box(const Box& box)
    : GeometricObject(box),
    p0(box.p0),
    p1(box.p1)
{
}

Box* Box::clone(void) const{
    return new Box(*this);
}

Box::~Box (void) {
}

Box& Box::operator=(const Box& rhs){
    if(this == &rhs){
        return *this;
    }
    GeometricObject::operator=(rhs);
    p0 = rhs.p0;
    p1 = rhs.p1;
    return *this;
}

bool Box::hit(const Ray& ray, double& tmin, ShadeRec& sr) const {
    double ox = ray.o.x;
    double oy = ray.o.y;
    double oz = ray.o.z;

    double dx = ray.d.x;
    double dy = ray.d.y;
    double dz = ray.d.z;

    double tx_min, ty_min, tz_min;
    double tx_max, ty_max, tz_max;

    double a = 1.0 / dx;
    if (a >= 0) {
        tx_min = (p0.x - ox) * a;
        tx_max = (p1.x - ox) * a;
    }
    else {
        tx_min = (p1.x - ox) * a;
        tx_max = (p0.x - ox) * a;
    }

    double b = 1.0 / dy;
    if (b >= 0) {
        ty_min = (p0.y - oy) * b;
        ty_max = (p1.y - oy) * b;
    }
    else {
        ty_min = (p1.y - oy) * b;
        ty_max = (p0.y - oy) * b;
    }

    double c = 1.0 / dz;
    if (c >= 0) {
        tz_min = (p0.z - oz) * c;
        tz_max = (p1.z - oz) * c;
    }
    else {
        tz_min = (p1.z - oz) * c;
        tz_max = (p0.z - oz) * c;
    }

    double t0, t1;
    int face_in, face_out;

    // find largest entering t value

    if (tx_min > ty_min) {
        t0 = tx_min;
        face_in = (a >= 0.0) ? 0 : 3;
    }
    else {
        t0 = ty_min;
        face_in = (b >= 0.0) ? 1 : 4;
    }

    if (tz_min > t0) {
        t0 = tz_min;
        face_in = (c >= 0.0) ? 2 : 5;
    }

    // find smallest exiting t value

    if (tx_max < ty_max) {
        t1 = tx_max;
        face_out = (a >= 0.0) ? 3 : 0;
    }
    else {
        t1 = ty_max;
        face_out = (b >= 0.0) ? 4 : 1;
    }

    if (tz_max < t1) {
        t1 = tz_max;
        face_out = (c >= 0.0) ? 5 : 2;
    }

    if (t0 < t1 && t1 > kEpsilon) {  // condition for a hit
        if (t0 > kEpsilon) {
            tmin = t0; // ray hits outside surface
            sr.normal = get_normal(face_in);
        }
        else {
            tmin = t1; // ray hits inside surface
            sr.normal = get_normal(face_out);
        }

        sr.local_hit_point = ray.o + tmin * ray.d;
        return true;
    }
    return false;
}

bool Box::shadow_hit(const Ray& ray, float& tmin) const {
    double ox = ray.o.x;
    double oy = ray.o.y;
    double oz = ray.o.z;

    double dx = ray.d.x;
    double dy = ray.d.y;
    double dz = ray.d.z;

    double tx_min, ty_min, tz_min;
    double tx_max, ty_max, tz_max;

    double a = 1.0 / dx;
    if (a >= 0) {
        tx_min = (p0.x - ox) * a;
        tx_max = (p1.x - ox) * a;
    }
    else {
        tx_min = (p1.x - ox) * a;
        tx_max = (p0.x - ox) * a;
    }

    double b = 1.0 / dy;
    if (b >= 0) {
        ty_min = (p0.y - oy) * b;
        ty_max = (p1.y - oy) * b;
    }
    else {
        ty_min = (p1.y - oy) * b;
        ty_max = (p0.y - oy) * b;
    }

    double c = 1.0 / dz;
    if (c >= 0) {
        tz_min = (p0.z - oz) * c;
        tz_max = (p1.z - oz) * c;
    }
    else {
        tz_min = (p1.z - oz) * c;
        tz_max = (p0.z - oz) * c;
    }

    double t0, t1;

    // find largest entering t value

    if (tx_min > ty_min)
        t0 = tx_min;
    else
        t0 = ty_min;

    if (tz_min > t0)
        t0 = tz_min;

    // find smallest exiting t value

    if (tx_max < ty_max)
        t1 = tx_max;
    else
        t1 = ty_max;

    if (tz_max < t1)
        t1 = tz_max;

    if (t0 < t1 && t1 > kEpsilon) {  // condition for a hit
        if (t0 > kEpsilon)
            tmin = t0; // ray hits outside surface
        else
            tmin = t1; // ray hits inside surface
        return true;
    }
    return false;
}

Normal Box::get_normal(const int face_hit) const {
    switch (face_hit) {
        case 0: return Normal(-1, 0, 0); // -x face
        case 1: return Normal(0, -1, 0); // -y face
        case 2: return Normal(0, 0, -1); // -z face
        case 3: return Normal(1, 0, 0); // +x face
        case 4: return Normal(0, 1, 0); // +y face
        case 5: return Normal(0, 0, 1); // +z face
    }
    // Avoid "Non-void function does not return a value in all control paths" [-Wreturn-type]
    return Normal(0, 0, 0);
}

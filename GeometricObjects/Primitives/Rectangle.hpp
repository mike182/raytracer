#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "GeometricObject.hpp"

class Sampler;

class Rectangle: public GeometricObject {
public:
    Rectangle(void);
    Rectangle(const Point3D& p0, const Vector3D& a, const Vector3D& b);
    Rectangle(const Point3D& p0, const Vector3D& a, const Vector3D& b, const Normal& n);
    Rectangle(const Rectangle& r);
    virtual Rectangle* clone(void) const;
    virtual ~Rectangle(void);

    Rectangle& operator= (const Rectangle& rhs);

    BBox get_bounding_box(void);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;

    // the following functions are used when the rectangle is a light source
    Point3D sample(void);
    virtual Normal get_normal(const Point3D& p) const;
    virtual float pdf(const ShadeRec& sr);

private:
    Point3D p0; // corner vertex
    Vector3D a; // side
    Vector3D b; // side
    Normal normal;
    double a_len_squared;
    double b_len_squared;

    // for rectangular lights
    float area;
    float inv_area;
    Sampler* sampler_ptr;

private:
    static const double kEpsilon;
};

#endif // __RECTANGLE_HPP__

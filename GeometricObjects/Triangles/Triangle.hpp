#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "GeometricObject.hpp"

class Triangle: public GeometricObject {
public:
    Triangle(void);
    Triangle(const Point3D& a, const Point3D& b, const Point3D& c);
    virtual Triangle* clone(void) const;
    Triangle(const Triangle& triangle);
    virtual ~Triangle(void);

    Triangle& operator= (const Triangle& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;

    // virtual BBox get_bounding_box(void);
    void compute_normal(void);

private:
    Point3D v0, v1, v2;
    Normal normal;

private:
    static const double kEpsilon;
};

#endif // __TRIANGLE_HPP__

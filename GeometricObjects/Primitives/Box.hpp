#ifndef __BOX_HPP__
#define __BOX_HPP__

#include "GeometricObject.hpp"

class Box: public GeometricObject {
public:
    Box(void);
    Box(const Point3D c0, const Point3D c1);
    Box(const Box& box);
    virtual Box* clone(void) const;
    virtual ~Box(void);

    virtual Box& operator=(const Box& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;
    virtual Normal get_normal(const int face_hit) const;

private:
    Point3D p0; // minimum coordinate corner
    Point3D p1; // maximum coordinate corner
};

#endif // __BOX_HPP__

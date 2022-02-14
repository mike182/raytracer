#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include "GeometricObject.hpp"

class Plane : public GeometricObject {
public:
    Plane(void);
    Plane(const Point3D& p, const Normal& n);
    Plane(const Plane& plane);
    virtual Plane* clone(void) const;
    virtual ~Plane(void);

    Plane& operator=(const Plane& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;

private:
    Point3D a;
    Normal n;

private:
    static const double kEpsilon; // shadow & secondary ray
};

#endif // __PLANE_HPP__

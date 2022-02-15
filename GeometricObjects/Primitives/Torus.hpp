#ifndef __TORUS_HPP__
#define __TORUS_HPP__

#include "GeometricObject.hpp"

class Torus: public GeometricObject {
public:
    Torus(void);
    Torus(const double _a, const double _b);
    Torus(const Torus& torus);
    virtual Torus* clone(void) const;
    virtual ~Torus(void);

    Torus& operator=(Torus& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;
    Normal compute_normal(const Point3D& p) const;

private:
    double a; // swept radius
    double b; // tube radius
    // BBox bbox; // the bounding box

private:
    static const double kEpsilon;
};

#endif // __TORUS_HPP__

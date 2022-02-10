#ifndef __SPERE_HPP__
#define __SPERE_HPP__

#include "GeometricObject.hpp"

class Sphere : public GeometricObject {
public:
    Sphere(void);
    Sphere(Point3D center, double radius);
    Sphere(const Sphere& sphere);
    virtual Sphere* clone(void) const;
    virtual ~Sphere(void);

    Sphere& operator=(const Sphere& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;
    void set_center(const Point3D& c);
    void set_center(const double x, const double y, const double z);
    void set_radius(const double r);

public:
    Point3D center;
    double radius;
    static const double kEpsilon;
};

inline void Sphere::set_center(const Point3D& c) {
    center = c;
}

inline void Sphere::set_center(const double x, const double y, const double z) {
    center.x = x;
    center.y = y;
    center.z = z;
}

inline void Sphere::set_radius(const double r) {
    radius = r;
}

#endif // __SPERE_HPP__

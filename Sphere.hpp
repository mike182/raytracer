#ifndef __SPERE_HPP__
#define __SPERE_HPP__

#include "GeometricObject.hpp"
#include "Point3D.hpp"
#include "Constants.h"

class Sphere : public GeometricObject {
public:
    Sphere(void);
    Sphere(Point3D center, double radius);
    Sphere(const Sphere & sphere);
    virtual ~Sphere(void);

    Sphere & operator=(const Sphere & rhs);


    void set_center(const Point3D & c);
    void set_center(const double x, const double y, const double z);
    void set_radius(const double r);

    virtual bool hit(const Ray & ray, double & tmin, ShadeRec & sr) const;

public:
    Point3D center;
    double radius;
    static const double kEpsilon;
};

#endif // __SPERE_HPP__

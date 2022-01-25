#ifndef __PLANE_HPP__
#define __PLANE_HPP__

#include "GeometricObject.hpp"
#include "Point3D.hpp"
#include "Normal.hpp"
#include "Constants.h"

class Plane : public GeometricObject {
public:
    Plane(void);
    Plane(Point3D p, Normal n);
    Plane(const Plane & obj);
    virtual ~Plane(void);

    Plane & operator=(const Plane & rhs);

    virtual bool hit(const Ray & ray, double & t, ShadeRec & s) const;

private:
    Point3D a;
    Normal n;
    static const double kEpsilon;
};

#endif // __PLANE_HPP__

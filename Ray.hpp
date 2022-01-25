#ifndef __RAY_HPP__
#define __RAY_HPP__

#include "Point3D.hpp"
#include "Vector3D.hpp"

class Ray {
public:
    Ray(void);
    Ray(const Point3D & o, const Vector3D & d);
    Ray(const Ray & ray);
    virtual ~Ray(void);

    Ray & operator=(const Ray & rhs);

public:
    Point3D o;
    Vector3D d;
};

#endif // __RAY_HPP__

#ifndef __SHADEREC_HPP__
#define __SHADEREC_HPP__

#include "Point3D.hpp"
#include "Normal.hpp"
#include "Ray.hpp"
#include "RGBColor.hpp"

class World;

class ShadeRec {
public:
    ShadeRec(void) = delete;
    ShadeRec(World& w);
    ShadeRec(const ShadeRec& sr);
    virtual ~ShadeRec(void);

    ShadeRec& operator=(const ShadeRec& rhs) = delete;

public:
    bool hit_an_object;
    // Material ?
    Point3D hit_point;
    Point3D local_hit_point;
    Normal normal;
    Ray ray;
    int depth;
    RGBColor color;
    double t;
    float u, v;
    World& w;
};

#endif // __SHADEREC_HPP__

#ifndef __SHADEREC_HPP__
#define __SHADEREC_HPP__

#include "Point3D.hpp"
#include "Normal.hpp"
#include "RGBColor.hpp"

#include "World.hpp"

class ShadeRec
{
public:
    ShadeRec(void) = delete;
    ShadeRec(World & w);
    ShadeRec(const ShadeRec & sr);
    virtual ~ShadeRec(void);

    ShadeRec & operator=(const ShadeRec & rhs) = delete;

public:
    bool hit_an_object;
    Point3D local_hit_point;
    Normal normal;
    RGBColor color;
    World & w;
};

#endif // __SHADEREC_HPP__

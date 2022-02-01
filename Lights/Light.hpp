#ifndef __LIGHT_HPP__
#define __LIGHT_HPP__

#include "Constants.h"
#include "Vector3D.hpp"
#include "RGBColor.hpp"
#include "Ray.hpp"

class ShadeRec;

class Light
{
public:
    Light(void);
    Light(const Light& l);
    virtual Light* clone(void) const = 0;
    virtual ~Light(void);

    Light & operator=(const Light & rhs);

    virtual Vector3D get_direction(ShadeRec& sr) = 0;
    virtual RGBColor L(ShadeRec& sr);
};

#endif // __LIGHT_HPP__

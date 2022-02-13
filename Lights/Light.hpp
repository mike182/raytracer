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
    void set_shadows(const bool sh);
    bool cast_shadows() const;
    virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

protected:
    bool shadows;
};

inline void Light::set_shadows(const bool sh) {
    shadows = sh;
}

inline bool Light::cast_shadows() const {
    return shadows;
}

#endif // __LIGHT_HPP__

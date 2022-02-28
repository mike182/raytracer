#ifndef __EMISSIVE_HPP__
#define __EMISSIVE_HPP__

#include "Material.hpp"

class Emissive: public Material {
public:
    Emissive(void);
    Emissive(const Emissive& m);
    // virtual Emissive* clone(void) const;
    virtual Material* clone(void) const;
    virtual ~Emissive(void);

    Emissive& operator=(const Emissive& rhs);

    virtual RGBColor area_light_shade(ShadeRec& sr);
    virtual RGBColor shade(ShadeRec& sr);
    virtual RGBColor get_Le(ShadeRec& sr) const;
    void set_ce(const float r, const float g, const float b);
    void set_ce(const float c);
    void set_ce(const RGBColor& c);
    void scale_radiance(const float _ls);

private:
    float ls;
    RGBColor ce;
};

inline void Emissive::set_ce(const RGBColor& c) {
    ce.r = c.r;
    ce.g = c.g;
    ce.b = c.b;
}

inline void Emissive::set_ce(const float r, const float g, const float b) {
    ce.r = r;
    ce.g = g;
    ce.b = b;
}

inline void Emissive::set_ce(const float c) {
    ce.r = c;
    ce.g = c;
    ce.b = c;
}

inline void Emissive::scale_radiance(const float _ls) {
    ls = _ls;
}

#endif // __EMISSIVE_HPP__

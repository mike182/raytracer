#ifndef __AMBIENT_HPP__
#define __AMBIENT_HPP__

#include "Light.hpp"

class Ambient : public Light {
public:
    Ambient(void);
    Ambient(const Ambient& a);
    virtual Light* clone(void) const;
    virtual ~Ambient(void);

    Ambient & operator=(const Ambient & rhs);

    void scale_radiance(const float b);
    void set_color(const float c);
    void set_color(const RGBColor& c);
    void set_color(const float r, const float g, const float b);
    RGBColor get_color() const;
    virtual Vector3D get_direction(ShadeRec& s);
    virtual RGBColor L(ShadeRec& s);
    virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

public:
    float ls;
    RGBColor color;
};

inline void Ambient::scale_radiance(const float b) {
    ls = b;
}

inline void Ambient::set_color(const float c) {
    color.r = c; color.g = c; color.b = c;
}

inline void Ambient::set_color(const RGBColor& c) {
    color = c;
}

inline void Ambient::set_color(const float r, const float g, const float b) {
    color.r = r; color.g = g; color.b = b;
}

inline RGBColor Ambient::get_color() const {
    return color;
}

#endif // __AMBIENT_HPP__

#ifndef __POINTLIGHT_HPP__
#define __POINTLIGHT_HPP__

#include "Light.hpp"
#include "Vector3D.hpp"
#include "RGBColor.hpp"
// #include "World.hpp" // shadows
#include "ShadeRec.hpp"

class PointLight: public Light {
public:
    PointLight(void);
    PointLight(const PointLight& dl);
    virtual Light* clone(void) const;
    virtual ~PointLight(void);

    PointLight& operator= (const PointLight& rhs);

    void scale_radiance(const float b);
    void set_color(const float c);
    void set_color(const RGBColor& c);
    void set_color(const float r, const float g, const float b);
    void set_location(Vector3D d);
    void set_location(float dx, float dy, float dz);
    virtual Vector3D get_direction(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr) const;

private:
    float ls;
    RGBColor color;
    Vector3D location;
};

inline void PointLight::scale_radiance(const float b) {
    ls = b;
}

inline void PointLight::set_color(const float c) {
    color.r = c; color.g = c; color.b = c;
}

inline void PointLight::set_color(const RGBColor& c) {
    color = c;
}

inline void PointLight::set_color(const float r, const float g, const float b) {
    color.r = r; color.g = g; color.b = b;
}

inline void PointLight::set_location(Vector3D d) {
    location = d;
}

inline void PointLight::set_location(float dx, float dy, float dz) {
    location.x = dx; location.y = dy; location.z = dz;
}

#endif // __POINTLIGHT_HPP__

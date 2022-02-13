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
    PointLight(const PointLight& pl);
    virtual Light* clone(void) const;
    virtual ~PointLight(void);

    PointLight& operator= (const PointLight& rhs);

    void scale_radiance(const float b);
    void set_color(const float c);
    void set_color(const RGBColor& c);
    void set_color(const float r, const float g, const float b);
    void set_location(Point3D& p);
    void set_location(float x, float y, float z);
    virtual Vector3D get_direction(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

private:
    float ls;
    RGBColor color;
    Point3D location;
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

inline void PointLight::set_location(Point3D& p) {
    location = p;
}

inline void PointLight::set_location(float x, float y, float z) {
    location.x = x;
    location.y = y;
    location.z = z;
}

#endif // __POINTLIGHT_HPP__

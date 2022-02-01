#include "PointLight.hpp"

PointLight::PointLight(void)
    : Light(),
    ls(1.0),
    color(1.0),
    location(0, 1, 0)
{
}

PointLight::PointLight(const PointLight& dl)
    : Light(dl),
    ls(dl.ls),
    color(dl.color),
    location(dl.location)
{
}

PointLight::~PointLight(void) {
}

Light* PointLight::clone(void) const {
    return (new PointLight(*this));
}

PointLight& PointLight::operator= (const PointLight& rhs) {
    if (this == &rhs)
        return (*this);

    Light::operator= (rhs);
    ls		= rhs.ls;
    color 	= rhs.color;
    location 	= rhs.location;
    return (*this);
}

Vector3D PointLight::get_direction([[maybe_unused]] ShadeRec& sr) {
    return ((location - sr.hit_point).hat());
}

RGBColor PointLight::L([[maybe_unused]] ShadeRec& s) const {
    return (ls * color);
}

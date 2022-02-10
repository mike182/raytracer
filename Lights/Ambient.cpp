#include "Ambient.hpp"

Ambient::Ambient(void)
    : Light(),
    ls(1.0),
    color(1.0)
{
}

Ambient::Ambient(const Ambient& a)
    : Light(),
    ls(a.ls),
    color(a.color)
{
}

Ambient::~Ambient(void) {
}

Light* Ambient::clone(void) const {
    return new Ambient(*this);
}

Ambient & Ambient::operator=(const Ambient & rhs) {
    if (this == &rhs)
        return *this;
    Light::operator=(rhs);
    ls = rhs.ls;
    color = rhs.color;
    return *this;
}

Vector3D Ambient::get_direction([[maybe_unused]] ShadeRec& sr) {
    return Vector3D(0.0);
}

RGBColor Ambient::L([[maybe_unused]] ShadeRec& sr) const {
    return ls * color;
}

bool Ambient::in_shadow([[maybe_unused]]const Ray& ray, [[maybe_unused]]const ShadeRec& sr) const {
    return false;
}

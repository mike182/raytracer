#include "Emissive.hpp"

Emissive::Emissive(void):
    Material(),
    ls(1.0),
    ce(1.0) {
    }

Emissive::Emissive(const Emissive& m):
    Material(m),
    ls(m.ls),
    ce(m.ce) {
    }

// Emissive* Emissive::clone(void) const {
Material* Emissive::clone(void) const {
    return new Emissive(*this);
}

Emissive::~Emissive(void) {
}

Emissive& Emissive::operator=(const Emissive& rhs) {
    if (this == &rhs)
        return *this;
    Material::operator=(rhs);
    ls = rhs.ls;
    ce = rhs.ce;
    return *this;
}

RGBColor Emissive::get_Le([[maybe_unused]]ShadeRec& sr) const {
    return ls * ce;
}

RGBColor Emissive::shade(ShadeRec& sr) {
    return sr.color;
}

RGBColor Emissive::area_light_shade(ShadeRec& sr) {
    if (-sr.normal * sr.ray.d > 0.0)
        return ls * ce;
    else
        return black;
}

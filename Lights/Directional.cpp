#include "Directional.hpp"

Directional::Directional(void)
    : Light(),
    ls(1.0),
    color(1.0),
    dir(0, 1, 0)
{
}

Directional::Directional(const Directional& dl)
    : Light(dl),
    ls(dl.ls),
    color(dl.color),
    dir(dl.dir)
{
}

Directional::~Directional(void) {
}

Light* Directional::clone(void) const {
    return new Directional(*this);
}

Directional& Directional::operator= (const Directional& rhs) {
    if (this == &rhs)
        return *this;

    Light::operator= (rhs);
    ls		= rhs.ls;
    color 	= rhs.color;
    dir 	= rhs.dir;
    return *this;
}

Vector3D Directional::get_direction([[maybe_unused]] ShadeRec& sr) {
    return dir;
}

RGBColor Directional::L([[maybe_unused]] ShadeRec& s) const {
    return ls * color;
}

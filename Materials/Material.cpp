#include "Material.hpp"

Material::Material(void)
    : in_shadow(true)
{
}

Material::Material([[maybe_unused]] const Material& m) {
    in_shadow = m.in_shadow;
}

Material::~Material(void) {
}

Material& Material::operator=(const Material& rhs) {
    if (this == &rhs)
        return *this;

    in_shadow = rhs.in_shadow;

    return *this;
}

RGBColor Material::shade([[maybe_unused]] ShadeRec& sr) {
    return black;
}


RGBColor Material::area_light_shade([[maybe_unused]] ShadeRec& sr) {
    return black;
}


RGBColor Material::get_Le([[maybe_unused]] ShadeRec& sr) const {
    return black;
}

#include "Material.hpp"

Material::Material(void)
{
}

Material::Material([[maybe_unused]] const Material& m)
{
}

Material::~Material(void)
{
}

Material& Material::operator=(const Material& rhs) {
    if (this == &rhs)
        return *this;
    return *this;
}

RGBColor Material::shade([[maybe_unused]] ShadeRec& sr) {
    return black;
}

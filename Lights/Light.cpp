#include "Light.hpp"
#include "World.hpp"

Light::Light(void)
    : shadows(false)
{
}

Light::Light([[maybe_unused]] const Light& l) {
    shadows = l.shadows;
}

Light::~Light(void) {
}

Light & Light::operator=(const Light & rhs) {
    if (this == &rhs)
        return *this;
    shadows = rhs.shadows;
    return *this;
}

RGBColor Light::L([[maybe_unused]] ShadeRec& sr) const {
    return black;
}

bool Light::in_shadow([[maybe_unused]]const Ray& ray, [[maybe_unused]]const ShadeRec& sr) const {
    return false;
}

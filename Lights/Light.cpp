#include "Light.hpp"

Light::Light(void) {
}

Light::Light([[maybe_unused]] const Light& l) {
}

Light::~Light(void) {
}

Light & Light::operator=(const Light & rhs) {
    if (this == &rhs)
        return *this;
    return *this;
}

RGBColor Light::L([[maybe_unused]] ShadeRec& sr) {
    return black;
}

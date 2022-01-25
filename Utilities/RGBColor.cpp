#include "RGBColor.hpp"

#include <cmath>

RGBColor::RGBColor(void)
    : r(0.0), g(0.0), b(0.0) { }

RGBColor::RGBColor(float a)
    : r(a), g(a), b(a) { }

RGBColor::RGBColor(float r, float g, float b)
    : r(r), g(g), b(b) { }

RGBColor::RGBColor(const RGBColor & c)
    : r(c.r), g(c.g), b(c.b) { }

RGBColor::~RGBColor(void)
{
}

RGBColor & RGBColor::operator=(const RGBColor & rhs) {
    if (this == &rhs)
        return *this;

    r = rhs.r;
    g = rhs.g;
    b = rhs.b;

    return *this;
}

RGBColor RGBColor::powc(float p) const {
    return RGBColor(pow(r, p), pow(g, p), pow(b, p));
}

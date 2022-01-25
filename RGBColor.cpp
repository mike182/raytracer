#include "RGBColor.hpp"

RGBColor::RGBColor(void)
    : r(0.0), g(0.0), b(0.0), a(0.0) { }

RGBColor::RGBColor(float a)
    : r(a), g(a), b(a), a(0.0) { }

RGBColor::RGBColor(float r, float g, float b)
    : r(r), g(g), b(b), a(0.0) { }

RGBColor::RGBColor(float r, float g, float b, float a)
    : r(r), g(g), b(b), a(a) { }

RGBColor::RGBColor(const RGBColor & c)
    : r(c.r), g(c.g), b(c.b), a(0.0) { }

RGBColor::~RGBColor(void)
{
}

RGBColor & RGBColor::operator=(const RGBColor & rhs) {
    if (this == &rhs)
        return *this;

    r = rhs.r;
    g = rhs.g;
    b = rhs.b;
    a = rhs.a;

    return *this;
}


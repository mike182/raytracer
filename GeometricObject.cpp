#include "GeometricObject.hpp"
#include "RGBColor.hpp"
#include "Constants.h"

GeometricObject::GeometricObject(void)
    : color(black) { }

GeometricObject::GeometricObject(const GeometricObject & obj)
    : color(obj.color) { }

GeometricObject::~GeometricObject(void)
{
}

GeometricObject & GeometricObject::operator=(const GeometricObject & rhs) {
    if (this == &rhs)
        return *this;

    color = rhs.color;

    return *this;
}

// tmp
void GeometricObject::set_color(RGBColor & c) {
    color = c;
}

// tmp
void GeometricObject::set_color(const float r, const float g, const float b) {
    color.r = r;
    color.g = g;
    color.b = b;
}

// tmp
RGBColor GeometricObject::get_color() {
    return color;
}


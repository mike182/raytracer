#include "Checker3D.hpp"
#include "Constants.h"
#include <cmath>

Checker3D::Checker3D(void)
    : Texture(),
    color1(1),
    color2(0.5),
    size(1)
{
}

Checker3D::Checker3D(const Checker3D& ck)
    : Texture(ck),
    color1(ck.color1),
    color2(ck.color2),
    size(ck.size)
{
}

Checker3D* Checker3D::clone(void) const {
    return new Checker3D(*this);
}

Checker3D::~Checker3D(void) {
}

Checker3D& Checker3D::operator= (const Checker3D& rhs) {
    if (this == &rhs)
        return *this;

    Texture::operator=(rhs);
    size = rhs.size;
    color1 = rhs.color1;
    color2 = rhs.color2;
    return *this;
}

RGBColor Checker3D::get_color(const ShadeRec& sr) const {
    double eps = -0.000187453738; // small random number
    double x = sr.local_hit_point.x + eps;
    double y = sr.local_hit_point.y + eps;
    double z = sr.local_hit_point.z + eps;

    if (((int)floor(x / size) + (int)floor(y / size) + (int)floor(z / size)) % 2 == 0)
        return (color1);
    else
        return (color2);
}

#include "ConstantColor.hpp"
#include "Constants.h"

ConstantColor::ConstantColor(void)
    : Texture(),
    color(white)
{
}

ConstantColor::ConstantColor(const RGBColor& c)
    : Texture(),
    color(c)
{
}

ConstantColor::ConstantColor(const float c)
    : Texture(),
    color(c)
{
}

ConstantColor::ConstantColor(const ConstantColor& cc)
    : Texture(cc),
    color(cc.color)
{
}

ConstantColor* ConstantColor::clone(void) const {
    return new ConstantColor(*this);
}

ConstantColor::~ConstantColor(void) {
}

ConstantColor& ConstantColor::operator=(const ConstantColor& rhs) {
    if (this == &rhs)
        return *this;

    Texture::operator=(rhs);
    color = rhs.color;
    return *this;
}

RGBColor ConstantColor::get_color([[maybe_unused]]const ShadeRec& sr) const {
    return color;
}

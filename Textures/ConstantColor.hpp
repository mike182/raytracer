#ifndef __CONSTANTCOLOR_HPP__
#define __CONSTANTCOLOR_HPP__

#include "Texture.hpp"

class ConstantColor : public Texture {
public:
    ConstantColor(void);
    ConstantColor(const RGBColor& c);
    ConstantColor(const float c);
    ConstantColor(const ConstantColor& cc);
    virtual ConstantColor* clone(void) const;
    virtual ~ConstantColor(void);

    ConstantColor& operator=(const ConstantColor& rhs);

    void set_color(RGBColor& c);
    void set_color(float c);
    void set_color(float r, float g, float b);
    virtual RGBColor get_color(const ShadeRec& sr) const;

private:
    RGBColor color;
};

inline void ConstantColor::set_color(RGBColor& c) {
    color = c;
}

inline void ConstantColor::set_color(float c) {
    color = c;
}

inline void ConstantColor::set_color(float r, float g, float b) {
    color.r = r;
    color.g = g;
    color.b = b;
}

#endif // __CONSTANTCOLOR_HPP__

#ifndef __RGBCOLOR_HPP__
#define __RGBCOLOR_HPP__

class RGBColor {
public:
    RGBColor(void);
    RGBColor(float a);
    RGBColor(float r, float g, float b);
    RGBColor(float r, float g, float b, float a);
    RGBColor(const RGBColor & c);
    virtual ~RGBColor(void);

    RGBColor & operator=(const RGBColor & rhs);

public:
    float r, g, b, a;
};

#endif // __RGBCOLOR_HPP__

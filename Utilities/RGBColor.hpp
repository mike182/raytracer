#ifndef __RGBCOLOR_HPP__
#define __RGBCOLOR_HPP__

class RGBColor {
public:
    RGBColor(void);
    RGBColor(float a);
    RGBColor(float r, float g, float b);
    RGBColor(const RGBColor & c);
    virtual ~RGBColor(void);

    RGBColor & operator=(const RGBColor & rhs);

    RGBColor powc(float p) const;

public:
    float r, g, b;
};

#endif // __RGBCOLOR_HPP__

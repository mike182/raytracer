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

    RGBColor operator+(const RGBColor & c) const;
    RGBColor & operator+=(const RGBColor & c);
    RGBColor operator*(const float a) const;
    RGBColor & operator*=(const float a);
    RGBColor operator/(const float a) const;
    RGBColor & operator/=(const float a);
    RGBColor operator*(const RGBColor & c) const;
    bool operator==(const RGBColor & c) const;

    RGBColor powc(float p) const;
    float average() const;

    void to_255(); // tmp

public:
    float r, g, b;
};

#endif // __RGBCOLOR_HPP__

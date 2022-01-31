#ifndef __RGBCOLOR_HPP__
#define __RGBCOLOR_HPP__

class RGBColor {
public:
    RGBColor(void);
    RGBColor(float a);
    RGBColor(float r, float g, float b);
    RGBColor(const RGBColor& c);
    virtual ~RGBColor(void);

    RGBColor& operator=(const RGBColor& rhs);

    RGBColor operator+(const RGBColor& c) const;
    RGBColor& operator+=(const RGBColor& c);
    RGBColor operator*(const float a) const;
    RGBColor& operator*=(const float a);
    RGBColor operator/(const float a) const;
    RGBColor& operator/=(const float a);
    RGBColor operator*(const RGBColor& c) const;
    bool operator==(const RGBColor& c) const;

    RGBColor powc(float p) const;
    float average() const;
    void to_255(); // tmp

public:
    float r, g, b;
};

// lhs prototype
RGBColor operator* (const float a, const RGBColor& c);

inline RGBColor RGBColor::operator+(const RGBColor& c) const {
    return RGBColor(r + c.r, g + c.g, b + c.b);
}

inline RGBColor& RGBColor::operator+=(const RGBColor& c) {
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

inline RGBColor RGBColor::operator*(const float a) const {
    return RGBColor(r * a, g * a, b * a);
}

inline RGBColor& RGBColor::operator*=(const float a) {
    r *= a;
    g *= a;
    b *= a;
    return *this;
}

inline RGBColor RGBColor::operator/(const float a) const {
    return RGBColor(r / a, g / a, b / a);
}

inline RGBColor& RGBColor::operator/=(const float a) {
    r /= a;
    g /= a;
    b /= a;
    return *this;
}

inline RGBColor RGBColor::operator*(const RGBColor& c) const {
    return RGBColor(r * c.r, g * c.g, b * c.b);
}

inline bool RGBColor::operator==(const RGBColor& c) const {
    return r == c.r && g == c.g && b == c.b;
}

inline float RGBColor::average() const {
    return 0.333333333333 * (r + g + b);
}

// lhs
inline RGBColor operator* (const float a, const RGBColor& c) {
    return (RGBColor (a * c.r, a * c.g, a * c.b));
}

#endif // __RGBCOLOR_HPP__

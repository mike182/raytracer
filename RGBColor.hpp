#ifndef __RGBCOLOR_HPP__
#define __RGBCOLOR_HPP__

class RGBColor
{
public:
    RGBColor();
    RGBColor(int i);
    RGBColor(int r, int g, int b);
    RGBColor(int r, int g, int b, int a);
    virtual ~RGBColor();

private:
public:
    int r;
    int g;
    int b;
    int a;
};

#endif // __RGBCOLOR_HPP__

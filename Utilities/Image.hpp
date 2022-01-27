#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <stdint.h>
#include <vector>
#include "RGBColor.hpp"

class Image
{
public:
    Image(void);
    Image(const Image & img) = delete;
    virtual ~Image(void);

    Image & operator=(const Image & rhs) = delete;

    void set_resolution(const int hres, const int vres);
    void set_pixel(RGBColor c);
    void set_pixel(RGBColor c, int x, int y); // keep ?
    void save_image_png();
    void save_image_jpeg();

public:
    int hres, vres;
    std::vector<RGBColor> raw_image;
};

#endif // __IMAGE_HPP__

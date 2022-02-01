#ifndef __IMAGE_HPP__
#define __IMAGE_HPP__

#include <stdint.h>
#include <vector>
#include "RGBColor.hpp"

#ifndef FILE_BMP
#define FILE_BMP 0
#endif

#ifndef FILE_PNG
#define FILE_PNG 1
#endif

#ifndef FILE_JPEG
#define FILE_JPEG 2
#endif

class Image {
public:
    Image(void);
    Image(const Image & img) = delete;
    virtual ~Image(void);

    Image & operator=(const Image & rhs) = delete;

    void set_resolution(const int hres, const int vres);
    void set_pixel(RGBColor c);
    void set_pixel(RGBColor c, int x, int y); // keep ?
    void save_image(int type);
    void save_image_bmp();
    void save_image_png();
    void save_image_jpeg();

public:
    int hres, vres;
    std::vector<RGBColor> raw_image;
};

#endif // __IMAGE_HPP__

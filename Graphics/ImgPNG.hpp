#ifndef __IMGPNG_HPP__
#define __IMGPNG_HPP__

#include "Graphics.hpp"
#include <png++/png.hpp>

class ImgPNG : public Graphics {
public:
    ImgPNG(void);
    ImgPNG(const int width, const int height);
    ImgPNG(const ImgPNG& copy) = delete;
    virtual ~ImgPNG(void);

    ImgPNG& operator=(const ImgPNG& rhs) = delete;

    virtual void init();
    virtual void display(const int x, const int y, const float r, const float g, const float b);
    virtual void render_line();
    virtual void end();

public:
    // png::image<png::rgb_pixel>* image;
};

#endif // __IMGPNG_HPP__

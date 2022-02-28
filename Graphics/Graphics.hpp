#ifndef __GRAPHICS_HPP__
#define __GRAPHICS_HPP__

#include "RGBColor.hpp"
#include <vector>

class Graphics {
public:
    Graphics(void);
    Graphics(const int width, const int height);
    Graphics(const Graphics& gfx) = delete;
    virtual ~Graphics(void);

    Graphics& operator=(const Graphics& rhs) = delete;

    virtual void init();
    virtual void display(int x, int y, float r, float g, float b);
    virtual void render_line();
    virtual void get_event();
    virtual void end();

    void set_resolution(int w, int h);

public:
    int width;
    int height;
    // void* buffer_ptr;
    std::vector<RGBColor> buffer;
};

inline void Graphics::set_resolution(int w, int h) {
    width = w;
    height = h;
}

#endif // __GRAPHICS_HPP__

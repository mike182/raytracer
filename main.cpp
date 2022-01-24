#include <vector>

#include <chrono>

#include <png++/png.hpp>

#include "RGBColor.hpp"
#include "World.hpp"

int main(void) {
    World w;

    w.build(); // set hres, vres --> 800, 600
    std::vector<RGBColor> vp(w.hres * w.vres, RGBColor(0, 0, 0));

    for (int row = 0; row < w.vres; row++)
        for (int col = 0; col < w.hres; col++)
            vp[row * col + col] = RGBColor((col * row) * 255 / (w.hres * w.vres) , 0, (row * col) * 255 / (w.hres * w.vres));

    // save to image
    png::image<png::rgb_pixel> image(w.hres, w.vres);
    for (png::uint_32 y = 0; y < image.get_height(); ++y)
        for (png::uint_32 x = 0; x < image.get_width(); ++x)
            image[y][x] = png::rgb_pixel(vp[y*x+x].r, vp[y*x+x].g, vp[y*x+x].b);
            // image[y][x] = png::rgb_pixel(y, x, x + y);
    auto now = std::chrono::system_clock::now();
    auto UTC = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
    image.write("/mnt/d/w/rt_image/" + std::to_string(UTC) + ".png");

    return 0;
}

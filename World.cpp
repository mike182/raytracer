#include <chrono>
#include <png++/png.hpp>

#include "World.hpp"

World::World () {
}

World::~World() {
}

void World::build() {
    this->hres = 800;
    this->vres = 600;
}

void World::render() {
    std::vector<RGBColor> vp(this->hres * this->vres, RGBColor(0, 0, 0));

    for (int row = 0; row < vres; row++)
        for (int col = 0; col < hres; col++)
            vp[row * col + col] = RGBColor((col*row*255)/(hres*vres), 0, (row*col*255)/(hres*vres));

    // save to image
    png::image<png::rgb_pixel> image(hres, vres);
    for (png::uint_32 y = 0; y < image.get_height(); ++y)
        for (png::uint_32 x = 0; x < image.get_width(); ++x)
            image[y][x] = png::rgb_pixel(vp[y*x+x].r, vp[y*x+x].g, vp[y*x+x].b);
    auto now = std::chrono::system_clock::now();
    auto UTC = std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch()).count();
    image.write("/mnt/d/w/rt_image/" + std::to_string(UTC) + ".png");
}


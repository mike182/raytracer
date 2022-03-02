#include "ImgPNG.hpp"
#include <iostream>
#include <chrono>

ImgPNG::ImgPNG(void)
    : Graphics()
{
}

ImgPNG::ImgPNG(const int w, const int h)
    : Graphics(w, h)
{
}

ImgPNG::~ImgPNG(void) {
    buffer.clear();
}

void ImgPNG::init() {
    // image = new png::image<png::rgb_pixel>(width, height);
}

void ImgPNG::display([[maybe_unused]] int x, [[maybe_unused]] int y, float r, float g, float b) {
    // buffer.push_back(RGBColor(r, g, b));
    buffer[y*width+x] = RGBColor(r, g, b);
}

void ImgPNG::render_line() {
}

void ImgPNG::end() {
    png::image<png::rgb_pixel> image(width, height);
    int i = 0;

    for (int r = 0; r < height; r++)
        for (int c = 0; c < width; c++, i++) {
            int x = c;
            int y = height - r - 1;
            // (*image)[y][x] = png::rgb_pixel(buffer[i].r,
            image[y][x] = png::rgb_pixel(buffer[i].r,
                                         buffer[i].g,
                                         buffer[i].b);
        }

    using namespace std::chrono;
    auto UTC = duration_cast<seconds>((system_clock::now()).time_since_epoch()).count();
    // std::string filename = "/mnt/d/w/rt_image/" + std::to_string(UTC);

    std::cout << std::endl; // jump after progress bar

    // copy in current folder
    std::string filename = "./result";
    // image->write(filename + ".png");
    image.write(filename + ".png");
    std::cout << "Image: " << filename << ".png" << std::endl;

    // DEBUG
    // copy in Images/ folder
    filename = "../Images/" + std::to_string(UTC);
    // image->write(filename + ".png");
    image.write(filename + ".png");
    std::cout << "Image: " << filename << ".png" << std::endl;
}

#include "World.hpp"

#include <iostream>

#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Normal.hpp"
#include "Ray.hpp"


World::World (void)
    : background_color(black),
    tracer_ptr(nullptr)
{
    image = new Image();
}

World::~World(void) {
    if (tracer_ptr)
        delete tracer_ptr;
}

// 3.18
void World::build(void) {
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_pixel_size(1.0);

    background_color = black;
    tracer_ptr = new SingleSphere(this);

    sphere.set_center(0.0);
    sphere.set_radius(85.0);

}

void World::render_scene(void) const {
    image->set_resolution(vp.hres, vp.vres); // png
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0;
    double x, y;

    ray.d = Vector3D(0, 0, -1);
    for (int r = 0; r < vp.vres; r++) {
        for (int c = 0; c < vp.hres; c++) {
            progress_bar(r, vp.vres);
            x = vp.s * (c - 0.5 * (vp.hres - 1.0));
            y = vp.s * (r - 0.5 * (vp.vres - 1.0));
            ray.o = Point3D(x, y, zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(r, c, pixel_color);
        }
    }
    clear_progress_bar();
    image->save_image_png(); // png
}

void World::display_pixel(const int row, const int column, const RGBColor & pixel_color) const {
    RGBColor mapped_color;

    if (vp.show_out_of_gamut)
        mapped_color = clamp_to_color(pixel_color);
    else
        mapped_color = max_to_one(pixel_color);

    if (vp.gamma != 1.0)
        mapped_color = mapped_color.powc(vp.inv_gamma);

    //have to start from max y coordinate to convert to screen coordinates
    int x = column;
    int y = vp.vres - row - 1;

    image->set_pixel(mapped_color, x, y); // png
}

RGBColor World::max_to_one(const RGBColor& c) const  {
    float max_value = max(c.r, max(c.g, c.b));

    if (max_value > 1.0)
        return (c / max_value);

    return (c);
}

RGBColor World::clamp_to_color(const RGBColor & raw_color) const {
    RGBColor c(raw_color);

    if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
        c.r = 1.0;
        c.g = 0.0;
        c.b = 0.0;
    }

    return (c);
}

void World::progress_bar(int r, int vres) const {
    int barWidth = 50;
    int progress = r * barWidth / vres;
    int pos = progress; //
    std::cout << "[";
    for (int i = 0; i < barWidth; i++) {
        if (i < pos) std::cout << "=";
        else if (i == pos) std::cout << ">";
        else std::cout << " ";
    }
    std::cout << "] " << r * 100 / vres << " %\r";
    std::cout.flush();
}

void World::clear_progress_bar() const {
    for (int i = 0; i < 100 + 20; i++)
        std::cout << " ";
    std::cout << "\r";
    std::cout.flush();
}

// void World::display_pixel(const int row, const int column, const RGBColor & pixel_color) const {
// }


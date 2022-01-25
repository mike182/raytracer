#include "World.hpp"

#include <chrono>
#include <png++/png.hpp>

#include "Constants.h"
#include "Ray.hpp"
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Normal.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "SingleSphere.hpp"


World::World ()
    : background_color(black),
    tracer_ptr(nullptr) { }

World::~World() {
    if (tracer_ptr)
        delete tracer_ptr;
    // delete_objects();
}

// void World::delete_objects() {

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

void World::render_scene() const {
    png::image<png::rgb_pixel> image(vp.hres, vp.vres);
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0;
    double x, y;

    ray.d = Vector3D(0, 0, -1);
    for (int r = 0; r < vp.vres; r++)
        for (int c = 0; c < vp.hres; c++) {
            x = vp.s * (c - 0.5 * (vp.hres - 1.0));
            y = vp.s * (r - 0.5 * (vp.vres - 1.0));
            ray.o = Point3D(x, y, zw);
            pixel_color = tracer_ptr->trace_ray(ray);
            image[r][c] = png::rgb_pixel(pixel_color.r * 255,
                                         pixel_color.g * 255,
                                         pixel_color.b * 255);
        }

    using namespace std::chrono;
    auto now = system_clock::now();
    auto UTC = duration_cast<seconds>(now.time_since_epoch()).count();
    // write image to file
    image.write("/mnt/d/w/rt_image/" + std::to_string(UTC) + ".png");
}

// void World::display_pixel(const int row, const int column, const RGBColor & pixel_color) const {
// }


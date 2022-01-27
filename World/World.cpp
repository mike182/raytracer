#include "World.hpp"

#include <iostream>
#include <iomanip>
#include <cmath>

#include "Random.h"
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Normal.hpp"
#include "Ray.hpp"
#include "MultipleObjects.hpp"

World::World (void)
    : background_color(black),
    tracer_ptr(nullptr)
{
    image = new Image();
#ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    winsize = ts.ts_cols;
#elif defined(TIOCGWINSZ)
    struct winsize ws;
    ioctl(0, TIOCGWINSZ, &ws);
    winsize = ws.ws_col;
#endif // TIOCGSIZE
}

World::~World(void) {
    if (tracer_ptr)
        delete tracer_ptr;
    delete_objects();
}

void World::render_scene(void) const {
    RGBColor pixel_color;
    Ray ray;
    double zw = 100.0;
    int n = (int) sqrt((float)vp.num_samples);
    Point2D pp;

    image->set_resolution(vp.hres, vp.vres); // png
    ray.d = Vector3D(0, 0, -1);
    for (int r = 0; r < vp.vres; r++) { // up
        for (int c = 0; c < vp.hres; c++) { // accros
            pixel_color = black;
            // Regular Sampling
            for (int p = 0; p < n; p++)
                for (int q = 0; q < n; q++) {
                    pp.x = vp.s * (c - 0.5 * vp.hres + (q + 0.5) / n);
                    pp.y = vp.s * (r - 0.5 * vp.vres + (p + 0.5) / n);
                    ray.o = Point3D(pp.x, pp.y, zw);
                    pixel_color += tracer_ptr->trace_ray(ray);
                }
            // Random Sampling
            // for (int p = 0; p < vp.num_samples; p++) {
            //     pp.x = vp.s * (c - 0.5 * vp.hres + rand_float());
            //     pp.y = vp.s * (r - 0.5 * vp.vres + rand_float());
            //     ray.o = Point3D(pp.x, pp.y, zw);
            //     pixel_color += tracer_ptr->trace_ray(ray);
            // }
            // Jittered Sampling
            // for (int p = 0; p < n; p++)
            //     for (int q = 0; q < n; q++) {
            //         pp.x = vp.s * (c - 0.5 * vp.hres + (q + rand_float()) / n);
            //         pp.y = vp.s * (r - 0.5 * vp.vres + (p + rand_float()) / n);
            //         ray.o = Point3D(pp.x, pp.y, zw);
            //         pixel_color += tracer_ptr->trace_ray(ray);
            //     }
            pixel_color /= vp.num_samples;
            display_pixel(r, c, pixel_color);
            pbar_update(r, vp.vres);
        }
    }
    // pbar_clear();
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

    // done in Image Class
    // have to start from max y coordinate to convert to screen coordinates
    int x = column;
    int y = vp.vres - row - 1;

    image->set_pixel(mapped_color, x, y); // png
}

void World::add_object(GeometricObject * object_ptr) {
    objects.push_back(object_ptr);
}

void World::delete_objects() {
    int num_objects = objects.size();
    for (int i = 0; i < num_objects; i++)
        delete objects[i];
    objects.clear();
}

ShadeRec World::hit_bare_bones_objects(const Ray & ray) {
    ShadeRec sr(*this);
    double t;
    double tmin = kHugeValue;
    int num_objects = objects.size();

    for (int i = 0; i < num_objects; i++)
        if (objects[i]->hit(ray, t, sr) && (t < tmin)) {
            sr.hit_an_object = true;
            tmin = t;
            sr.color = objects[i]->get_color();
        }

    return sr;
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

// Progress: [ 42%] [#####################...........]
void World::pbar_update(int progress, int vres) const {
    int bar_width = winsize / 4;
    int percent = (progress + 1) * 100 / vres;
    int pos = progress * bar_width / vres;

    std::cout << "\033[0;30m" << "\033[42m"; // black txt & green bg
    std::cout << "Progress: [" << std::setw(3) << percent << "%]";
    std::cout << "\033[0m"; // reset color
    std::cout << " [";
    for (int i = 0; i < bar_width; i++) {
        if (i < pos) std::cout << "#";
        else if (i == pos) std::cout << "";
        else std::cout << ".";
    }
    std::cout << "] " << "\r";
    std::cout.flush();
}

void World::pbar_clear() const {
    for (int i = 0; i < 25 + 19; i++)
        std::cout << " ";
    std::cout << "\r";
    std::cout.flush();
}


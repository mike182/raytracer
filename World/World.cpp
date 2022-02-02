#include "World.hpp"
// Tracers
// #include "SingleSphere.hpp"
#include "MultipleObjects.hpp"
#include "Ray.hpp"
// Cameras
#include "Orthographic.hpp"
#include "Pinhole.hpp"
// Lights
#include "Light.hpp"
// Materials
#include "Matte.hpp"
// Utilities
#include "Maths.h"
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Normal.hpp"
#include "ShadeRec.hpp"
// c/cpp header
#include <cmath>
#include <iostream>
#include <iomanip>

World::World (void)
    : background_color(black),
    tracer_ptr(nullptr),
    ambient_ptr(new Ambient),
    camera_ptr(new Orthographic)
{
#ifdef TIOCGSIZE
    struct ttysize ts;
    ioctl(STDIN_FILENO, TIOCGSIZE, &ts);
    winsize = ts.ts_cols;
#elif defined(TIOCGWINSZ)
    struct winsize ws;
    ioctl(0, TIOCGWINSZ, &ws);
    winsize = ws.ws_col;
#else
    winsize = 80;
#endif // TIOCGSIZE

    image = new Image();
}

World::~World(void) {
    if (tracer_ptr)
        delete tracer_ptr;
    if (ambient_ptr)
        delete ambient_ptr;
    if (camera_ptr)
        delete camera_ptr;
    delete_objects();
    delete_lights();
}

// void World::render_scene(void) const {
//     RGBColor pixel_color;
//     Ray ray;
//     double zw = 100.0;
//     Point2D sp;
//     Point2D pp;

//     image->set_resolution(vp.hres, vp.vres); // png
//     ray.d = Vector3D(0, 0, -1);
//     for (int r = 0; r < vp.vres; r++) { // up
//         for (int c = 0; c < vp.hres; c++) { // accros
//             pixel_color = black;
//             for (int i = 0; i < vp.num_samples; i++) {
//                     sp = vp.sampler_ptr->sample_unit_square();
//                     pp.x = vp.s * (c - 0.5 * vp.hres + sp.x);
//                     pp.y = vp.s * (r - 0.5 * vp.vres + sp.y);
//                     ray.o = Point3D(pp.x, pp.y, zw);
//                     pixel_color += tracer_ptr->trace_ray(ray);
//                 }
//             pixel_color /= vp.num_samples;
//             display_pixel(r, c, pixel_color);
//         }
//     }
//     // pbar_clear();
//     image->save_image_png(); // png
// }

void World::display_pixel(const int row, [[maybe_unused]] const int column, const RGBColor& pixel_color) const {
    RGBColor mapped_color;

    if (vp.show_out_of_gamut)
        mapped_color = clamp_to_color(pixel_color);
    else
        mapped_color = max_to_one(pixel_color);
    if (vp.gamma != 1.0)
        mapped_color = mapped_color.powc(vp.inv_gamma);
    // have to start from max y coordinate to convert to screen coordinates
    // done in Image Class
    // int x = column;
    // int y = vp.vres - row - 1;
    // image->set_pixel(mapped_color, x, y); // image file
    image->set_pixel(mapped_color); // image file
    pbar_update(row, vp.vres);
}

ShadeRec World::hit_objects(const Ray& ray) {
    ShadeRec sr(*this);
    double t;
    Normal normal;
    Point3D local_hit_point;
    float tmin = kHugeValue;
    int num_objects = objects.size();

    for (int j = 0; j < num_objects; j++)
        if (objects[j]->hit(ray, t, sr) && (t < tmin)) {
            sr.hit_an_object = true;
            tmin = t;
            sr.material_ptr = objects[j]->get_material();
            sr.hit_point = ray.o + t * ray.d;
            normal = sr.normal;
            local_hit_point = sr.local_hit_point;
        }
    if(sr.hit_an_object) {
        sr.t = tmin;
        sr.normal = normal;
        sr.local_hit_point = local_hit_point;
    }
    return sr;
}

// ShadeRec World::hit_bare_bones_objects(const Ray& ray) {
//     ShadeRec sr(*this);
//     double t;
//     double tmin = kHugeValue;
//     int num_objects = objects.size();

//     for (int i = 0; i < num_objects; i++)
//         if (objects[i]->hit(ray, t, sr) && (t < tmin)) {
//             sr.hit_an_object = true;
//             tmin = t;
//             sr.color = objects[i]->get_color();
//         }
//     return sr;
// }

RGBColor World::max_to_one(const RGBColor& c) const  {
    float max_value = max(c.r, max(c.g, c.b));

    if (max_value > 1.0)
        return (c / max_value);
    return (c);
}

RGBColor World::clamp_to_color(const RGBColor& raw_color) const {
    RGBColor c(raw_color);

    if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
        c.r = 1.0;
        c.g = 0.0;
        c.b = 0.0;
    }
    return (c);
}

void World::delete_objects() {
    int num_objects = objects.size();
    for (int i = 0; i < num_objects; i++) {
        delete objects[i];
        objects[i] = nullptr;
    }
    objects.clear();
}

void World::delete_lights() {
    int num_lights = lights.size();
    for (int i = 0; i < num_lights; i++) {
        delete lights[i];
        lights[i] = nullptr;
    }
    lights.clear();
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

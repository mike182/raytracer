#include "World.hpp"
// Tracers
// #include "SingleSphere.hpp"
#include "MultipleObjects.hpp"
#include "RayCast.hpp"
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
    camera_ptr(nullptr),
    ambient_ptr(new Ambient),
    image_ptr(new Image)
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
}

World::~World(void) {
    if (tracer_ptr)
        delete tracer_ptr;
    if (ambient_ptr)
        delete ambient_ptr;
    if (camera_ptr)
        delete camera_ptr;
    if (image_ptr)
        delete image_ptr;
    delete_objects();
    delete_lights();
}

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
    // image_ptr->set_pixel(mapped_color, x, y); // image file
    image_ptr->set_pixel(mapped_color); // image file
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

void sleepcp(int milli) {
   // Cross-platform sleep function
   clock_t end_time;
   end_time = std::clock() + milli * CLOCKS_PER_SEC/1000;
   while (clock() < end_time) {
      //blank loop for waiting
   }
}

int World::build_info() const {
    // Utilities

    // World

    // BRDFs

    // Samplers
    if (vp.sampler_ptr == nullptr) {
        std::cout << RED << "ViewPlane: sampler_ptr is null" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "ViewPlane: num_samples set to ";
    std::cout << vp.sampler_ptr->get_num_samples() << std::endl;
    std::cout << "ViewPlane: sampler_ptr set to ";
    std::cout << ((std::string)typeid(*(vp.sampler_ptr)).name()).erase(0,1) << std::endl;

    // Tracers
    if (tracer_ptr == nullptr) {
        std::cout << RED << "World: tracer_ptr is null" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "World: tracer_ptr set to ";
    std::cout << ((std::string)typeid(*tracer_ptr).name()).erase(0,1) << std::endl;

    // Cameras
    if (camera_ptr == nullptr) {
        std::cout << RED << "World: camera_ptr is null" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "World: camera_ptr: ";
    std::cout << ((std::string)typeid(*camera_ptr).name()).erase(0,1) << std::endl;

    // GeometricObjects
    // check objects list size
    if (objects.size() == 0) {
        std::cout << "World: " << YEL << "warning: " << WHITE;
        std::cout << "objects[] is empty" << std::endl;
        // return EXIT_FAILURE; // do not exit if no objects ?
    }
    else {
        // check objects[i]
        int num_objects = objects.size();
        std::cout << "World: objects: ";
        for (int i = 0; i < num_objects; i++)
            if (objects[i] == nullptr) {
                std::cout << RED << "objects[" << i+1 << "] is null " << std::endl;
                return EXIT_FAILURE;
            }
        std::cout << "ok" << std::endl;
        // check Materials
        std::cout << "World: materials: ";
        for (int i = 0; i < num_objects; i++)
            if (objects[i]->get_material() == nullptr) {
                std::cout << RED << "mat from objects[" << i+1 << "] is null " << std::endl;
                return EXIT_FAILURE;
            }
        std::cout << "ok" << std::endl;
    }

    // Lights
    // ambient light
    if (ambient_ptr == nullptr) {
        std::cout << RED << "World: ambient_ptr is null" << std::endl;
        return EXIT_FAILURE;
    }
    std::cout << "World: ambient light: color: ";
    std::cout << ((Ambient*)ambient_ptr)->color.r << std::endl;
    std::cout << "World: ambient light: ok" << std::endl;
    // check lights list size
    if (lights.size() == 0) {
        std::cout << "World: " << YEL << "warning: " << WHITE;
        std::cout << "lights[] is empty" << std::endl;
        // return EXIT_FAILURE; // do not exit if no lights ?
    }
    else {
        // check lights[i]
        int num_lights = lights.size();
        std:: cout << "World: lights: ";
        for (int i = 0; i < num_lights; i++) {
            if (lights[i] == nullptr) {
                std::cout << RED << "lights[" << i+1 << "] is null " << std::endl;
                return EXIT_FAILURE;
            }
            // std::cout << i+1 << " ";
        }
        std::cout << "ok" << std::endl;
    }

    return 0;
}

RGBColor World::max_to_one(const RGBColor& c) const  {
    float max_value = max(c.r, max(c.g, c.b));

    if (max_value > 1.0)
        return c / max_value;
    return c;
}

RGBColor World::clamp_to_color(const RGBColor& raw_color) const {
    RGBColor c(raw_color);

    if (raw_color.r > 1.0 || raw_color.g > 1.0 || raw_color.b > 1.0) {
        c.r = 1.0;
        c.g = 0.0;
        c.b = 0.0;
    }
    return c;
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
    for (int i = 0; i < winsize + 19; i++)
        std::cout << " ";
    std::cout << "\r";
    std::cout.flush();
}

#include "World.hpp"

#include <iostream>

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
}

World::~World(void) {
    if (tracer_ptr)
        delete tracer_ptr;
    delete_objects();
}

// 3.18
// void World::build(void) {
//     vp.set_hres(200);
//     vp.set_vres(200);
//     vp.set_pixel_size(1.0);

//     background_color = black;
//     tracer_ptr = new SingleSphere(this);

//     sphere.set_center(0.0);
//     sphere.set_radius(85.0);

// }


void World::build(void) {
    vp.set_hres(200);
    vp.set_vres(200);

    background_color = black;
    tracer_ptr = new MultipleObjects(this);

    // use access functions to set center and radius for this sphere

    Sphere* sphere_ptr = new Sphere;
    sphere_ptr->set_center(0, -25, 0);
    sphere_ptr->set_radius(80.0);
    sphere_ptr->set_color(1, 0, 0);  // red
    add_object(sphere_ptr);

    // use a constructor to set center and radius for this sphere

    sphere_ptr = new Sphere(Point3D(0, 30, 0), 60);
    sphere_ptr->set_color(1, 1, 0);	// yellow
    add_object(sphere_ptr);


    Plane* plane_ptr = new Plane(Point3D(0.0), Normal(0, 1, 1));
    plane_ptr->set_color(0.0, 0.25, 0.0);	// dark green
    add_object(plane_ptr);
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


#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include <stdint.h>
#include <vector>
#include "Constants.h"
#include "Maths.h"
#include "ViewPlane.hpp"
#include "RGBColor.hpp"
#include "Tracer.hpp"
#include "ShadeRec.hpp"
#include "GeometricObject.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Image.hpp"

class World {
public:
    World(void);
    virtual ~World(void);

public:
    void build(void);
    void render_scene(void) const;
    void display_pixel(const int row, const int column, const RGBColor & pixel_color) const;
    void add_object(GeometricObject * object_ptr);
    ShadeRec hit_bare_bones_objects(const Ray & ray);

    RGBColor max_to_one(const RGBColor& c) const;
    RGBColor clamp_to_color(const RGBColor& c) const;

private:
    void delete_objects();
    void progress_bar(int row, int vres) const;
    void clear_progress_bar() const;

public:
    ViewPlane                       vp;
    RGBColor                        background_color;
    Tracer                          *tracer_ptr;
    // Camera                          *camera_ptr;
    std::vector<GeometricObject*>   objects;
    // std::vector<Light*>             objects;
    Image                           *image;
};

#endif // __WORLD_HPP__

#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include "ViewPlane.hpp"
#include "RGBColor.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Tracer.hpp"
#include "GeometricObject.hpp"
#include "ShadeRec.hpp"

#include <vector>

#include "SingleSphere.hpp"

class World {
public:
    World();
    World(int hres, int vres);
    virtual ~World();

public:
    void build();
    void render_scene(void) const;
    // void display_pixel(const int row, const int column, const RGBColor & pixel_color) const;
private:
    // void progress_bar(int row, int vres) const;
    // void delete_objects();

public:
    ViewPlane vp;
    RGBColor background_color;
    Sphere sphere;
    Tracer * tracer_ptr;
    std::vector<GeometricObject*> obj;
};

#endif // __WORLD_HPP__

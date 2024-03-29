#ifndef __WORLD_HPP__
#define __WORLD_HPP__

#include "Constants.h"
#include "Graphics.hpp"
#include "ViewPlane.hpp"
#include "RGBColor.hpp"
#include "GeometricObject.hpp"
#include "Light.hpp"
#include "Ambient.hpp"
#include "Camera.hpp"
#include "Tracer.hpp"
#include "Ray.hpp"
#include <sys/ioctl.h>
#include <cstdio>
#include <cstdint>
#include <vector>
#include <iostream>

class World {
public:
    World(void);
    virtual ~World(void);

public:
    void build(void);
    void set_camera(Camera* c_ptr);
    void add_object(GeometricObject* object_ptr);
    void add_light(Light* light_ptr);
    void set_ambient_light(Light* light_ptr);

    void display_pixel(const int row, const int column, const RGBColor& pixel_color) const;
    ShadeRec hit_objects(const Ray& ray);

    RGBColor max_to_one(const RGBColor& c) const;
    RGBColor clamp_to_color(const RGBColor& c) const;

    int build_info(void) const;
    void pbar_update(int row, int vres) const;
    void pbar_clear() const;

private:
    void delete_objects();
    void delete_lights();

public:
    ViewPlane vp;
    RGBColor background_color;
    Tracer* tracer_ptr;
    Camera* camera_ptr;
    Light* ambient_ptr;
    std::vector<GeometricObject*> objects;
    std::vector<Light*> lights;

    Graphics* gfx_ptr;
    int winsize;
};

inline void World::add_object(GeometricObject* object_ptr) {
    objects.push_back(object_ptr);
}

inline void World::add_light(Light* light_ptr) {
    lights.push_back(light_ptr);
}

inline void World::set_ambient_light(Light* light_ptr) {
    ambient_ptr = light_ptr;
}

inline void World::set_camera(Camera* c_ptr) {
    camera_ptr = c_ptr;
}

#endif // __WORLD_HPP__

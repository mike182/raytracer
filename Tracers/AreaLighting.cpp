#include "AreaLighting.hpp"
#include "World.hpp"
#include "ShadeRec.hpp"
#include "Material.hpp"

AreaLighting::AreaLighting(void)
    : Tracer()
{
}

AreaLighting::AreaLighting(World* w_ptr)
    : Tracer(w_ptr)
{
}

AreaLighting::~AreaLighting(void) {
}

// The statement sr.ray = ray; is required for specular shading, computing the reflected and
// transmitted ray directions, and for rendering single sided emissive materials with area lights
RGBColor AreaLighting::trace_ray(const Ray& ray, const int depth) const {
    if (depth > world_ptr->vp.max_depth)
        return black;
    else {
        ShadeRec sr(world_ptr->hit_objects(ray));

        if (sr.hit_an_object) {
            sr.depth = depth;
            sr.ray = ray;

            return (sr.material_ptr->area_light_shade(sr));
        }
        else
            return (world_ptr->background_color);
    }
}


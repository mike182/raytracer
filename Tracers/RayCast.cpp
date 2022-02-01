#include "RayCast.hpp"
#include "World.hpp"
#include "ShadeRec.hpp"
#include "Material.hpp"

RayCast::RayCast(void)
    : Tracer()
{
}

RayCast::RayCast(World* w_ptr)
    : Tracer(w_ptr)
{
}

// RayCast::RayCast(const RayCast& rc)
//     : Tracer(w)
//     {
//     }

RayCast::~RayCast(void)
{
}

// RayCast& RayCast::operator=(const RayCast& rhs) {
//     if (this == &rhs)
//         return *this;
//     return *this;
// }

RGBColor RayCast::trace_ray(const Ray& ray) const {
    ShadeRec sr(world_ptr->hit_objects(ray));

    if (sr.hit_an_object) {
        sr.ray = ray; // used for specular shading
        return (sr.material_ptr->shade(sr));
    }
    else
        return (world_ptr->background_color);
}

RGBColor RayCast::trace_ray(const Ray ray, [[maybe_unused]]const int depth) const {
    ShadeRec sr(world_ptr->hit_objects(ray));

    if (sr.hit_an_object) {
        sr.ray = ray; // used for specular shading
        return (sr.material_ptr->shade(sr));
    }
    else
        return (world_ptr->background_color);
}

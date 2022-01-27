#include "MultipleObjects.hpp"

MultipleObjects::MultipleObjects(void)
    : Tracer() { }

MultipleObjects::MultipleObjects(World * world_ptr)
    : Tracer(world_ptr) { }

// MultipleObjects::MultipleObjects(const MultipleObjects & cpy arg) { }

MultipleObjects::~MultipleObjects(void)
{
}

// MultipleObjects & MultipleObjects::operator=(const MultipleObjects & rhs) {
//     if (this == &rhs)
//         return *this;

//     // x = rhs.x;
//     // y = rhs.y;
//     // z = rhs.z;

//     return *this;
// }

RGBColor MultipleObjects::trace_ray(__attribute__((unused))const Ray & ray) const {
    ShadeRec sr(world_ptr->hit_bare_bones_objects(ray));

    if (sr.hit_an_object)
        return sr.color;
    else
        return world_ptr->background_color;
}


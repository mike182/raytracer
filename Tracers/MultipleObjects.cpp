#include "MultipleObjects.hpp"

MultipleObjects::MultipleObjects(void)
    : Tracer()
{
}

MultipleObjects::MultipleObjects(World* w)
    : Tracer(w)
{
}

// MultipleObjects::MultipleObjects(const MultipleObjects& objs)
// {
// }

MultipleObjects::~MultipleObjects(void) {
}

// MultipleObjects& MultipleObjects::operator=(const MultipleObjects& rhs) {
//     if (this == &rhs)
//         return *this;

//     return *this;
// }

RGBColor MultipleObjects::trace_ray([[maybe_unused]]const Ray& ray) const {
    ShadeRec sr(world_ptr->hit_objects(ray));

    if (sr.hit_an_object)
        return sr.color;
    else
        return world_ptr->background_color;
}

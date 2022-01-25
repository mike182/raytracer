#include "Tracer.hpp"

#include "World.hpp"
#include "Constants.h"

Tracer::Tracer()
    : world_ptr(NULL) { }

Tracer::Tracer(World * w_ptr)
    : world_ptr(w_ptr) { }

Tracer::~Tracer()
{
    if (world_ptr)
        world_ptr = nullptr;
}


RGBColor Tracer::trace_ray(const Ray & ray) const {
    Ray unused = ray; // unused
    return red;
}

// RGBColor Tracer::trace_ray(const Ray & ray, const int depth) const {
//     return black;
// }


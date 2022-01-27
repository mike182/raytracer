#include "Tracer.hpp"

#include "World.hpp"
#include "Constants.h"

Tracer::Tracer(void)
    : world_ptr(NULL) { }

Tracer::Tracer(World * wp)
    : world_ptr(wp) { }

Tracer::~Tracer(void)
{
    if (world_ptr)
        world_ptr = nullptr;
}

RGBColor Tracer::trace_ray(__attribute__((unused))const Ray & ray) const {
    return red;
}

// RGBColor Tracer::trace_ray(const Ray & ray, const int depth) const {
//     return black;
// }


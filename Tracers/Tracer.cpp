#include "Tracer.hpp"

Tracer::Tracer(void)
    : world_ptr(nullptr)
{
}

Tracer::Tracer(World* w_ptr)
    : world_ptr(w_ptr)
{
}

Tracer::~Tracer(void)
{
    if (world_ptr)
        world_ptr = nullptr;
}

RGBColor Tracer::trace_ray([[maybe_unused]] const Ray& ray) const {
    return black;
}

RGBColor Tracer::trace_ray([[maybe_unused]] const Ray& ray, [[maybe_unused]] const int depth) const {
    return black;
}

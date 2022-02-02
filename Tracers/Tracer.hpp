#ifndef __TRACER_HPP__
#define __TRACER_HPP__

#include "Constants.h"
#include "Ray.hpp"
#include "RGBColor.hpp"

class World;

class Tracer {
public:
    Tracer(void);
    Tracer(World* w_ptr);
    virtual ~Tracer(void);

    virtual RGBColor trace_ray(const Ray& ray) const; // SingleSphere & MultipleObjects
    virtual RGBColor trace_ray(const Ray& ray, const int depth) const;

protected:
    World* world_ptr;
};

#endif // __TRACER_HPP__

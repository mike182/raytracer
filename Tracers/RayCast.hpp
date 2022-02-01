#ifndef __RAYCAST_HPP__
#define __RAYCAST_HPP__

#include "Tracer.hpp"

class RayCast : public Tracer {
public:
    RayCast(void);
    RayCast(World* w_ptr);
    RayCast(const RayCast& rc) = delete;
    virtual ~RayCast(void);

    RayCast& operator=(const RayCast& rhs) = delete;

    virtual RGBColor trace_ray(const Ray& ray) const;
    virtual RGBColor trace_ray(const Ray ray, const int depth) const;
};

#endif // __RAYCAST_HPP__

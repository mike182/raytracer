#ifndef __AREALIGHTNING_HPP__
#define __AREALIGHTNING_HPP__

#include "Tracer.hpp"

class AreaLighting: public Tracer {
public:
    AreaLighting(void);
    AreaLighting(World* w_ptr);
    virtual ~AreaLighting(void);

    virtual RGBColor trace_ray(const Ray& ray, const int depth) const;
};

#endif // __AREALIGHTNING_HPP__

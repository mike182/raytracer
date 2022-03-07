#ifndef __WHITTED_HPP__
#define __WHITTED_HPP__

#include "Tracer.hpp"

class Whitted: public Tracer {
public:
    Whitted(void);
    Whitted(World* w_ptr);
    virtual ~Whitted(void);

    virtual RGBColor trace_ray(const Ray& ray, const int depth) const;
};

#endif // __WHITTED_HPP__

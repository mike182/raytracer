#ifndef __MULTIPLEOBJECTS_HPP__
#define __MULTIPLEOBJECTS_HPP__

#include "World.hpp"

class MultipleObjects : public Tracer {
public:
    MultipleObjects(void);
    MultipleObjects(World * world_ptr);
    MultipleObjects(const MultipleObjects & mobj) = delete;
    virtual ~MultipleObjects(void);

    MultipleObjects & operator=(const MultipleObjects & rhs) = delete;

    virtual RGBColor trace_ray(const Ray & ray) const;

public:
    // no data
};

#endif // __MULTIPLEOBJECTS_HPP__

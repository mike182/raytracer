#ifndef __MULTIPLEOBJECTS_HPP__
#define __MULTIPLEOBJECTS_HPP__

#include "World.hpp"

class MultipleObjects : public Tracer {
public:
    MultipleObjects(void);
    MultipleObjects(World* w_ptr);
    MultipleObjects(const MultipleObjects& objs) = delete;
    virtual ~MultipleObjects(void);

    MultipleObjects& operator=(const MultipleObjects& rhs) = delete;

    virtual RGBColor trace_ray(const Ray& ray) const;
};

#endif // __MULTIPLEOBJECTS_HPP__

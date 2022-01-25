#ifndef __GEOMETRICOBJECT_HPP__
#define __GEOMETRICOBJECT_HPP__

#include "RGBColor.hpp"
#include "Ray.hpp"
#include "ShadeRec.hpp"

class GeometricObject {
public:
    GeometricObject(void);
    GeometricObject(const GeometricObject & obj);
    virtual ~GeometricObject(void);

    GeometricObject & operator=(const GeometricObject & rhs);

    virtual bool hit(const Ray & ray, double & tmin, ShadeRec & sr) const = 0;

    // tmp
    void set_color(RGBColor & c);
    void set_color(const float r, const float g, const float b);
    RGBColor get_color();

protected:
    RGBColor color;
};

#endif // __GEOMETRICOBJECT_HPP__

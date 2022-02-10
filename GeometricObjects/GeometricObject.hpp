#ifndef __GEOMETRICOBJECT_HPP__
#define __GEOMETRICOBJECT_HPP__

#include "Constants.h"
// #include "BBox.h"
#include "RGBColor.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include "Normal.hpp"
#include "Ray.hpp"
#include "ShadeRec.hpp"
#include <cmath>

class Material;

class GeometricObject {
public:
    GeometricObject(void);
    GeometricObject(const GeometricObject& obj);
    virtual GeometricObject* clone(void) const = 0;
    virtual ~GeometricObject(void);
protected:
    GeometricObject& operator=(const GeometricObject& rhs);

public:
    virtual void set_material(Material* m_ptr);
    Material* get_material(void) const;
    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const = 0;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;

    // chap 3 only
    void set_color(RGBColor& c);
    void set_color(const float r, const float g, const float b);
    RGBColor get_color();

    // virtual void set_bounding_box(void);
    // virtual BBox get_bounding_box(void);
    virtual void add_object(GeometricObject* object_ptr);

    virtual Point3D sample(void);
    virtual float pdf(ShadeRec& sr);

    virtual Normal get_normal(void) const;
    virtual Normal get_normal(const Point3D& p);

protected:
    mutable Material* material_ptr;
    RGBColor color;
    bool shadows;
};

inline void GeometricObject::set_color(RGBColor& c) {
    color = c;
}

inline void GeometricObject::set_color(const float r, const float g, const float b) {
    color.r = r;
    color.g = g;
    color.b = b;
}

inline RGBColor GeometricObject::get_color() {
    return color;
}

#endif // __GEOMETRICOBJECT_HPP__

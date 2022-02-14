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

    // virtual void set_bounding_box(void);
    // virtual BBox get_bounding_box(void);
    virtual void add_object(GeometricObject* object_ptr);

    virtual Point3D sample(void);
    virtual float pdf(ShadeRec& sr);

    virtual Normal get_normal(void) const;
    virtual Normal get_normal(const Point3D& p);

protected:
    mutable Material* material_ptr;
    bool shadows;
};

#endif // __GEOMETRICOBJECT_HPP__

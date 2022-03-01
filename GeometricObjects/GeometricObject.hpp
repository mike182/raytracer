#ifndef __GEOMETRICOBJECT_HPP__
#define __GEOMETRICOBJECT_HPP__

#include "Constants.h"
#include "BBox.hpp"
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
    virtual BBox get_bounding_box(void);
    virtual void add_object(GeometricObject* object_ptr);

    // The following two functions are only required for objects that are
    // light sources, eg disks, rectangles, and spheres
    virtual Point3D sample(void);
    virtual float pdf(const ShadeRec& sr);

    // The following two functions allow us to simplify the code for
    // smooth shaded triangle meshes
    virtual Normal get_normal(void) const;
    virtual Normal get_normal(const Point3D& p) const;

    virtual Normal get_normal(const int face_hit) const;

protected:
    // mutable allows the const functions Compound::hit,
    // Instance::hit, and RegularGrid::hit to assign to material_ptr
    mutable Material* material_ptr;
    bool shadows;
};

#endif // __GEOMETRICOBJECT_HPP__

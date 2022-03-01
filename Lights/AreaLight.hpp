#ifndef __AREALIGHT_HPP__
#define __AREALIGHT_HPP__

#include "Light.hpp"
#include "RGBColor.hpp"
#include "Vector3D.hpp"
#include "Point3D.hpp"
#include "Normal.hpp"
#include "GeometricObject.hpp"
#include "Material.hpp"

class AreaLight: public Light {
public:
    AreaLight(void);
    AreaLight(const AreaLight& al);
    // virtual AreaLight* clone(void) const;
    virtual Light* clone(void) const;
    virtual ~AreaLight(void);

    AreaLight& operator=(const AreaLight& rhs);

    void set_object(GeometricObject* obj_ptr);
    virtual Vector3D get_direction(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;
    virtual float G(const ShadeRec& sr) const;
    virtual float pdf(const ShadeRec& sr) const;

private:
    GeometricObject* object_ptr;
    Material* material_ptr; // will be an emissive material
    Point3D sample_point;
    Normal light_normal; // assigned in get_direction - which therefore can't be const for any light
    Vector3D wi; // unit direction from hit point being shaded to sample point on light surface
};

inline void AreaLight::set_object(GeometricObject* obj_ptr) {
    object_ptr = obj_ptr;
    material_ptr = object_ptr->get_material();
}

#endif // __AREALIGHT_HPP__

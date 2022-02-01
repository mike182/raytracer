#include "GeometricObject.hpp"
#include "Constants.h"
#include "Material.hpp"

GeometricObject::GeometricObject(void)
    : material_ptr(nullptr),
    color(black)
    // shadows(true)
 {
 }

GeometricObject::GeometricObject(const GeometricObject& obj)
    : material_ptr(nullptr),
    color(obj.color)
      // shadows(true)
{
    if (obj.material_ptr)
        material_ptr = obj.material_ptr->clone();
    else
        material_ptr = nullptr;
}

GeometricObject::~GeometricObject(void) {
    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }
}

GeometricObject& GeometricObject::operator=(const GeometricObject& rhs) {
    if (this == &rhs)
        return *this;

    color = rhs.color;
    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }
    if (rhs.material_ptr)
        material_ptr = rhs.material_ptr->clone();
    // shadows = rhs.shadows;
    return *this;
}

void GeometricObject::set_material(Material* m_ptr) {
    material_ptr = m_ptr;
}

Material* GeometricObject::get_material(void) const {
    return material_ptr;
}

// void GeometricObject::set_bounding_box (void) {
// }

// BBox GeometricObject::get_bounding_box (void) {
    // return BBox();
// }

void GeometricObject::add_object([[maybe_unused]] GeometricObject* object_ptr) {
}

Point3D GeometricObject::sample(void) {
    return (Point3D(0.0));
}

float GeometricObject::pdf([[maybe_unused]] ShadeRec& sr) {
    return (0.0);
}

Normal GeometricObject::get_normal(void) const {
    return (Normal());
}

Normal GeometricObject::get_normal([[maybe_unused]] const Point3D& p) {
    return (Normal());
}

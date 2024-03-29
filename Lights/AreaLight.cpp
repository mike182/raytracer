#include "AreaLight.hpp"
#include "Emissive.hpp"

AreaLight::AreaLight(void)
    : Light(),
    object_ptr(nullptr),
    material_ptr(nullptr)
{
}

AreaLight::AreaLight(const AreaLight& al)
    : Light(al)
{
    if(al.object_ptr)
        object_ptr = al.object_ptr->clone();
    else  object_ptr = nullptr;

    if(al.material_ptr)
        material_ptr = al.material_ptr->clone();
    else  material_ptr = nullptr;
}

// AreaLight* AreaLight::clone(void) const {
Light* AreaLight::clone(void) const {
    return new AreaLight(*this);
}

AreaLight::~AreaLight(void) {
    // if (object_ptr) {
    //     delete object_ptr;
    //     object_ptr = nullptr;
    // }

    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }
}

AreaLight& AreaLight::operator=(const AreaLight& rhs) {
    if (this == &rhs)
        return *this;

    Light::operator=(rhs);

    if (object_ptr) {
        delete object_ptr;
        object_ptr = nullptr;
    }

    if (rhs.object_ptr)
        object_ptr = rhs.object_ptr->clone();

    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }

    if (rhs.material_ptr)
        material_ptr = rhs.material_ptr->clone();

    return *this;
}

Vector3D AreaLight::get_direction(ShadeRec& sr) {
    sample_point = object_ptr->sample(); // used in the G function
    light_normal = object_ptr->get_normal(sample_point);
    wi = sample_point - sr.hit_point; // used in the G function
    wi.normalize();

    return wi;
}

RGBColor AreaLight::L(ShadeRec& sr) {
    float ndotd = -light_normal * wi;

    if (ndotd > 0.0)
        return material_ptr->get_Le(sr);
    else
        return black;
}

bool AreaLight::in_shadow(const Ray& ray, const ShadeRec& sr) const {
    float t;
    int num_objects = sr.w.objects.size();
    float ts = (sample_point - ray.o) * ray.d;

    for (int j = 0; j < num_objects; j++)
        if (sr.w.objects[j]->shadow_hit(ray, t) && t < ts)
            return true;

    return false;
}

// G is part of the geometric factor
float AreaLight::G(const ShadeRec& sr) const {
    float ndotd = -light_normal * wi;
    float d2 = sample_point.d_squared(sr.hit_point);

    return ndotd / d2;
}

float AreaLight::pdf(const ShadeRec& sr) const {
    return object_ptr->pdf(sr);
}

#include "EnvironmentLight.hpp"

EnvironmentLight::EnvironmentLight()
    : Light(),
    sampler_ptr(nullptr),
    material_ptr(nullptr)
{
}

EnvironmentLight::EnvironmentLight(const EnvironmentLight& el)
    : Light(el)
{
    if (el.sampler_ptr)
        sampler_ptr = el.sampler_ptr->clone();
    else  sampler_ptr = nullptr;

    if (el.material_ptr)
        material_ptr = el.material_ptr->clone();
    else  material_ptr = nullptr;
}

// EnvironmentLight* EnvironmentLight::clone() const {
Light* EnvironmentLight::clone() const {
    return new EnvironmentLight(*this);
}

EnvironmentLight::~EnvironmentLight() {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }
}

EnvironmentLight& EnvironmentLight::operator=(const EnvironmentLight& rhs) {
    if (this == &rhs)
        return *this;
    Light::operator=(rhs);
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    if (rhs.sampler_ptr)
        sampler_ptr = rhs.sampler_ptr->clone();
    if (material_ptr) {
        delete material_ptr;
        material_ptr = nullptr;
    }
    if (rhs.material_ptr)
        material_ptr = rhs.material_ptr->clone();
    return *this;
}

void EnvironmentLight::set_sampler(Sampler* s_ptr) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    sampler_ptr = s_ptr;
    sampler_ptr->map_samples_to_hemisphere(1);
}

Vector3D EnvironmentLight::get_direction(ShadeRec& sr) {
    w = sr.normal;
    v = Vector3D(0.0034, 1, 0.0071) ^ v;
    v.normalize();
    u = v ^ w;

    Point3D sp = sampler_ptr->sample_hemisphere();
    wi = sp.x * u + sp.y * v + sp.z * w;
    return wi;
}

RGBColor EnvironmentLight::L(ShadeRec& sr) {
    return material_ptr->get_Le(sr);
}

bool EnvironmentLight::in_shadow(const Ray& ray, const ShadeRec& sr) const {
    float t;
    int num_objects = sr.w.objects.size();

    for (int j = 0; j < num_objects; j++)
        if (sr.w.objects[j]->shadow_hit(ray, t))
            return true;
    return false;
}

float EnvironmentLight::pdf([[maybe_unused]] const ShadeRec& sr) const {
    return (w * wi) / PI;
}

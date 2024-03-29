#include "PointLight.hpp"
#include "World.hpp"

PointLight::PointLight(void)
    : Light(),
    ls(1.0),
    color(1.0),
    location(0, 0, 100)
{
}

PointLight::PointLight(const PointLight& pl)
    : Light(pl),
    ls(pl.ls),
    color(pl.color),
    location(pl.location)
{
}

PointLight::~PointLight(void) {
}

Light* PointLight::clone(void) const {
    return new PointLight(*this);
}

PointLight& PointLight::operator=(const PointLight& rhs) {
    if (this == &rhs)
        return *this;

    Light::operator= (rhs);
    ls = rhs.ls;
    color = rhs.color;
    location = rhs.location;
    return *this;
}

Vector3D PointLight::get_direction([[maybe_unused]] ShadeRec& sr) {
    return (location - sr.hit_point).hat();
}

RGBColor PointLight::L([[maybe_unused]] ShadeRec& s) {
    return ls * color;
}

bool PointLight::in_shadow(const Ray& ray, const ShadeRec& sr) const {
    float t;
    int num_objects = sr.w.objects.size();
    float d = location.distance(ray.o);

    for (int j = 0; j < num_objects; j++)
        if (sr.w.objects[j]->shadow_hit(ray, t) && t < d)
            return true;
    return false;
}

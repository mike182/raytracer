#include "Directional.hpp"
#include "World.hpp"

Directional::Directional(void)
    : Light(),
    ls(1.0),
    color(1.0),
    dir(0, 1, 0)
{
}

Directional::Directional(const Directional& dl)
    : Light(dl),
    ls(dl.ls),
    color(dl.color),
    dir(dl.dir)
{
}

Directional::~Directional(void) {
}

Light* Directional::clone(void) const {
    return new Directional(*this);
}

Directional& Directional::operator= (const Directional& rhs) {
    if (this == &rhs)
        return *this;

    Light::operator= (rhs);
    ls = rhs.ls;
    color = rhs.color;
    dir = rhs.dir;
    return *this;
}

Vector3D Directional::get_direction([[maybe_unused]] ShadeRec& sr) {
    return dir;
}

RGBColor Directional::L([[maybe_unused]] ShadeRec& s) {
    return ls * color;
}

bool Directional::in_shadow(const Ray& ray, const ShadeRec& sr) const {
    float t;
    int num_objects = sr.w.objects.size();
    // float d = location.distance(ray.o);

    for (int j = 0; j < num_objects; j++)
        // if (sr.w.objects[j]->shadow_hit(ray, t) && t < d)
        if (sr.w.objects[j]->shadow_hit(ray, t) && t > 0)
            return true;
    return false;
}

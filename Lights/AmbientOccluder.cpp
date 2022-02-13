#include "AmbientOccluder.hpp"
#include "World.hpp"
#include "Sampler.hpp"

AmbientOccluder::AmbientOccluder(void)
    : ls(1),
    color(1),
    min_amount(0),
    sampler_ptr(nullptr),
    u(1, 0, 0),
    v(0, 1, 0),
    w(0, 0, 1)
{
}

AmbientOccluder::AmbientOccluder(const AmbientOccluder& ao)
    : ls(ao.ls),
      color(ao.color),
      min_amount(ao.min_amount),
      sampler_ptr(ao.sampler_ptr),
      u(ao.u),
      v(ao.v),
      w(ao.w)
{
    if (ao.sampler_ptr) {
    }
}

AmbientOccluder::~AmbientOccluder(void) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
}

AmbientOccluder* AmbientOccluder::clone(void) const {
    return new AmbientOccluder(*this);
}

AmbientOccluder& AmbientOccluder::operator=(const AmbientOccluder& rhs) {
    if (this == &rhs)
        return *this;

    Light::operator=(rhs);
    u = rhs.u;
    v = rhs.v;
    w = rhs.w;
    sampler_ptr = rhs.sampler_ptr;
    min_amount = rhs.min_amount;
    return *this;
}

void AmbientOccluder::set_sampler(Sampler* s_ptr) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
    sampler_ptr = s_ptr;
    sampler_ptr->map_samples_to_hemisphere(1);
}

Vector3D AmbientOccluder::get_direction([[maybe_unused]]ShadeRec& sr) {
    Point3D sp = sampler_ptr->sample_hemisphere();
    return sp.x * u + sp.y * v + sp.z * w;
}

RGBColor AmbientOccluder::L(ShadeRec& sr) {
    w = sr.normal;
    v = w ^ Vector3D(0.0072, 1.0, 0.0034); // jitter the up vector in case normal is vertical
    v.normalize();
    u = v ^ w;

    Ray shadow_ray;
    shadow_ray.o = sr.hit_point;
    shadow_ray.d = get_direction(sr);

    if (in_shadow(shadow_ray, sr)) {
        return (min_amount * ls * color);
    }
    else {
        return (ls * color);
    }
}

bool AmbientOccluder::in_shadow(const Ray& ray, const ShadeRec& sr) const {
    float t;
    int num_objects = sr.w.objects.size();

    for (int j = 0; j < num_objects; j++)
        if (sr.w.objects[j]->shadow_hit(ray, t))
            return true;
    return false;
}

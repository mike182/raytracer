#include "Matte.hpp"

Matte::Matte(void)
    : Material(),
    ambient_brdf(new Lambertian),
    diffuse_brdf(new Lambertian)
{
}

Matte::Matte(const Matte& m)
    : Material(m)
{
    if (m.ambient_brdf)
        ambient_brdf = m.ambient_brdf->clone();
    else
        ambient_brdf = nullptr;

    if (m.diffuse_brdf)
        diffuse_brdf = m.diffuse_brdf->clone();
    else
        diffuse_brdf = nullptr;
}

Matte::~Matte(void) {
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = nullptr;
    }
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = nullptr;
    }
}

Material* Matte::clone(void) const {
    return new Matte(*this);
}

Matte& Matte::operator=(const Matte& rhs) {
    if (this == &rhs)
        return *this;
    Material::operator=(rhs);
    if (ambient_brdf) {
        delete ambient_brdf;
        ambient_brdf = nullptr;
    }
    if (rhs.ambient_brdf)
        ambient_brdf = rhs.ambient_brdf->clone();
    if (diffuse_brdf) {
        delete diffuse_brdf;
        diffuse_brdf = nullptr;
    }
    if (rhs.diffuse_brdf)
        diffuse_brdf = rhs.diffuse_brdf->clone();
    return *this;
}

RGBColor Matte::shade(ShadeRec& sr) {
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    int num_lights = sr.w.lights.size();

    for (int j = 0; j < num_lights; j++) {
        Vector3D wi = sr.w.lights[j]->get_direction(sr);
        float ndotwi = sr.normal * wi;
        if (ndotwi > 0.0) {
            bool in_shadow = false;
            if (sr.w.lights[j]->cast_shadows()) {
                Ray shadowRay(sr.hit_point, wi);
                in_shadow = sr.w.lights[j]->in_shadow(shadowRay, sr);
            }
            if (!in_shadow)
                L += diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr) * ndotwi;
        }
    }
    return L;
}

RGBColor Matte::area_light_shade(ShadeRec& sr) {
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    int num_lights= sr.w.lights.size();

    for (int j = 0; j < num_lights; j++) {
        Vector3D wi = sr.w.lights[j]->get_direction(sr);
        float ndotwi = sr.normal * wi;

        if (ndotwi > 0.0) {
            bool in_shadow = false;

            // if (sr.w.lights[j]->casts_shadows()) {
            if (sr.w.lights[j]->cast_shadows()) {
                Ray shadow_ray(sr.hit_point, wi);
                in_shadow = sr.w.lights[j]->in_shadow(shadow_ray, sr);
            }
            if (!in_shadow)
                L += diffuse_brdf->f(sr, wo, wi) * sr.w.lights[j]->L(sr) * ndotwi
                    * sr.w.lights[j]->G(sr) / sr.w.lights[j]->pdf(sr);
        }
    }

    return L;
}

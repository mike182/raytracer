#include "SV_Matte.hpp"

SV_Matte::SV_Matte(void)
    : Material(),
    ambient_brdf(new SV_Lambertian),
    diffuse_brdf(new SV_Lambertian)
{
}

SV_Matte::SV_Matte(const SV_Matte& m)
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

Material* SV_Matte::clone(void) const {
    return new SV_Matte(*this);
}

SV_Matte::~SV_Matte(void)
{
    if (ambient_brdf)
        delete ambient_brdf;
    if (diffuse_brdf)
        delete diffuse_brdf;
}

SV_Matte& SV_Matte::operator=(const SV_Matte& rhs) {
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

RGBColor SV_Matte::shade(ShadeRec& sr) {
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    int num_lights = sr.w.lights.size();

    for (int j = 0; j < num_lights; j++) {
        Light * light_ptr = sr.w.lights[j];
        Vector3D wi = light_ptr->get_direction(sr);
        wi.normalize();
        float ndotwi = sr.normal * wi;
        float ndotwo = sr.normal * wo;
        if (ndotwi > 0.0 && ndotwo > 0.0) {
            bool in_shadow = false;
            if (sr.w.lights[j]->cast_shadows()) {
                Ray shadowRay(sr.hit_point, wi);
                in_shadow = light_ptr->in_shadow(shadowRay, sr);
            }
            if (!in_shadow)
                // L += diffuse_brdf->f(sr, wo, wi) * light_ptr->L(sr) * light_ptr->G(sr) * ndotwi;
                L += diffuse_brdf->f(sr, wo, wi) * light_ptr->L(sr) * ndotwi;
        }
    }
    return L;
}

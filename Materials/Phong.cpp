#include "Phong.hpp"

Phong::Phong(void)
    : Material(),
    ambient_brdf(new Lambertian),
    diffuse_brdf(new Lambertian),
    specular_brdf(new GlossySpecular)
{
}

Phong::Phong(const Phong& m)
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

    if (m.specular_brdf)
        specular_brdf = m.specular_brdf->clone();
    else
        specular_brdf = nullptr;
}

Phong::~Phong(void)
{
    if (ambient_brdf)
        delete ambient_brdf;
    if (diffuse_brdf)
        delete diffuse_brdf;
    if (specular_brdf)
        delete specular_brdf;
}

Material* Phong::clone(void) const {
    return new Phong(*this);
}

Phong& Phong::operator=(const Phong& rhs) {
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

    if (specular_brdf) {
        delete specular_brdf;
        specular_brdf = nullptr;
    }
    if (rhs.specular_brdf)
        specular_brdf = rhs.specular_brdf->clone();

    return *this;
}

RGBColor Phong::shade(ShadeRec& sr) {
    Vector3D wo = -sr.ray.d;
    RGBColor L = ambient_brdf->rho(sr, wo) * sr.w.ambient_ptr->L(sr);
    int num_lights = sr.w.lights.size();

    for (int j = 0; j < num_lights; j++) {
        Vector3D wi = sr.w.lights[j]->get_direction(sr);
        float ndotwi = sr.normal * wi;
        if (ndotwi > 0.0)
            L += (diffuse_brdf->f(sr, wo, wi)
                  + specular_brdf->f(sr, wo, wi))
                  * sr.w.lights[j]->L(sr) * ndotwi;
    }
    return L;
}

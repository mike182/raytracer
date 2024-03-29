#include "GlossySpecular.hpp"
#include "MultiJittered.hpp"

GlossySpecular::GlossySpecular(void)
    : ks(0.0),
    cs(1.0),
    sampler(nullptr)
{
}

GlossySpecular::~GlossySpecular(void) {
}


GlossySpecular* GlossySpecular::clone (void) const {
    return new GlossySpecular(*this);
}

void GlossySpecular::set_sampler(Sampler* sp, const float exp) {
    sampler_ptr = sp;
    sampler_ptr->map_samples_to_hemisphere(exp);
}

void GlossySpecular::set_samples(const int num_samples, const float exp) {
    sampler_ptr = new MultiJittered(num_samples);
    sampler_ptr->map_samples_to_hemisphere(exp);
}

RGBColor GlossySpecular::f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const {
    RGBColor L;
    float ndotwi = sr.normal * wi;
    Vector3D r(-wi + 2.0 * sr.normal * ndotwi); // mirror reflection direction
    float rdotwo = r * wo;
    if (rdotwo > 0.0)
        L = ks * cs * pow(rdotwo, exp);
    return L;
}

RGBColor GlossySpecular::sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const {
    float ndotwo = sr.normal * wo;
    Vector3D r = -wo + 2.0 * sr.normal * ndotwo; // direction of mirror reflection
    Vector3D w = r;
    Vector3D u = Vector3D(0.00424, 1, 0.00764) ^ w;
    u.normalize();
    Vector3D v = u ^ w;
    Point3D sp = sampler_ptr->sample_hemisphere();
    wi = sp.x * u + sp.y * v + sp.z * w; // reflected ray direction
    if (sr.normal * wi < 0.0) // reflected ray is below tangent plane
        wi = -sp.x * u - sp.y * v + sp.z * w;

    float phong_lobe = pow(r * wi, exp);
    pdf = phong_lobe * (sr.normal * wi);
    return ks * cs * phong_lobe;
}

RGBColor GlossySpecular::rho([[maybe_unused]]const ShadeRec& sr, [[maybe_unused]]const Vector3D& wo) const {
    return black;
}

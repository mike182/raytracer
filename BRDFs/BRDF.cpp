#include "BRDF.hpp"

BRDF::BRDF(void)
    : sampler_ptr(nullptr)
{
}

BRDF::BRDF([[maybe_unused]] const BRDF& brdf) {
    if (brdf.sampler_ptr)
        sampler_ptr = brdf.sampler_ptr->clone();
    else
        sampler_ptr = nullptr;
}

BRDF::~BRDF(void) {
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = nullptr;
    }
}

BRDF& BRDF::operator= (const BRDF& rhs) {
    if (this == &rhs)
        return *this;
    if (sampler_ptr) {
        delete sampler_ptr;
        sampler_ptr = NULL;
    }
    if (rhs.sampler_ptr)
        sampler_ptr = rhs.sampler_ptr->clone();
    return *this;
}

void BRDF::set_sampler([[maybe_unused]]Sampler* sPtr) {
    sampler_ptr = sPtr;
    sampler_ptr->map_samples_to_hemisphere(1); // for perfect diffuse
}

RGBColor BRDF::f([[maybe_unused]] const ShadeRec& sr, [[maybe_unused]] const Vector3D& wo, [[maybe_unused]] const Vector3D& wi) const {
    return black;
}

RGBColor BRDF::sample_f([[maybe_unused]] const ShadeRec& sr, [[maybe_unused]] const Vector3D& wo, [[maybe_unused]] Vector3D& wi) const {
    return black;
}

RGBColor BRDF::sample_f([[maybe_unused]] const ShadeRec& sr, [[maybe_unused]] const Vector3D& wo, [[maybe_unused]] Vector3D& wi, [[maybe_unused]] float& pdf) const {
    return black;
}

RGBColor BRDF::rho([[maybe_unused]] const ShadeRec& sr, [[maybe_unused]] const Vector3D& wo) const {
    return black;
}

#include "BRDF.hpp"

BRDF::BRDF(void)
{
}

BRDF::BRDF([[maybe_unused]] const BRDF& brdf)
{
}

BRDF::~BRDF(void) {
}

BRDF& BRDF::operator= (const BRDF& rhs) {
    if (this == &rhs)
        return *this;
    return *this;
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
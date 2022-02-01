#ifndef __BRDF_HPP__
#define __BRDF_HPP__

#include "Constants.h"
#include "RGBColor.hpp"
#include "Vector3D.hpp"
#include "ShadeRec.hpp"
#include <cmath>

class BRDF {
public:
    BRDF(void);
    BRDF(const BRDF& brdf);
    virtual BRDF* clone(void) const = 0;
    virtual ~BRDF(void);

protected:
    BRDF& operator= (const BRDF& rhs);

public:
    virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
    virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi) const;
    virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;
    virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;
};

#endif // __BRDF_HPP__

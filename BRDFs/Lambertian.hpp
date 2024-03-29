#ifndef __LAMBERTIAN_HPP__
#define __LAMBERTIAN_HPP__

#include "BRDF.hpp"

class Lambertian: public BRDF {
public:
    Lambertian(void);
    Lambertian(const Lambertian& lamb);
    virtual Lambertian* clone(void) const;
    virtual ~Lambertian(void);

    Lambertian& operator=(const Lambertian& rhs);

    virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
    virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;
    virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;
    void set_ka(const float ka);
    void set_kd(const float kd);
    void set_cd(const RGBColor& c);
    void set_cd(const float r, const float g, const float b);
    void set_cd(const float c);

private:
    float kd;
    RGBColor cd;
};

inline void Lambertian::set_ka(const float k) {
    kd = k;
}

inline void Lambertian::set_kd(const float k) {
    kd = k;
}

inline void Lambertian::set_cd(const RGBColor& c) {
    cd = c;
}

inline void Lambertian::set_cd(const float r, const float g, const float b) {
    cd.r = r; cd.g = g; cd.b = b;
}

inline void Lambertian::set_cd(const float c) {
    cd.r = c; cd.g = c; cd.b = c;
}

#endif // __LAMBERTIAN_HPP__

#ifndef __SV_LAMBERTIAN_HPP__
#define __SV_LAMBERTIAN_HPP__

#include "BRDF.hpp"
#include "Texture.hpp"

class SV_Lambertian: public BRDF {
public:
    SV_Lambertian(void);
    SV_Lambertian(const SV_Lambertian& lamb);
    virtual SV_Lambertian* clone(void) const;
    virtual ~SV_Lambertian(void);

    SV_Lambertian& operator=(const SV_Lambertian& rhs);

    virtual RGBColor f(const ShadeRec& sr, const Vector3D& wo, const Vector3D& wi) const;
    virtual RGBColor sample_f(const ShadeRec& sr, const Vector3D& wo, Vector3D& wi, float& pdf) const;
    virtual RGBColor rho(const ShadeRec& sr, const Vector3D& wo) const;
    void set_ka(const float ka);
    void set_kd(const float kd);
    void set_cd(Texture* t_ptr);
    // void set_cd(const RGBColor& c);
    // void set_cd(const float r, const float g, const float b);
    // void set_cd(const float c);

private:
    float kd;
    Texture* cd;
};

inline void SV_Lambertian::set_ka(const float k) {
    kd = k;
}

inline void SV_Lambertian::set_kd(const float k) {
    kd = k;
}

inline void SV_Lambertian::set_cd(Texture* t_ptr) {
    if (cd)
        delete cd;
    cd = t_ptr;
}

// inline void SV_Lambertian::set_cd(const RGBColor& c) {
//     cd = c;
// }

// inline void SV_Lambertian::set_cd(const float r, const float g, const float b) {
//     cd.r = r; cd.g = g; cd.b = b;
// }

// inline void SV_Lambertian::set_cd(const float c) {
//     cd.r = c; cd.g = c; cd.b = c;
// }

#endif // __SV_LAMBERTIAN_HPP__

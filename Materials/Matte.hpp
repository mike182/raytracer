#ifndef __MATTE_H__
#define __MATTE_H__

#include "Material.hpp"
#include "Lambertian.hpp"

class Matte : public Material {
public:
    Matte(void);
    Matte(const Matte& m);
    virtual Material* clone(void) const;
    virtual ~Matte(void);

    Matte& operator=(const Matte& rhs);

    virtual RGBColor shade(ShadeRec& sr);

    void set_ka(const float k);
    void set_kd(const float k);
    void set_cd(const RGBColor c);
    void set_cd(const float r, const float g, const float b);
    void set_cd(const float c);

public:
    Lambertian* ambient_brdf;
    Lambertian* diffuse_brdf;
};

inline void Matte::set_ka(const float ka) {
    ambient_brdf->set_kd(ka);
}

inline void Matte::set_kd (const float kd) {
    diffuse_brdf->set_kd(kd);
}

inline void Matte::set_cd(const RGBColor c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

inline void Matte::set_cd(const float r, const float g, const float b) {
    ambient_brdf->set_cd(r, g, b);
    diffuse_brdf->set_cd(r, g, b);
}

inline void Matte::set_cd(const float c) {
    ambient_brdf->set_cd(c);
    diffuse_brdf->set_cd(c);
}

#endif // __MATTE_H__

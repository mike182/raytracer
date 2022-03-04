#ifndef __ENVIRONMENTLIGHT_HPP__
#define __ENVIRONMENTLIGHT_HPP__

#include "Light.hpp"
#include "Sampler.hpp"
#include "Material.hpp"

class EnvironmentLight: public Light {
public:
    EnvironmentLight();
    EnvironmentLight(const EnvironmentLight& el);
    // virtual EnvironmentLight* clone() const;
    virtual Light* clone() const;
    virtual ~EnvironmentLight();
    EnvironmentLight& operator=(const EnvironmentLight& rhs);

    void set_sampler(Sampler* sampler);
    virtual Vector3D get_direction(ShadeRec& s);
    virtual RGBColor L(ShadeRec& sr);
    bool in_shadow(const Ray& ray, const ShadeRec& sr) const;
    virtual float pdf(const ShadeRec& sr) const;

private:
    Sampler* sampler_ptr;
    Material* material_ptr;
    Vector3D u, v, w;
    Vector3D wi;
};

#endif // __ENVIRONMENTLIGHT_HPP__

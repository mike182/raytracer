#ifndef __AMBIENTOCCLUDER_HPP__
#define __AMBIENTOCCLUDER_HPP__

#include "Light.hpp"
#include "Vector3D.hpp"
#include "RGBColor.hpp"
// #include "World.hpp" // shadows
#include "ShadeRec.hpp"

class Sampler;

class AmbientOccluder : public Light {
public:
    AmbientOccluder(void);
    AmbientOccluder(const AmbientOccluder& ao);
    virtual AmbientOccluder* clone(void) const;
    virtual ~AmbientOccluder(void);

    AmbientOccluder& operator=(const AmbientOccluder& rhs);

    void set_sampler(Sampler* s_ptr);
    virtual Vector3D get_direction(ShadeRec& sr);
    virtual RGBColor L(ShadeRec& sr);
    virtual bool in_shadow(const Ray& ray, const ShadeRec& sr) const;

private:
    float ls;
    RGBColor color;
    RGBColor min_amount;
    Sampler* sampler_ptr;
    Vector3D u, v, w;
};

#endif // __AMBIENTOCCLUDER_HPP__

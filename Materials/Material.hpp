#ifndef __MATERIAL_HPP__
#define __MATERIAL_HPP__

#include "World.hpp"
#include "RGBColor.hpp"
#include "ShadeRec.hpp"

class Material {
public:
    Material(void);
    Material(const Material& m);
    virtual Material* clone(void) const = 0;
    virtual ~Material(void);

    virtual RGBColor shade(ShadeRec& sr);

    // Emissive
    virtual RGBColor get_Le(ShadeRec& sr) const;

protected:
    Material& operator=(const Material& rhs);

protected:
    bool in_shadow;
};

#endif // __MATERIAL_HPP__

#ifndef __TEXTURE_HPP__
#define __TEXTURE_HPP__

#include "ShadeRec.hpp"
#include "RGBColor.hpp"

class Texture {
public:
    Texture(void);
    Texture(const Texture& t);
    virtual Texture* clone(void) const = 0;
    virtual ~Texture(void);

protected:
    Texture& operator=(const Texture& rhs);

public:
    virtual RGBColor get_color(const ShadeRec& sr) const = 0;
};

#endif // __TEXTURE_HPP__

#ifndef __ORTHOGRAPHIC_HPP__
#define __ORTHOGRAPHIC_HPP__

#include "Camera.hpp"
#include "World.hpp"

class Orthographic : public Camera {
public:
    Orthographic(void);
    Orthographic(const Orthographic& ph);
    virtual Camera* clone(void) const;
    virtual ~Orthographic(void);

    Orthographic& operator=(const Orthographic& rhs);

    virtual void render_scene(const World& w);
};

#endif // __ORTHOGRAPHIC_HPP__

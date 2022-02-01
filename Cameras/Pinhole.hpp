#ifndef __PINHOLE_HPP__
#define __PINHOLE_HPP__

#include "Camera.hpp"
#include "Point2D.hpp"
#include "World.hpp"

class Pinhole : public Camera {
public:
    Pinhole(void);
    Pinhole(const Pinhole& ph);
    virtual Camera* clone(void) const;
    virtual ~Pinhole(void);

    Pinhole& operator=(const Pinhole& rhs);

    virtual void render_scene(const World& w);

    void set_view_distance(const float vd);
    void set_zoom(const float zoom_factor);
    Vector3D get_direction(const Point2D& p) const;

public:
    float d; // vp distance
    float zoom; // zoom factor
};

inline void Pinhole::set_view_distance(const float vd) {
    d = vd;
}

inline void Pinhole::set_zoom(const float zf) {
    zoom = zf;
}

#endif // __PINHOLE_HPP__

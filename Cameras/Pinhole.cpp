#include "Pinhole.hpp"
#include "Constants.h"
#include "Point3D.hpp"
#include "Vector3D.hpp"
#include <cmath>

Pinhole::Pinhole(void)
    : Camera(),
    d(500),
    zoom(1.0)
{
}

Pinhole::Pinhole(const Pinhole& ph)
    : Camera(ph),
    d(ph.d),
    zoom(ph.zoom)
{
}

Camera* Pinhole::clone(void) const {
    return new Pinhole(*this);
}


Pinhole::~Pinhole(void) {
}

Pinhole& Pinhole::operator=(const Pinhole& rhs) {
    if (this == &rhs)
        return *this;
    Camera::operator=(rhs);
    d = rhs.d;
    zoom = rhs.zoom;
    return *this;
}

Vector3D Pinhole::get_direction(const Point2D& p) const {
    Vector3D dir = p.x * u + p.y * v - d * w;
    dir.normalize();
    return dir;
}

void Pinhole::render_scene(const World& w) {
    RGBColor L;
    ViewPlane vp(w.vp);
    Ray ray;
    int depth = 0;
    Point2D pp;
    int n = (int)sqrt((float)vp.num_samples);

    vp.s /= zoom;
    ray.o = eye;
    w.image->set_resolution(vp.hres, vp.vres); // image file
    for (int r = 0; r < vp.vres; r++) // up
        for (int c = 0; c < vp.hres; c++) { // across
            L = black;
            for (int p = 0; p < n; p++)	// up pixel
                for (int q = 0; q < n; q++) { // across pixel
                    pp.x = vp.s * (c - 0.5 * vp.hres + (q + 0.5) / n);
                    pp.y = vp.s * (r - 0.5 * vp.vres + (p + 0.5) / n);
                    ray.d = get_direction(pp);
                    L += w.tracer_ptr->trace_ray(ray, depth);
                }
            L /= vp.num_samples;
            L *= exposure_time;
            w.display_pixel(r, c, L);
        }
    w.image->save_image(FILE_PNG); // image file
}

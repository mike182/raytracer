#include "Pinhole.hpp"
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

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

Vector3D Pinhole::ray_direction(const Point2D& p) const {
    Vector3D dir = p.x * u + p.y * v - d * w;
    dir.normalize();
    return dir;
}

void Pinhole::render_scene(const World& w) {
    RGBColor L;
    ViewPlane vp(w.vp);
    Ray ray;
    int depth = 0;
    Point2D sp;
    Point2D pp;

    vp.s /= zoom;
    ray.o = eye;
    w.image_ptr->set_resolution(vp.hres, vp.vres); // image file
    for (int r = 0; r < vp.vres; r++) // up
        for (int c = 0; c < vp.hres; c++) { // across
            L = black;
            for (int i = 0; i < vp.num_samples; i++) {
                sp = vp.sampler_ptr->sample_unit_square();
                pp.x = vp.s * (c - 0.5 * vp.hres + sp.x);
                pp.y = vp.s * (r - 0.5 * vp.vres + sp.y);
                ray.d = ray_direction(pp);
                L += w.tracer_ptr->trace_ray(ray, depth);
            }
            L /= vp.num_samples;
            L *= exposure_time;
            w.display_pixel(r, c, L);
        }
    w.image_ptr->save_image(FILE_PNG); // image file
}

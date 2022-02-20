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
    // // render color only
    // for (int r = 0; r < vp.vres; r++) { // up
    //     for (int c = 0; c < vp.hres; c++) { // across
    //         L = black;
    //         pp.x = (c - 0.5 * vp.hres + ( + 0.5));
    //         pp.y = (r - 0.5 * vp.vres + ( 0.5));
    //         ray.d = ray_direction(pp);
    //         L = w.tracer_ptr->trace_ray(ray, depth);
    //         w.display_pixel(r, c, L);
    //gfx_ptr->get_event();
    //     w.gfx_ptr->render_line();
    // }

    // render full
    for (int r = 0; r < vp.vres; r++) { // up
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
            // if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
                // exit(EXIT_FAILURE);
        }
        w.gfx_ptr->render_line();
    }
    w.gfx_ptr->end();
}

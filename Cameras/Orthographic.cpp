#include "Orthographic.hpp"
#include "Point2D.hpp"
#include "Point3D.hpp"
#include "Vector3D.hpp"

Orthographic::Orthographic(void)
    : Camera()
{
    set_eye(0, 0, 1);
    set_lookat(0, 0, -1);
}

Orthographic::Orthographic(const Orthographic& ph)
    : Camera(ph)
{
}

Camera* Orthographic::clone(void) const {
    return new Orthographic(*this);
}


Orthographic::~Orthographic(void) {
}

Orthographic& Orthographic::operator=(const Orthographic& rhs) {
    if (this == &rhs)
        return *this;
    Camera::operator=(rhs);
    return *this;
}

void Orthographic::render_scene(const World& w) {
    RGBColor pixel_color;
    ViewPlane vp(w.vp);
    Ray ray;
    double zw = 100.0;
    int depth = 0;
    Point2D sp;
    Point2D pp;

    ray.d = Vector3D(0, 0, -1);
    for (int r = 0; r < vp.vres; r++) { // up
        for (int c = 0; c < vp.hres; c++) { // across
            pixel_color = black;
            for (int i = 0; i < vp.num_samples; i++) {
                sp = vp.sampler_ptr->sample_unit_square();
                pp.x = vp.s * (c - 0.5 * vp.hres + sp.x);
                pp.y = vp.s * (r - 0.5 * vp.vres + sp.y);
                ray.o = Point3D(pp.x, pp.y, zw);
                pixel_color += w.tracer_ptr->trace_ray(ray, depth);
            }
            pixel_color /= vp.num_samples;
            pixel_color *= exposure_time;
            w.display_pixel(r, c, pixel_color);
        }
        w.gfx_ptr->render_line();
    }
    w.gfx_ptr->end();
}

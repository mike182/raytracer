// This builds the scene for Figure 3.18 - the single red sphere

#include "World.hpp"
#include "MultipleObjects.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"

void World::build(void) {
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_pixel_size(1.0);
    vp.num_samples = 4;

    background_color = black;
    tracer_ptr = new MultipleObjects(this);

    Sphere* sphere_ptr = new Sphere;
    sphere_ptr->set_center(0.0);
    sphere_ptr->set_radius(85.0);
    sphere_ptr->set_color(1, 0, 0);  // red
    add_object(sphere_ptr);

}

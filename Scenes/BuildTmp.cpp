// this builds the page one image for Chapter 3: Bare Bones Ray Tracing

#include "World.hpp"
#include "RayCast.hpp"
#include "Camera.hpp"
#include "Pinhole.hpp"
#include "MultipleObjects.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"
#include "Material.hpp"
#include "Matte.hpp"

#include "Jittered.hpp"

void World::build(void) {

    int num_samples = 4;

    vp.set_hres(400);
    vp.set_vres(400);
    vp.set_samples(num_samples);

    tracer_ptr = new RayCast(this);

    // Jittered* sampler_ptr = new Jittered(num_samples);
    // vp.set_sampler(sampler_ptr); // for 4.8(b)
    vp.set_sampler(new Jittered(num_samples));

    Ambient* ambient_ptr = new Ambient;
    ambient_ptr->scale_radiance(1.0);
    ambient_ptr->set_color(red);
    set_ambient_light(ambient_ptr);

    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(0, 0, 500.0);
    pinhole_ptr->set_lookat(-5, 0, 0);
    pinhole_ptr->set_view_distance(850.0);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);

    PointLight* light_ptr2 = new PointLight;
    light_ptr2->set_location(100, 50, 150);
    light_ptr2->scale_radiance(3.0);
    add_light(light_ptr2);

    Matte* matte_ptr1 = new Matte;
    matte_ptr1->set_ka(0.25);
    matte_ptr1->set_kd(0.65);
    matte_ptr1->set_cd(1, 1, 0);	  				// yellow
    Sphere*	sphere_ptr1 = new Sphere(Point3D(10, -5, 0), 27);
    sphere_ptr1->set_material(matte_ptr1);
    add_object(sphere_ptr1);

    Matte* matte_ptr2 = new Matte;
    matte_ptr2->set_ka(0.15);
    matte_ptr2->set_kd(0.85);
    matte_ptr2->set_cd(0.71, 0.40, 0.16);   		// brown
    Sphere*	sphere_ptr2 = new Sphere(Point3D(-25, 10, -35), 27);
    sphere_ptr2->set_material(matte_ptr2);
    add_object(sphere_ptr2);

    Matte* matte_ptr3 = new Matte;
    matte_ptr3->set_ka(0.15);
    matte_ptr3->set_kd(0.5);
    matte_ptr3->set_cd(0, 0.4, 0.2);				// dark green
    Plane* plane_ptr = new Plane(Point3D(0, 0, -50), Normal(0, 0, 1));
    plane_ptr->set_material(matte_ptr3);
    add_object(plane_ptr);
}

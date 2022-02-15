#include "World.hpp"
#include "Constants.h" // Utilities
#include "Lambertian.hpp" // BRDFs
#include "GlossySpecular.hpp"
#include "Orthographic.hpp" // Cameras
#include "Pinhole.hpp"
#include "Plane.hpp" // GeometricObjects
#include "Sphere.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "Ambient.hpp" // Lights
#include "Directional.hpp"
#include "PointLight.hpp"
#include "AmbientOccluder.hpp"
#include "Matte.hpp" // Materials
#include "Phong.hpp"
#include "Regular.hpp" // Samplers
#include "PureRandom.hpp"
#include "NRooks.hpp"
#include "Hammersley.hpp"
#include "Jittered.hpp"
#include "MultiJittered.hpp"
#include "MultipleObjects.hpp" // Tracers
#include "RayCast.hpp"

// builds the scene for Figure 3.20(a)

void World::build(void) {
    vp.set_hres(200);
    vp.set_vres(200);

    background_color = black;
    tracer_ptr = new MultipleObjects(this);

    // use access functions to set center and radius for this sphere

    Sphere* sphere_ptr = new Sphere;
    sphere_ptr->set_center(0, -25, 0);
    sphere_ptr->set_radius(80.0);
    sphere_ptr->set_color(1, 0, 0);  // red
    add_object(sphere_ptr);

    // use a constructor to set center and radius for this sphere

    sphere_ptr = new Sphere(Point3D(0, 30, 0), 60);
    sphere_ptr->set_color(1, 1, 0);	// yellow
    add_object(sphere_ptr);


    Plane* plane_ptr = new Plane(Point3D(0.0), Normal(0, 1, 1));
    plane_ptr->set_color(0.0, 0.25, 0.0);	// dark green
    add_object(plane_ptr);
}

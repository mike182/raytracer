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
#include "Box.hpp"
#include "Ambient.hpp" // Lights
#include "Directional.hpp"
#include "PointLight.hpp"
#include "AmbientOccluder.hpp"
#include "AreaLight.hpp"
#include "Matte.hpp" // Materials
#include "SV_Matte.hpp"
#include "Phong.hpp"
#include "Emissive.hpp"
#include "Regular.hpp" // Samplers
#include "PureRandom.hpp"
#include "NRooks.hpp"
#include "Hammersley.hpp"
#include "Jittered.hpp"
#include "MultiJittered.hpp"
#include "Texture.hpp" // Textures
#include "Checker3D.hpp"
#include "RayCast.hpp" // Tracers
#include "AreaLighting.hpp"

// This builds the scene for Figure 18.4

void World::build(void) {
    // int num_samples = 1; // for Figure 18.4(a)
    int num_samples = 100; // for Figure 18.4(b) & (c)

    Sampler* sampler_ptr = new MultiJittered(num_samples);

    vp.set_hres(600);
    vp.set_vres(600);
    vp.set_sampler(sampler_ptr);

    background_color = RGBColor(0.5);

    tracer_ptr = new AreaLighting(this);

    Pinhole* camera = new Pinhole;
    camera->set_eye(-20, 10, 20);
    camera->set_lookat(0, 2, 0);
    camera->set_view_distance(1080);
    camera->compute_uvw();
    set_camera(camera);


    Emissive* emissive_ptr = new Emissive;
    emissive_ptr->scale_radiance(40.0);
    emissive_ptr->set_ce(white);


    // define a rectangle for the rectangular light

    float width = 4.0;				// for Figure 18.4(a) & (b)
    float height = 4.0;
    // float width = 2.0;				// for Figure 18.4(c)
    // float height = 2.0;
    Point3D center(0.0, 7.0, -7.0);	// center of each area light (rectangular, disk, and spherical)
    Point3D p0(-0.5 * width, center.y - 0.5 * height, center.z);
    Vector3D a(width, 0.0, 0.0);
    Vector3D b(0.0, height, 0.0);
    Normal normal(0, 0, 1);

    Rectangle* rectangle_ptr = new Rectangle(p0, a, b, normal);
    rectangle_ptr->set_material(emissive_ptr);
    rectangle_ptr->set_sampler(sampler_ptr);
    rectangle_ptr->set_shadows(false);
    add_object(rectangle_ptr);


    AreaLight* area_light_ptr = new AreaLight;
    area_light_ptr->set_object(rectangle_ptr);
    area_light_ptr->set_shadows(true);
    add_light(area_light_ptr);


    // Four axis aligned boxes

    float box_width 	= 1.0; 		// x dimension
    float box_depth 	= 1.0; 		// z dimension
    float box_height 	= 4.5; 		// y dimension
    float gap		= 3.0;

    Matte* matte_ptr1 = new Matte;
    matte_ptr1->set_ka(0.25);
    matte_ptr1->set_kd(0.75);
    matte_ptr1->set_cd(0.4, 0.7, 0.4);     // green

    Box* box_ptr0 = new Box(Point3D(- 1.5 * gap - 2.0 * box_width, 0.0, -0.5 * box_depth),
                            Point3D(-1.5 * gap  - box_width, box_height, 0.5 * box_depth));
    box_ptr0->set_material(matte_ptr1);
    add_object(box_ptr0);

    Box* box_ptr1 = new Box(Point3D(- 0.5 * gap - box_width, 0.0, -0.5 * box_depth),
                            Point3D(-0.5 * gap, box_height, 0.5 * box_depth));
    box_ptr1->set_material(matte_ptr1);
    add_object(box_ptr1);

    Box* box_ptr2 = new Box(Point3D(0.5 * gap, 0.0, -0.5 * box_depth),
                            Point3D(0.5 * gap + box_width, box_height, 0.5 * box_depth));
    box_ptr2->set_material(matte_ptr1);
    add_object(box_ptr2);

    Box* box_ptr3 = new Box(Point3D(1.5 * gap + box_width, 0.0, -0.5 * box_depth),
                            Point3D(1.5 * gap + 2.0 * box_width, box_height, 0.5 * box_depth));
    box_ptr3->set_material(matte_ptr1);
    add_object(box_ptr3);


    // ground plane

    Matte* matte_ptr2 = new Matte;
    matte_ptr2->set_ka(0.1);
    matte_ptr2->set_kd(0.90);
    matte_ptr2->set_cd(white);

    Plane* plane_ptr = new Plane(Point3D(0.0), Normal(0, 1, 0));
    plane_ptr->set_material(matte_ptr2);
    add_object(plane_ptr);
}

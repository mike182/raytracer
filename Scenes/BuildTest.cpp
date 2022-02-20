#include "World.hpp"
#include "Constants.h" // Utilities
#include "Lambertian.hpp" // BRDFs
#include "GlossySpecular.hpp"
#include "Orthographic.hpp" // Cameras
#include "Pinhole.hpp"
#include "Plane.hpp" // GeometricObjects
#include "Sphere.hpp"
#include "Rectangle.hpp"
#include "Ambient.hpp" // Lights
#include "Directional.hpp"
#include "PointLight.hpp"
#include "AmbientOccluder.hpp"
#include "Matte.hpp" // Materials
#include "SV_Matte.hpp"
#include "Phong.hpp"
#include "Regular.hpp" // Samplers
#include "PureRandom.hpp"
#include "NRooks.hpp"
#include "Hammersley.hpp"
#include "Jittered.hpp"
#include "MultiJittered.hpp"
#include "Texture.hpp" // Textures
#include "Checker3D.hpp"
#include "MultipleObjects.hpp" // Tracers
#include "RayCast.hpp"

// 26.7

void World::build(void) {
    // int num_samples = 1; // for Figure 26.7(a)
    // int num_samples = 100; // for Figure 26.7(b)
    // int num_samples = 1024; // for Figure 26.7(c)
    // int num_samples = 10000; // for Figure 26.7(d)

    int num_samples = 16;
    vp.set_hres(300);
    vp.set_vres(300);
    vp.set_samples(num_samples);
    // vp.set_max_depth(10);

    background_color = black;

    tracer_ptr = new RayCast(this);
    // tracer_ptr = new PathTrace(this);

    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(27.6, 27.4, -80.0);
    pinhole_ptr->set_lookat(27.6, 27.4, 0.0);
    pinhole_ptr->set_view_distance(400);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);

    Point3D p0;
    Vector3D a, b;
    Normal normal;

    // box dimensions

    double width 	= 55.28;   	// x direction
    double height 	= 54.88;  	// y direction
    double depth 	= 55.92;	// z direction


    // the ceiling light - doesn't need samples

    // Emissive* emissive_ptr = new Emissive;
    // emissive_ptr->set_ce(1.0, 0.73, 0.4);
    // emissive_ptr->scale_radiance(100);

    // p0 = Point3D(21.3, height - 0.001, 22.7);
    // a = Vector3D(0.0, 0.0, 10.5);
    // b = Vector3D(13.0, 0.0, 0.0);
    // normal = Normal(0.0, -1.0, 0.0);
    // Rectangle* light_ptr = new Rectangle(p0, a, b, normal);
    // light_ptr->set_material(emissive_ptr);
    // add_object(light_ptr);

    // p0 = Point3D(0.0, height, 0.0);
    // a = Vector3D(0.0, 0.0, depth);
    // b = Vector3D(width, 0.0, 0.0);


    // items
    // -----
    float radius = 6;
    Point3D center(27.64, radius, 27.96);
    int spheres = 0;

    int boxes = 1;

    float ka_red = 0.6;
    float ka_green = 0.6;
    float ka_white = 0.6;

    ka_red = ka_green = ka_white = 0.2;

    int sampl = 128;
    // tmp light
    // ---------
    // PointLight* light_ptr = new PointLight();
    // // light_ptr->set_location(21.3, height - 0.001, 22.7); // for rectangle light
    // light_ptr->set_location(27.64, height - 1.1, 27.96); // centered
    // light_ptr->set_shadows(true);
    // add_light(light_ptr);

    // tmp ambient occluder
    // --------------------
    vp.set_samples(sampl);
    MultiJittered* sampler_ptr = new MultiJittered(sampl);
    AmbientOccluder* occluder_ptr = new AmbientOccluder();
    occluder_ptr->scale_radiance(1.3);
    occluder_ptr->set_min_amount(0);
    occluder_ptr->set_sampler(sampler_ptr);
    set_ambient_light(occluder_ptr);

    // left wall

    Matte* matte_ptr1 = new Matte;
    matte_ptr1->set_ka(ka_red);
    matte_ptr1->set_kd(0.6);
    matte_ptr1->set_cd(0.57, 0.025, 0.025);	 // red
    // matte_ptr1->set_sampler(new MultiJittered(num_samples));

    p0 = Point3D(width, 0.0, 0.0);
    a = Vector3D(0.0, 0.0, depth);
    b = Vector3D(0.0, height, 0.0);
    normal = Normal(-1.0, 0.0, 0.0);
    Rectangle* left_wall_ptr = new Rectangle(p0, a, b, normal);
    left_wall_ptr->set_material(matte_ptr1);
    add_object(left_wall_ptr);


    // right wall

    Matte* matte_ptr2 = new Matte;
    matte_ptr2->set_ka(ka_green);
    matte_ptr2->set_kd(0.6);
    matte_ptr2->set_cd(0.37, 0.59, 0.2);	 // green   from Photoshop
    // matte_ptr2->set_sampler(new MultiJittered(num_samples));

    p0 = Point3D(0.0, 0.0, 0.0);
    a = Vector3D(0.0, 0.0, depth);
    b = Vector3D(0.0, height, 0.0);
    normal = Normal(1.0, 0.0, 0.0);
    Rectangle* right_wall_ptr = new Rectangle(p0, a, b, normal);
    right_wall_ptr->set_material(matte_ptr2);
    add_object(right_wall_ptr);


    // back wall

    Matte* matte_ptr3 = new Matte;
    matte_ptr3->set_ka(ka_white);
    matte_ptr3->set_kd(0.6);
    matte_ptr3->set_cd(1.0);	 // white
    // matte_ptr3->set_sampler(new MultiJittered(num_samples));

    p0 = Point3D(0.0, 0.0, depth);
    a = Vector3D(width, 0.0, 0.0);
    b = Vector3D(0.0, height, 0.0);
    normal = Normal(0.0, 0.0, -1.0);
    Rectangle* back_wall_ptr = new Rectangle(p0, a, b, normal);
    back_wall_ptr->set_material(matte_ptr3);
    add_object(back_wall_ptr);


    // floor

    p0 = Point3D(0.0, 0.0, 0.0);
    a = Vector3D(0.0, 0.0, depth);
    b = Vector3D(width, 0.0, 0.0);
    normal = Normal(0.0, 1.0, 0.0);
    Rectangle* floor_ptr = new Rectangle(p0, a, b, normal);
    floor_ptr->set_material(matte_ptr3);
    add_object(floor_ptr);


    // ceiling

    p0 = Point3D(0.0, height, 0.0);
    a = Vector3D(0.0, 0.0, depth);
    b = Vector3D(width, 0.0, 0.0);
    normal = Normal(0.0, -1.0, 0.0);
    Rectangle* ceiling_ptr = new Rectangle(p0, a, b, normal);
    ceiling_ptr->set_material(matte_ptr3);
    add_object(ceiling_ptr);


    // spheres
    if (spheres) {
        Sphere* sphere_ptr = new Sphere(center, radius);
        sphere_ptr->set_material(matte_ptr3);
        add_object(sphere_ptr);
    }

    // boxes
    if (boxes) {

    // the two boxes defined as 5 rectangles each

    // short box

    // top

    p0 = Point3D(13.0, 16.5, 6.5);
    a = Vector3D(-4.8, 0.0, 16.0);
    b = Vector3D(16.0, 0.0, 4.9);
    normal = Normal(0.0, 1.0, 0.0);
    Rectangle* short_top_ptr = new Rectangle(p0, a, b, normal);
    short_top_ptr->set_material(matte_ptr3);
    add_object(short_top_ptr);


    // side 1

    p0 = Point3D(13.0, 0.0, 6.5);
    a = Vector3D(-4.8, 0.0, 16.0);
    b = Vector3D(0.0, 16.5, 0.0);
    Rectangle* short_side_ptr1 = new Rectangle(p0, a, b);
    short_side_ptr1->set_material(matte_ptr3);
    add_object(short_side_ptr1);


    // side 2

    p0 = Point3D(8.2, 0.0, 22.5);
    a = Vector3D(15.8, 0.0, 4.7);
    Rectangle* short_side_ptr2 = new Rectangle(p0, a, b);
    short_side_ptr2->set_material(matte_ptr3);
    add_object(short_side_ptr2);


    // side 3

    p0 = Point3D(24.2, 0.0, 27.4);
    a = Vector3D(4.8, 0.0, -16.0);
    Rectangle* short_side_ptr3 = new Rectangle(p0, a, b);
    short_side_ptr3->set_material(matte_ptr3);
    add_object(short_side_ptr3);


    // side 4

    p0 = Point3D(29.0, 0.0, 11.4);
    a = Vector3D(-16.0, 0.0, -4.9);
    Rectangle* short_side_ptr4 = new Rectangle(p0, a, b);
    short_side_ptr4->set_material(matte_ptr3);
    add_object(short_side_ptr4);




    // tall box

    // top

    p0 = Point3D(42.3, 33.0, 24.7);
    a = Vector3D(-15.8, 0.0, 4.9);
    b = Vector3D(4.9, 0.0, 15.9);
    normal = Normal(0.0, 1.0, 0.0);
    Rectangle* tall_top_ptr = new Rectangle(p0, a, b, normal);
    tall_top_ptr->set_material(matte_ptr3);
    add_object(tall_top_ptr);


    // side 1

    p0 = Point3D(42.3, 0.0, 24.7);
    a = Vector3D(-15.8, 0.0, 4.9);
    b = Vector3D(0.0, 33.0, 0.0);
    Rectangle* tall_side_ptr1 = new Rectangle(p0, a, b);
    tall_side_ptr1->set_material(matte_ptr3);
    add_object(tall_side_ptr1);


    // side 2

    p0 = Point3D(26.5, 0.0, 29.6);
    a = Vector3D(4.9, 0.0, 15.9);
    Rectangle* tall_side_ptr2 = new Rectangle(p0, a, b);
    tall_side_ptr2->set_material(matte_ptr3);
    add_object(tall_side_ptr2);


    // side 3

    p0 = Point3D(31.4, 0.0, 45.5);
    a = Vector3D(15.8, 0.0, -4.9);
    Rectangle* tall_side_ptr3 = new Rectangle(p0, a, b);
    tall_side_ptr3->set_material(matte_ptr3);
    add_object(tall_side_ptr3);


    // side 4

    p0 = Point3D(47.2, 0.0, 40.6);
    a = Vector3D(-4.9, 0.0, -15.9);
    Rectangle* tall_side_ptr4 = new Rectangle(p0, a, b);
    tall_side_ptr4->set_material(matte_ptr3);
    add_object(tall_side_ptr4);
    }
}

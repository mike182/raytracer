#include "World.hpp"
#include "Constants.h" // Utilities
#include "Lambertian.hpp" // BRDFs
#include "GlossySpecular.hpp"
#include "Orthographic.hpp" // Cameras
#include "Pinhole.hpp"
#include "Instance.hpp" // GeometricObjects
#include "Plane.hpp"
#include "Sphere.hpp"
#include "OpenCylinder.hpp"
#include "Disk.hpp"
#include "Torus.hpp"
#include "Rectangle.hpp"
#include "Triangle.hpp"
#include "OpenCone.hpp"
#include "SolidCylinder.hpp"
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
    int num_samples = 1;
    // int num_samples = 16;

    vp.set_hres(600);
    vp.set_vres(400);
    vp.set_samples(num_samples);

    tracer_ptr = new RayCast(this);

    Ambient* ambient_ptr = new Ambient;
    ambient_ptr->scale_radiance(0.5);
    set_ambient_light(ambient_ptr);

    float a = 0.75;
    background_color = RGBColor(0.0, 0.3 * a, 0.25 * a);  // torquise

    Pinhole* pinhole_ptr = new Pinhole;
    pinhole_ptr->set_eye(0, 4, 100);
    // pinhole_ptr->set_eye(0, 4, 10);
    pinhole_ptr->set_lookat(0, 4, 0);
    pinhole_ptr->set_view_distance(3250);
    pinhole_ptr->compute_uvw();
    set_camera(pinhole_ptr);

    // lights
    Directional* light_ptr = new Directional;
    light_ptr->set_direction(55, 15, 100);
    light_ptr->scale_radiance(2.0);
    light_ptr->set_shadows(true);
    add_light(light_ptr);


    Phong* phong_ptr1 = new Phong();
    phong_ptr1->set_ka(0.45);
    phong_ptr1->set_kd(0.8);
    phong_ptr1->set_ks(0.15);
    phong_ptr1->set_exp(50);
    phong_ptr1->set_cd(0.75, 0.75, 0);    	// dark yellow

    Phong* phong_ptr2 = new Phong();
    phong_ptr2->set_ka(0.25);
    phong_ptr2->set_kd(0.6);
    phong_ptr2->set_ks(0.25);
    phong_ptr2->set_exp(100);
    phong_ptr2->set_cd(1, 0.5, 1);  		// mauve

    Matte* matte_ptr2 = new Matte;
    matte_ptr2->set_ka(0.45);
    matte_ptr2->set_kd(0.75);
    matte_ptr2->set_cd(0.75, 0.25, 0);  	 // orange

    Matte* matte_ptr3 = new Matte;
    matte_ptr3->set_ka(0.4);
    matte_ptr3->set_kd(0.75);
    matte_ptr3->set_cd(1, 0.5, 1);  		// mauve

    Matte* matte_ptr4 = new Matte;
    matte_ptr4->set_ka(a);
    matte_ptr4->set_ka(0.15);
    matte_ptr4->set_kd(0.5);
    matte_ptr4->set_cd(0.75, 1.0, 0.75);   	// light green

    Matte* matte_ptr5 = new Matte;
    matte_ptr5->set_ka(0.20);
    matte_ptr5->set_kd(0.97);
    matte_ptr5->set_cd(white);

    // dark green triangle (transformed)
    Matte* matte_ptr6 = new Matte;
    matte_ptr6->set_ka(0.25);
    matte_ptr6->set_kd(0.75);
    matte_ptr6->set_cd(0.0, 0.5, 0.41);

    Matte* matte_ptr7 = new Matte;
    matte_ptr7->set_ka(0.70);
    matte_ptr7->set_kd(0.97);
    matte_ptr7->set_cd(RGBColor(0.4, 0.4, 0.9));

    // ground plane
    Plane* plane_ptr = new Plane(Point3D(0), Normal(0, 1, 0));
    plane_ptr->set_material(matte_ptr5);
    add_object(plane_ptr);

    // spheres

    Sphere* sphere_ptr1 = new Sphere(Point3D(4, 1.75, 0), 1.75);
    sphere_ptr1->set_material(phong_ptr1);
    add_object(sphere_ptr1);

    // cylinder

    // OpenCylinder* cylinder_ptr = new OpenCylinder(0, 6, 1.75);
    // // cylinder_ptr->set_material(phong_ptr2);
    // cylinder_ptr->set_material(matte_ptr3);
    // add_object(cylinder_ptr);


    Matte* matte_ptr45 = new Matte;
    matte_ptr45->set_cd(0.2, 1, 0.4); // yellow
    matte_ptr45->set_ka(0.3);
    matte_ptr45->set_kd(0.6);
    // solid cylinder
    // the following values for bottom, top, and radius can also be the default values
    // by setting them in the SolidCylinder default constructor
    float bottom = 0.0;
    float top = 6.0;
    float radius = 1.75;
    SolidCylinder* cylinder_ptr = new SolidCylinder(bottom, top, radius);
    cylinder_ptr->set_material(matte_ptr45);
    add_object(cylinder_ptr);



    // cone

    Instance* cone_ptr = new Instance(new OpenCone(5, 2));
    cone_ptr->set_material(phong_ptr2);
    // cone_ptr->set_material(matte_ptr4);
    cone_ptr->translate(7, 0, 5);
    add_object(cone_ptr);

    // torus

    Instance* torus_ptr = new Instance(new Torus());
    torus_ptr->set_material(phong_ptr2);
    torus_ptr->rotate_x(90);
    torus_ptr->translate(-6, 6, 0);
    add_object(torus_ptr);

    // Rectangle

    Rectangle* rectangle = new Rectangle(Point3D(-6.5, 0, -5), Vector3D(17, 0, 0), Vector3D(0, 6, 0));
    // Rectangle* rectangle = new Rectangle(Point3D(-5, 0, 0), Vector3D(-3.5, 0, -11), Vector3D(2.5, 6, 6.5));
    rectangle->set_material(matte_ptr2);
    add_object(rectangle);

    // Triangle

    Instance* triangle = new Instance(new Triangle(Point3D(3, 3, 1),
                                                   Point3D(3, 0, -1),
                                                   Point3D(-1, -1, -0)));
    triangle->translate(-6, 0, -2);
    triangle->set_material(matte_ptr7);
    add_object(triangle);

    // // Instance* triangle_ptr2 = new Instance(new Triangle(Point3D(2-3, 1+3, 5), Point3D(2-3, 0.5+3, -5), Point3D(-1-3, -1+3, -4)));
    // // triangle_ptr2->rotate_y(120);
    // // triangle_ptr2->set_material(matte_ptr6);
    // // add_object(triangle_ptr2);

}

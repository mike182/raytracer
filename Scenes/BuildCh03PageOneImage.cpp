// this builds the page one image for Chapter 3: Bare Bones Ray Tracing

#include "World.hpp"
#include "MultipleObjects.hpp"
#include "Plane.hpp"
#include "Sphere.hpp"

void World::build(void) {
    vp.set_hres(400);
    vp.set_vres(400);
    vp.set_pixel_size(0.5);
    vp.num_samples = 4;

    background_color = black;
    tracer_ptr = new MultipleObjects(this);

    // colors

    RGBColor yellow(1, 1, 0);
    RGBColor brown(0.71, 0.40, 0.16);
    RGBColor dark_green(0.0, 0.41, 0.41);
    RGBColor orange(1.0, 0.75, 0.0);
    RGBColor green(0.0, 0.6, 0.3);
    RGBColor light_green(0.65, 1.0, 0.30);
    RGBColor dark_yellow(0.61, 0.61, 0.0);
    RGBColor light_purple(0.65, 0.3, 1.0);
    RGBColor dark_purple(0.5, 0.0, 1.0);

    // spheres

    Sphere * sphere_ptr1 = new Sphere(Point3D(5, 3, 0), 30);
    sphere_ptr1->set_color(yellow);
    add_object(sphere_ptr1);

    Sphere * sphere_ptr2 = new Sphere(Point3D(45, -7, -60), 20);
    sphere_ptr2->set_color(brown);
    add_object(sphere_ptr2);

    Sphere * sphere_ptr3 = new Sphere(Point3D(40, 43, -100), 17);
    sphere_ptr3->set_color(dark_green);
    add_object(sphere_ptr3);

    Sphere * sphere_ptr4 = new Sphere(Point3D(-20, 28, -15), 20);
    sphere_ptr4->set_color(orange);
    add_object(sphere_ptr4);

    Sphere * sphere_ptr5 = new Sphere(Point3D(-25, -7, -35), 27);
    sphere_ptr5->set_color(green);
    add_object(sphere_ptr5);

    Sphere * sphere_ptr6 = new Sphere(Point3D(20, -27, -35), 25);
    sphere_ptr6->set_color(light_green);
    add_object(sphere_ptr6);

    Sphere * sphere_ptr7 = new Sphere(Point3D(35, 18, -35), 22);
    sphere_ptr7->set_color(green);
    add_object(sphere_ptr7);

    Sphere * sphere_ptr8 = new Sphere(Point3D(-57, -17, -50), 15);
    sphere_ptr8->set_color(brown);
    add_object(sphere_ptr8);

    Sphere * sphere_ptr9 = new Sphere(Point3D(-47, 16, -80), 23);
    sphere_ptr9->set_color(light_green);
    add_object(sphere_ptr9);

    Sphere * sphere_ptr10 = new Sphere(Point3D(-15, -32, -60), 22);
    sphere_ptr10->set_color(dark_green);
    add_object(sphere_ptr10);

    Sphere * sphere_ptr11 = new Sphere(Point3D(-35, -37, -80), 22);
    sphere_ptr11->set_color(dark_yellow);
    add_object(sphere_ptr11);

    Sphere * sphere_ptr12 = new Sphere(Point3D(10, 43, -80), 22);
    sphere_ptr12->set_color(dark_yellow);
    add_object(sphere_ptr12);

    Sphere * sphere_ptr13 = new Sphere(Point3D(30, -7, -80), 10);
    sphere_ptr13->set_color(dark_yellow);
    add_object(sphere_ptr13);

    Sphere * sphere_ptr14 = new Sphere(Point3D(-40, 48, -110), 18);
    sphere_ptr14->set_color(dark_green);
    add_object(sphere_ptr14);

    Sphere * sphere_ptr15 = new Sphere(Point3D(-10, 53, -120), 18);
    sphere_ptr15->set_color(brown);
    add_object(sphere_ptr15);

    Sphere * sphere_ptr16 = new Sphere(Point3D(-55, -52, -100), 10);
    sphere_ptr16->set_color(light_purple);
    add_object(sphere_ptr16);

    Sphere * sphere_ptr17 = new Sphere(Point3D(5, -52, -100), 15);
    sphere_ptr17->set_color(brown);
    add_object(sphere_ptr17);

    Sphere * sphere_ptr18 = new Sphere(Point3D(-20, -57, -120), 15);
    sphere_ptr18->set_color(dark_purple);
    add_object(sphere_ptr18);

    Sphere * sphere_ptr19 = new Sphere(Point3D(55, -27, -100), 17);
    sphere_ptr19->set_color(dark_green);
    add_object(sphere_ptr19);

    Sphere * sphere_ptr20 = new Sphere(Point3D(50, -47, -120), 15);
    sphere_ptr20->set_color(brown);
    add_object(sphere_ptr20);

    Sphere * sphere_ptr21 = new Sphere(Point3D(70, -42, -150), 10);
    sphere_ptr21->set_color(light_purple);
    add_object(sphere_ptr21);

    Sphere * sphere_ptr22 = new Sphere(Point3D(5, 73, -130), 12);
    sphere_ptr22->set_color(light_purple);
    add_object(sphere_ptr22);

    Sphere * sphere_ptr23 = new Sphere(Point3D(66, 21, -130), 13);
    sphere_ptr23->set_color(dark_purple);
    add_object(sphere_ptr23);

    Sphere * sphere_ptr24 = new Sphere(Point3D(72, -12, -140), 12);
    sphere_ptr24->set_color(light_purple);
    add_object(sphere_ptr24);

    Sphere * sphere_ptr25 = new Sphere(Point3D(64, 5, -160), 11);
    sphere_ptr25->set_color(green);
    add_object(sphere_ptr25);

    Sphere * sphere_ptr26 = new Sphere(Point3D(55, 38, -160), 12);
    sphere_ptr26->set_color(light_purple);
    add_object(sphere_ptr26);

    Sphere * sphere_ptr27 = new Sphere(Point3D(-73, -2, -160), 12);
    sphere_ptr27->set_color(light_purple);
    add_object(sphere_ptr27);

    Sphere * sphere_ptr28 = new Sphere(Point3D(30, -62, -140), 15);
    sphere_ptr28->set_color(dark_purple);
    add_object(sphere_ptr28);

    Sphere * sphere_ptr29 = new Sphere(Point3D(25, 63, -140), 15);
    sphere_ptr29->set_color(dark_purple);
    add_object(sphere_ptr29);

    Sphere * sphere_ptr30 = new Sphere(Point3D(-60, 46, -140), 15);
    sphere_ptr30->set_color(dark_purple);
    add_object(sphere_ptr30);

    Sphere * sphere_ptr31 = new Sphere(Point3D(-30, 68, -130), 12);
    sphere_ptr31->set_color(light_purple);
    add_object(sphere_ptr31);

    Sphere * sphere_ptr32 = new Sphere(Point3D(58, 56, -180), 11);
    sphere_ptr32->set_color(green);
    add_object(sphere_ptr32);

    Sphere * sphere_ptr33 = new Sphere(Point3D(-63, -39, -180), 11);
    sphere_ptr33->set_color(green);
    add_object(sphere_ptr33);

    Sphere * sphere_ptr34 = new Sphere(Point3D(46, 68, -200), 10);
    sphere_ptr34->set_color(light_purple);
    add_object(sphere_ptr34);

    Sphere * sphere_ptr35 = new Sphere(Point3D(-3, -72, -130), 12);
    sphere_ptr35->set_color(light_purple);
    add_object(sphere_ptr35);
}


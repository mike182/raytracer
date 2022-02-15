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

// This builds the scene for Figure 3.18 - the single red sphere

void World::build(void) {
    vp.set_hres(200);
    vp.set_vres(200);
    vp.set_pixel_size(1.0);

    background_color = black;
    tracer_ptr = new SingleSphere(this);

    sphere.set_center(0.0);
    sphere.set_radius(85.0);
}

#include "World.hpp"
#include "Constants.h" // Utilities
#include "Lambertian.hpp" // BRDFs
#include "GlossySpecular.hpp"
#include "Orthographic.hpp" // Cameras
#include "Pinhole.hpp"
#include "Plane.hpp" // GeometricObjects
#include "Sphere.hpp"
#include "Rectangle.hpp"
#include "Grid.hpp" // Compound
#include "Triangle.hpp" // Triangles
#include "SmoothTriangle.hpp"
#include "Mesh.hpp" // Mesh
#include "FlatMeshTriangle.hpp"
#include "SmoothMeshTriangle.hpp"
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

#pragma clang diagnostic ignored "-Wwritable-strings"

// This builds the scene for Figure 23.7
// The two triangles are read from a PLY file
// The triangles can be flat or smooth shaded depending on which
// of the following two functions is called:

// Grid::grid_ptr->read_flat_triangles(file_name);
// Grid::grid_ptr->read_smooth_triangles(file_name);

void World::build(void) {
	int num_samples = 16;

	vp.set_hres(400);
	vp.set_vres(400);
	vp.set_samples(num_samples);

	tracer_ptr = new RayCast(this);

	background_color = black;

	Pinhole* pinhole_ptr = new Pinhole;
	pinhole_ptr->set_eye(100, 50, 90);
	pinhole_ptr->set_lookat(0, -0.5, 0);
	pinhole_ptr->set_view_distance(16000);
	pinhole_ptr->compute_uvw();
	set_camera(pinhole_ptr);

	Directional* directional_ptr = new Directional;
	directional_ptr->set_direction(0.75, 1, -0.15);
	directional_ptr->scale_radiance(4.5);
	directional_ptr->set_shadows(true);
	add_light(directional_ptr);

	Matte* matte_ptr1 = new Matte;
	matte_ptr1->set_ka(0.1);
	matte_ptr1->set_kd(0.75);
	matte_ptr1->set_cd(0.1, 0.5, 1.0);

	char* file_name = "../PLYFiles/TwoTriangles.ply";
	Grid* grid_ptr = new Grid(new Mesh);
	// grid_ptr->read_flat_triangles(file_name); // for Figure 23.7(a)
	grid_ptr->read_smooth_triangles(file_name); // for Figure 23.7(b)
	grid_ptr->set_material(matte_ptr1);
	grid_ptr->setup_cells();
	add_object(grid_ptr);

	Matte* matte_ptr2 = new Matte;
	matte_ptr2->set_cd(1, 0.9, 0.6);
	matte_ptr2->set_ka(0.25);
	matte_ptr2->set_kd(0.4);

	Plane* plane_ptr1 = new Plane(Point3D(0, -2.0, 0), Normal(0, 1, 0));
	plane_ptr1->set_material(matte_ptr2);
	add_object(plane_ptr1);
}

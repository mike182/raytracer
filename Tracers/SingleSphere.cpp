#include "SingleSphere.hpp"
#include "World.hpp"
#include "ShadeRec.hpp"

SingleSphere::SingleSphere(void)
  : Tracer(nullptr)
{
}

SingleSphere::SingleSphere(World* w_ptr)
  : Tracer(w_ptr)
{
}

SingleSphere::~SingleSphere()
{
}

RGBColor SingleSphere::trace_ray(const Ray& ray) const {
  ShadeRec sr(*world_ptr); // not used
  double t; // not used

  if (world_ptr->sphere.hit(ray, t, sr))
    return red;
  else
    return black;
}

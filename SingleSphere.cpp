#include "SingleSphere.hpp"
#include "World.hpp"
#include "ShadeRec.hpp"

#include "Constants.h"
#include "Tracer.hpp"

SingleSphere::SingleSphere()
  : Tracer(NULL)
{
}

SingleSphere::SingleSphere(World * worldPtr)
  : Tracer(worldPtr)
{
}

SingleSphere::~SingleSphere()
{
}

RGBColor SingleSphere::trace_ray(const Ray & ray) const {
  ShadeRec sr(*world_ptr); // not used
  double t; // not used

  if (world_ptr->sphere.hit(ray, t, sr))
    return red;
  else
    return black;
}

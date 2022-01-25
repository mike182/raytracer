#ifndef __SINGLESPHERE_HPP__
#define __SINGLESPHERE_HPP__

#include "Tracer.hpp"

class World;

class SingleSphere: public Tracer {
 public:
  SingleSphere();
  SingleSphere(World * worldPtr);
  virtual ~SingleSphere();

  virtual RGBColor trace_ray(const Ray & ray) const;
};



#endif // __SINGLESPHERE_HPP__

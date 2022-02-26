#ifndef __SMOOTHMESHTRIANGLE_HPP__
#define __SMOOTHMESHTRIANGLE_HPP__

// SmoothMeshTriangle is a MeshTriangle that uses smooth shading with
// an interpolated normal at each hit point

#include "MeshTriangle.hpp"

class SmoothMeshTriangle: public MeshTriangle {
public:
    SmoothMeshTriangle(void);
    SmoothMeshTriangle(Mesh* m_ptr, const int i0, const int i1, const int i2);
    SmoothMeshTriangle(const SmoothMeshTriangle& fmt);
    virtual SmoothMeshTriangle* clone(void) const;
    virtual ~SmoothMeshTriangle(void);

    SmoothMeshTriangle& operator=(const SmoothMeshTriangle& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;

protected:
    Normal interpolate_normal(const float beta, const float gamma) const;
};

#endif // __SMOOTHMESHTRIANGLE_HPP__

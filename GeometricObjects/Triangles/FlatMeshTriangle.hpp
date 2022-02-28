#ifndef __FLATMESHTRIANGLE_HPP__
#define __FLATMESHTRIANGLE_HPP__

// FlatMeshTriangle is a MeshTriangle that uses flat shading with a constant normal
// This uses the inherited shadow hit function from MeshTriangle

#include "MeshTriangle.hpp"

class FlatMeshTriangle: public MeshTriangle {
public:
    FlatMeshTriangle(void);
    FlatMeshTriangle(Mesh* _meshPtr, const int i0, const int i1, const int i2);
    FlatMeshTriangle(const FlatMeshTriangle& fmt);
    virtual FlatMeshTriangle* clone(void) const;
    virtual ~FlatMeshTriangle(void);

    FlatMeshTriangle& operator=(const FlatMeshTriangle& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
};

#endif // __FLATMESHTRIANGLE_HPP__

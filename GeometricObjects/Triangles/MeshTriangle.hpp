#ifndef __MESHTRIANGLE_HPP__
#define __MESHTRIANGLE_HPP__

#include "GeometricObject.hpp"
#include "Mesh.hpp"

class MeshTriangle: public GeometricObject {
public:
    MeshTriangle(void);
    MeshTriangle(Mesh* _mesh_ptr, const int i1, const int i2, const int i3);
    MeshTriangle(const MeshTriangle& mt);
    virtual MeshTriangle* clone(void) const = 0;
    virtual ~MeshTriangle(void);

    MeshTriangle& operator=(const MeshTriangle& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const = 0;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;
    // virtual bool shadow_hit(const Ray& ray, double& tmin) const;
    void compute_normal(const bool reverse_normal);
    virtual Normal get_normal(void) const;
    virtual BBox get_bounding_box(void);

protected:
    float interpolate_u(const float beta, const float gamma) const;
    float interpolate_v(const float beta, const float gamma) const;

public:
    Mesh* mesh_ptr; // stores all the data
    int index0, index1, index2; // indices into the vertices array in the mesh
    Normal normal;
    float area; // required for translucency
};

#endif // __MESHTRIANGLE_HPP__

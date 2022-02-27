#ifndef __SMOOTHTRIANGLE_HPP__
#define __SMOOTHTRIANGLE_HPP__

// This triangle has three normals which are linearly interpolated at the hit point
// for smooth shading
// Making the normals public simplifies the code in the Grid::tessellate_smooth_sphere.
// This is currently the only function that uses this class.
// The only figure that uses it is Figure 23.3

#include "GeometricObject.hpp"

class SmoothTriangle: public GeometricObject {
public:
    SmoothTriangle(void);
    SmoothTriangle(const Point3D& a, const Point3D& b, const Point3D& c);
    SmoothTriangle(const SmoothTriangle& st);
    virtual SmoothTriangle* clone(void) const;
    virtual ~SmoothTriangle(void);

    SmoothTriangle& operator=(const SmoothTriangle& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    // virtual bool shadow_hit(const Ray& ray, double& tmin) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;

    virtual BBox get_bounding_box(void);
private:
    Normal interpolate_normal(const float beta, const float gamma) const;

private:
    Point3D v0, v1, v2;
public:
    Normal n0, n1, n2; // normals at each vertex

};

#endif // __SMOOTHTRIANGLE_HPP__

#ifndef __BBOX_HPP__
#define __BBOX_HPP__

#include "Ray.hpp"
#include "Point3D.hpp"

class BBox {
public:
    BBox(void);
    BBox(const double x0, const double x1,
         const double y0, const double y1,
         const double z0, const double z1);
    BBox(const Point3D p0, const Point3D p1);
    BBox(const BBox& bbox);

    ~BBox(void);

    BBox& operator=(const BBox& rhs);

    bool hit(const Ray& ray) const;
    bool inside(const Point3D& p) const;
public:
    double x0, x1, y0, y1, z0, z1;
};

#endif // __BBOX_HPP__

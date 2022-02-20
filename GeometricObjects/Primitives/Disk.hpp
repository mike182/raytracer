#ifndef __DISK_HPP__
#define __DISK_HPP__

#include "GeometricObject.hpp"

class Disk : public GeometricObject {
public:
    Disk(void);
    Disk(const Point3D& center, const double radius, const Normal& normal);
    Disk(const Disk& plane);
    virtual Disk* clone(void) const;
    virtual ~Disk(void);

    Disk& operator=(const Disk& rhs);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;
    void set_center(const Point3D& c);
    void set_center(const double x, const double y, const double z);
    void set_radius(const double r);

private:
    Point3D center;
    double radius;
    Normal normal;

private:
    static const double kEpsilon; // shadow & secondary ray
};

inline void Disk::set_center(const Point3D& c) {
    center = c;
}

inline void Disk::set_center(const double x, const double y, const double z) {
    center.x = x;
    center.y = y;
    center.z = z;
}

inline void Disk::set_radius(const double r) {
    radius = r;
}

#endif // __DISK_HPP__

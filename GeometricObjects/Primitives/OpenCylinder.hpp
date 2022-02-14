#ifndef __OPENCYLINDER_HPP__
#define __OPENCYLINDER_HPP__

#include "GeometricObject.hpp"

class OpenCylinder: public GeometricObject {
public:
    OpenCylinder(void);
    OpenCylinder(const double bottom, const double top, const double radius);
    OpenCylinder(const OpenCylinder& c);
    virtual OpenCylinder* clone (void) const;
    virtual ~OpenCylinder(void);

    OpenCylinder& operator=(const OpenCylinder& rhs);

    virtual bool hit(const Ray& ray, double& t, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;
    void set_bottom(const double y);
    void set_top(const double y);
    void set_radius(const double r);

protected:
    double y0; // bottom
    double y1; // top
    double radius;
    double inv_radius;
private:
    static const double kEpsilon;
};

inline void OpenCylinder::set_bottom(const double y) {
    y0 = y;
}

inline void OpenCylinder::set_top(const double y) {
    y1 = y;
}

inline void OpenCylinder::set_radius(const double r) {
    radius = r;
}

#endif // __OPENCYLINDER_HPP__

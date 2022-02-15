#ifndef __OPENCONE_HPP__
#define __OPENCONE_HPP__

#include "GeometricObject.hpp"

class OpenCone: public GeometricObject {
public:
    OpenCone(void);
    OpenCone(const double height, const double radius);
    OpenCone(const OpenCone& c);
    virtual OpenCone* clone (void) const;
    virtual ~OpenCone(void);

    OpenCone& operator=(const OpenCone& rhs);

    virtual bool hit(const Ray& ray, double& t, ShadeRec& sr) const;
    virtual bool shadow_hit(const Ray& ray, float& tmin) const;
    void set_height(const double h);
    void set_radius(const double r);

protected:
    double y; // height
    double radius;
private:
    static const double kEpsilon;
};

inline void OpenCone::set_height(const double h) {
    y = h;
}

inline void OpenCone::set_radius(const double r) {
    radius = r;
}

#endif // __OPENCONE_HPP__

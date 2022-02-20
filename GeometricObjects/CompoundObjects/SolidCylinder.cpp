#include "SolidCylinder.hpp"

SolidCylinder::SolidCylinder(void)
    : Compound()
{
    objects.push_back(new OpenCylinder);
    objects.push_back(new Disk(Point3D(0.0, -1.0, 0.0), Normal(0.0, -1.0, 0.0), 1.0));
    objects.push_back(new Disk(Point3D(0.0, 1.0, 0.0), Normal(0.0, 1.0, 0.0), 1.0));
}

SolidCylinder::SolidCylinder(const float bottom, const float top, const float radius)
    : Compound()
{
    objects.push_back(new OpenCylinder(bottom, top, radius));
    objects.push_back(new Disk(Point3D(0.0, bottom, 0.0), Normal(0.0, -1.0, 0.0), radius));
    objects.push_back(new Disk(Point3D(0.0, top, 0.0), Normal(0.0, 1.0, 0.0), radius));
}

SolidCylinder::SolidCylinder(const SolidCylinder& sc)
    : Compound(sc)
{
}

SolidCylinder::~SolidCylinder(void) {
}

SolidCylinder* SolidCylinder::clone(void) const {
    return new SolidCylinder(*this);
}

SolidCylinder& SolidCylinder::operator=(const SolidCylinder& rhs) {
    if (this == &rhs)
        return *this;
    SolidCylinder::operator=(rhs);
    return *this;
}

// void SolidCylinder::set_material(Material* m) {
    // for (unsigned long i = 0; i < objects.size(); i++)
        // objects[i]->set_material(m);
// }

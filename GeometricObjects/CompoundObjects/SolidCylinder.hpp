#ifndef __SOLIDCYLINDER_HPP__
#define __SOLIDCYLINDER_HPP__

#include "Compound.hpp"
#include "OpenCylinder.hpp"
#include "Disk.hpp"

class SolidCylinder : public Compound {
public:
    SolidCylinder(void);
    SolidCylinder(const float bottom, const float top, const float radius);
    SolidCylinder(const SolidCylinder& sc);
    virtual SolidCylinder* clone(void) const;
    virtual ~SolidCylinder(void);

    SolidCylinder& operator=(const SolidCylinder& rhs);

    // void set_material(Material* m);
    // void set_wall_material(Material* m);
    // void set_bottom_material(Material* m);
    // void set_top_material(Material* m);
};

#endif // __SOLIDCYLINDER_HPP__

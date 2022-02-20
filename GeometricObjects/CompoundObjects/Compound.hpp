#ifndef __COMPOUND_HPP__
#define __COMPOUND_HPP__

#include "GeometricObject.hpp"
#include <vector>

class Compound: public GeometricObject {
public:
    Compound(void);
    Compound(const Compound& c);
    virtual Compound* clone(void) const;
    ~Compound(void);

    Compound& operator=(const Compound& c);

    virtual bool hit(const Ray& ray, double& tmin, ShadeRec& sr) const;
    virtual void set_material(Material* material_ptr);
    virtual void add_object(GeometricObject* object_ptr);
    int get_num_objects(void);

private:
    void delete_objects(void);
    void copy_objects(const std::vector<GeometricObject*>& obj_cpy);

protected:
    std::vector<GeometricObject*> objects;
};

inline int Compound::get_num_objects(void) {
    return objects.size();
}

#endif // __COMPOUND_HPP__
